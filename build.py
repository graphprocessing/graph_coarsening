import os, sys, subprocess

project_directory = os.getcwd()
compiler = {"g++" : ("gcc", "g++"),
            "clang" : ("clang", "clang++")
}

os.chdir("..")
if not os.path.exists("build"):
    os.mkdir("build")
os.chdir("build")
build_directory = os.getcwd()
os.chdir(project_directory)

def lint_walk(subdirectory):
    for path, _, files in os.walk(os.path.join(project_directory, subdirectory)):
        for file in files:
            if (file.endswith(".h") or file.endswith(".cpp")):
                print("Checking: " + os.path.join(path, file))
                if not os.path.exists(os.path.join(build_directory, "lint.log")):
                    open(os.path.join(build_directory, "lint.log"), "tw").close()
                os.system("cpplint " + os.path.join(path, file) + " 2> " + os.path.join(build_directory, "lint.log"))
                verdict = ""
                ingored_errors = 0
                f = open(os.path.join(build_directory, "lint.log"), "r")
                for line in f:
                    if line.endswith("use a pointer: benchmark::State& state  [runtime/references] [2]\n"):
                        ingored_errors += 1
                    verdict = line
                f.close()
                if (verdict.startswith("Done processing")):
                    print("\033[32mSuccess: " + file + "\033[0m")
                else:
                    real_errors = int(verdict.split()[-1]) - ingored_errors
                    if real_errors == 0:
                        print("\033[32mSuccess: " + file + "\033[0m")
                    else:
                        f = open(os.path.join(build_directory, "lint.log"), "r")
                        for line in f:
                            if (line.startswith("Done processing")):
                                break
                            print(line)
                        f.close()
                        print("\033[31mFailed: "  + file + "\033[0m")
                        return_code = 1

def lint():
    return_code = 0
    if not os.path.exists(build_directory):
        os.mkdir(build_directory)
    lint_walk("modules")
    lint_walk("tests")
    lint_walk("benchmark")
    return return_code


def build(compiler_name = "g++"):
    if not os.path.exists(build_directory):
        os.mkdir(build_directory)
    os.chdir(build_directory)
    if os.name == "posix":
        subprocess.call('cmake -D CMAKE_C_COMPILER=' + compiler[compiler_name][0] + ' -D CMAKE_CXX_COMPILER=' + compiler[compiler_name][1]
        + ' CMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ' + project_directory, shell=True)
    elif os.name == "nt":
        subprocess.call('cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ' + project_directory, shell=True)
    if os.name == "posix":
        subprocess.call("cppcheck -j4 --project=compile_commands.json > log_cppcheck", shell=True)
    elif os.name == "nt":
        subprocess.call("cppcheck --project=compile_commands.json > log_cppcheck", shell=True)
    subprocess.call("python " + os.path.join(project_directory, "scripts/static_analysis.py") + " log_cppcheck", shell=True)
    if os.name == "posix":
        return_code = subprocess.call("make -j4", shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("mingw32-make")
    os.chdir(project_directory)
    return return_code

def run_main():
    if not os.path.exists(build_directory):
        return -1
    os.chdir(build_directory)
    if os.name == "posix":
        return_code = subprocess.call("./modules/application/Graph_Partition", shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("modules\\application\\Graph_Partition", shell=True)
    os.chdir(project_directory)
    return return_code

def run_tests():
    if not os.path.exists(build_directory):
        return -1
    os.chdir(build_directory)
    if os.name == "posix":
        return_code = subprocess.call("./tests/Test_Target", shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("tests\\Test_Target", shell=True)
    os.chdir(project_directory)
    return return_code

def benchmark():
    if not os.path.exists(build_directory):
        return -1
    os.chdir(build_directory)
    if os.name == "posix":
        return_code = subprocess.call("./benchmark/Benchmark_Target", shell=True)
    elif os.name == "nt":
        return_code = subprocess.call("benchmark\\Benchmark_Target", shell=True)
    os.chdir(project_directory)
    return return_code

def cmake_graph():
    if not os.path.exists(build_directory):
        return -1
    os.chdir(build_directory)
    subprocess.call("cmake --graphviz=graph_project/graph_cmake ..", shell=True)
    os.chdir(project_directory)

def help():
    print("python3 build.py lint             (check code style)")
    print("python3 build.py build <compiler> (build project)")
    print("python3 build.py run              (run main)")
    print("python3 build.py test             (run gtests)")
    print("python3 build.py benchmark        (run benchmark)")
    print("python3 build.py graph            (generate graph project)")
    print("python3 build.py all <compiler>   (check code style, build, run main and tests)")
    print("compilers: g++ (default), clang")
    print("Compler choice temporary works only on linux-like OS")

if (len(sys.argv) < 2):
    help()
elif (sys.argv[1] == "all"):
    result = {'lint' : -1,
               'build' : -1,
               'tests' : -1,
               'main' : -1}
    result['lint'] = lint()
    result['build'] = build() if len(sys.argv) == 2 else build(sys.argv[2])
    if result['build'] == 0:
        result['tests'] = run_tests()
        result['main'] = run_main()
    for stage in result:
        print("Stage " + stage + " returned exit code " + str(result[stage]))
elif (sys.argv[1] == "lint"):
    lint()
elif (sys.argv[1] == "build"):
    if len(sys.argv) == 2:
        build()
    else:
        build(sys.argv[2])
elif (sys.argv[1] == "run"):
    run_main()
elif (sys.argv[1] == "benchmark"):
    benchmark()
elif (sys.argv[1] == "test"):
    run_tests()
elif (sys.argv[1] == "graph"):
    cmake_graph()
else:
    help()
