from __future__ import print_function
import os, sys, subprocess, multiprocessing

project_directory = os.getcwd()
data_directory = None
compiler = {
    "g++" : ("gcc", "g++"),
    "clang" : ("clang", "clang++"),
    "msvc" : ("msvc", "msvc"),
    "icc" : ("icc", "icpc")
}
build_directories = dict()

def create_folders():
    global data_directory, build_directoriess
    os.chdir("..")
    for x in compiler.keys():
        build_directories[x] = os.path.join(os.getcwd(), "build_" + x)
    if not os.path.exists("graph_data"):
        os.mkdir("graph_data")
    os.chdir("graph_data")
    data_directory = os.getcwd()
    os.chdir(project_directory)
    return 0

def lint_walk(subdirectory):
    return_code = 0
    for path, _, files in os.walk(os.path.join(project_directory, subdirectory)):
        for file in files:
            if (file.endswith(".h") or file.endswith(".cpp")):
                print("Checking: " + os.path.join(path, file))
                if not os.path.exists(os.path.join(data_directory, "lint.log")):
                    open(os.path.join(data_directory, "lint.log"), "w").close()
                if os.name == "posix":
                    os.system("cpplint " + os.path.join(path, file) + " 2> " + os.path.join(data_directory, "lint.log") + " 1> /dev/null")
                elif os.name == "nt":
                    os.system("cpplint " + os.path.join(path, file) + " 2> " + os.path.join(data_directory, "lint.log") + " 1> NUL")
                f = open(os.path.join(data_directory, "lint.log"), "r")
                real_errors = 0
                for line in f:
                    if (not line.endswith("benchmark::State& state  [runtime/references] [2]\n") and
                        not line.endswith("[build/include_what_you_use] [4]\n")):
                        real_errors += 1
                f.close()
                if real_errors == 0:
                    print("\033[32mSuccess: " + file + "\033[0m")
                else:
                    f = open(os.path.join(data_directory, "lint.log"), "r")
                    for line in f:
                        if (not line.endswith("benchmark::State& state  [runtime/references] [2]\n") and
                            not line.endswith("[build/include_what_you_use] [4]\n")):
                            print(line, end='')
                    f.close()
                    print("\033[31mFailed: "  + file + "\033[0m")
                    return_code = 1
    return return_code

def lint():
    return_code = 0
    return_code += lint_walk("modules")
    return_code += lint_walk("tests")
    return_code += lint_walk("benchmark")
    return_code += lint_walk("samples")
    return return_code

def build():
    if ((os.name == "posix" and compiler_name == "msvc") or
        (os.name == "nt" and compiler_name == "clang")):
        print("This compiler is not supported by script on this OS")
        exit(1)
    return_code = 0
    subprocess.call('git submodule update --init --recursive', shell=True)
    if not os.path.exists(build_directories[compiler_name]):
        os.mkdir(build_directories[compiler_name])
    os.chdir(build_directories[compiler_name])
    if os.name == "posix":
        subprocess.call('cmake -D CMAKE_C_COMPILER=' + compiler[compiler_name][0] + ' -D CMAKE_CXX_COMPILER=' + compiler[compiler_name][1]
        + ' -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ' + project_directory, shell=True)
    elif os.name == "nt":
        if compiler_name == "msvc":
            subprocess.call('cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ' + project_directory, shell=True)
        elif compiler_name == "g++":
            subprocess.call('cmake -G "MinGW Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ' + project_directory, shell=True)
        elif compiler_name == "icc":
            subprocess.call('cmake -D CMAKE_C_COMPILER=icl -D CMAKE_CXX_COMPILER=icl'
        + ' -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ' + project_directory, shell=True)
    if os.name == "posix":
        subprocess.call("cppcheck -j" + str(multiprocessing.cpu_count()) + " --project=compile_commands.json > log_cppcheck", shell=True)
    elif os.name == "nt":
        subprocess.call("cppcheck --project=compile_commands.json > log_cppcheck", shell=True)
    subprocess.call("python " + os.path.join(project_directory, "scripts/static_analysis.py") + " log_cppcheck", shell=True)
    if os.name == "posix":
        return_code = subprocess.call("cmake --build . --config Release -- -j" + str(multiprocessing.cpu_count()), shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("cmake --build . --config Release ", shell=True)
    os.chdir(project_directory)
    return return_code

def run_example(example_name = "main", args = []):
    if not os.path.exists(build_directories[compiler_name]):
        return -1
    if os.name == "posix":
        command = os.path.join(build_directories[compiler_name], "./bin/example_" + example_name)
    elif os.name == "nt":
        command = os.path.join(build_directories[compiler_name], "bin\\example_" + example_name + ".exe")
    for arg in args:
        command += " " + arg
    print(command)
    return_code = subprocess.call(command, shell=True)
    return return_code

def run_tests():
    if not os.path.exists(build_directories[compiler_name]):
        return -1
    os.chdir(build_directories[compiler_name])
    if os.name == "posix":
        return_code = subprocess.call("./bin/test_target", shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("bin\\test_target.exe", shell=True)
    if (os.path.isfile("test.bin")):
        os.remove("test.bin")
    if (os.path.isfile("test.txt")):
        os.remove("test.txt")
    os.chdir(project_directory)
    return return_code

def benchmark():
    if not os.path.exists(build_directories[compiler_name]):
        return -1
    os.chdir(build_directories[compiler_name])
    if os.name == "posix":
        return_code = subprocess.call("./bin/benchmark_target", shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("bin\\benchmark_target.exe", shell=True)
    os.chdir(project_directory)
    return return_code

def asymp(args):
    if not os.path.exists(os.path.join(build_directories[compiler_name], "asymp.log")):
        run_example(os.path.join(build_directories[compiler_name], "asymp.log"))
    if os.name == "posix":
        script_call_command = ("python3 " + os.path.join(project_directory, "scripts/asymptotics.py")+
                            " " + os.path.join(build_directories[compiler_name], "asymp.log"))
    elif os.name == "nt":
        script_call_command = ("python " + os.path.join(project_directory, "scripts/asymptotics.py")+
                            " " + os.path.join(build_directories[compiler_name], "asymp.log"))
    for arg in args:
        script_call_command += " " + arg
    return_code = subprocess.call(script_call_command, shell=True)
    return return_code

def cmake_graph():
    if not os.path.exists(build_directories[compiler_name]):
        return -1
    os.chdir(build_directories[compiler_name])
    return_code = subprocess.call("cmake --graphviz=graph_project/graph_cmake " + build_directories[compiler_name], shell=True)
    os.chdir(project_directory)
    return return_code

def run_pipelines(args):
    return run_example("pipelines", args)

def visualize(data_file = None):
    if os.name == "posix":
        return_code = subprocess.call("python3 scripts/graph_visualization.py " + data_file, shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("python scripts/graph_visualization.py " + data_file, shell=True)
    return return_code

def help():
    print("python3 build.py lint <compiler>                 (check code style)")
    print("python3 build.py build <compiler>                (build project)")
    print("python3 build.py run <compiler> <example> <args> (run example)")
    print("python3 build.py test <compiler>                 (run gtests)")
    print("python3 build.py benchmark <compiler>            (run benchmark)")
    print("python3 build.py graph <compiler>                (generate graph project)")
    print("python3 build.py all <compiler>                  (check code style, build, run main and tests)")
    print("python3 build.py asymp <compiler> <args>         (make asymptotics figures)")
    print("python3 build.py pipelines <compiler> <args>     (run pipelines)")
    print("python3 build.py visualize <file_path>           (create graph visualization)")
    print("compilers: g++ (default), clang (Linux, macOS), msvc (Windows)")
    print("Compler choice temporary works only on linux-like OS")
    print("Use python instead of python3 on Windows")
    exit(0)

if __name__ == "__main__":
    try:
        create_folders()
    except Exception:
        print("Folders can't be created")
        exit(1)
    global compiler_name
    compiler_name = sys.argv[2] if len(sys.argv) > 2 else "g++"
    if len(sys.argv) < 2:
        help()
    elif (sys.argv[1] == "all"):
        result = {'lint' : -1,
                'build' : -1,
                'tests' : -1,
                'benchmark' : -1,
                'main' : -1}
        result['lint'] = lint()
        result['build'] = build()
        if result['build'] == 0:
            result['benchmark'] = benchmark()
            result['tests'] = run_tests()
            result['main'] = run_example()
        return_code = 0
        for stage in result:
            if result[stage] != 0:
                return_code = 1
            print("Stage " + stage + " returned exit code " + str(result[stage]))
    elif (sys.argv[1] == "lint"):
        return_code = lint()
    elif (sys.argv[1] == "build"):
        return_code = build()
    elif (sys.argv[1] == "run"):
        if len(sys.argv) > 3:
            additional_args = []
            for i in range(4, len(sys.argv)):
                additional_args.append(sys.argv[i])
            return_code = run_example(sys.argv[3], additional_args)
        else:
            return_code = run_example()
    elif (sys.argv[1] == "benchmark"):
        return_code = benchmark()
    elif (sys.argv[1] == "test"):
        return_code = run_tests()
    elif (sys.argv[1] == "pipelines"):
        additional_args = []
        for i in range(3, len(sys.argv)):
            additional_args.append(sys.argv[i])
        return_code = run_pipelines(additional_args)
    elif (sys.argv[1] == "asymp"):
        additional_args = []
        for i in range(3, len(sys.argv)):
            additional_args.append(sys.argv[i])
        return_code = asymp(additional_args)
    elif (sys.argv[1] == "graph"):
        return_code = cmake_graph()
    elif (sys.argv[1] == "visualize"):
        if len(sys.argv) > 2:
            return_code = visualize(sys.argv[2])
        else:
            return_code = 1
    else:
        help()
    print("Stage " + sys.argv[1] + " returned exit code " + str(return_code))
    exit(return_code)
