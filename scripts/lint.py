import os, subprocess, re, sys

######################################################################
print("################ START FOUND LINT ERROR ################")
def StartTests(command):
    proc = subprocess.Popen(command, shell=True, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    out = proc.stdout.read()
    out_err = proc.stderr.read()
    print(out_err)
    proc.wait()

    pattern = 'Total errors found: 0';
    res_succ = re.findall(pattern, out)

    pattern_bad = 'Total errors found: (\d*)';
    res_bad = re.findall(pattern_bad, out)

    res_count_bad = 0
    for value in res_bad:
        res_count_bad = res_count_bad + int(value)

    pattern_non_const = 'Is this a non-const reference\? If so, make const or use a pointer: benchmark::State& state';
    list_non_const = re.findall(pattern_non_const, out_err)

    if len(res_succ) != 0: return True
    else:
        if res_count_bad == len(list_non_const): return True
        else:                                    return False

pattern_filename = r'(\w+\.h|\w+\.cpp)$'

project_directory = sys.argv[1]
home_directory = sys.argv[1]

cpplint_path = project_directory + '/3rdparty/cpplint.py'
cpplint_path = os.path.abspath(cpplint_path)
project_directory = os.path.abspath(project_directory)
exit_flag = True
for dirs, node, files in os.walk(project_directory):
    for file in files:
        if re.search(pattern_filename, file) != None:
            if re.search(r'/build/|/3rdparty/', dirs) == None:
                os.chdir(dirs)
                print(dirs + " -> " + file)
                command = sys.executable + ' ' + cpplint_path + ' ' + file
                status = StartTests(command)
                if status:
                    print("\033[0;32mSuccess: " + file + "\033[0;0m");
                else:
                    print("\033[0;31mFailed: "  + file + "\033[0;0m");
                    exit_flag = False
os.chdir(home_directory)
print("################ END FOUND LINT ERROR   ################")
if exit_flag: exit(0)
else: exit(1)
######################################################################
