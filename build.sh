current_path=${PWD}
if [ "$1" == "lint" ]; then
    python scripts/lint.py ${current_path}
fi

cd ..
build_path="${PWD}/build_graph_partition"
cd ${current_path}
if [ "$1" == "build" ]; then
    if [ ! -d "${build_path}" ]; then
        mkdir ${build_path}
    fi

    cd ${build_path}
    cmake -W no-dev -D CMAKE_EXPORT_COMPILE_COMMANDS=ON ${current_path}
    cppcheck -j4 --project=compile_commands.json &> log_cppcheck
    python ${current_path}/scripts/static_analysis.py log_cppcheck
    make -j4
    cd ${current_path}
fi

if [ "$1" == "run" ]; then
    cd ${build_path}
    ./modules/application/Graph_Partition
    cd ${current_path}
fi

if [ "$1" == "test" ]; then
    cd ${build_path}
    ./tests/Test_Target
    cd ${current_path}
fi

if [ "$1" == "benchmark" ]; then
    cd ${build_path}
    ./benchmark/Benchmark_Target
    cd ${current_path}
fi

if [ "$1" == "graph" ]; then
    cd ${build_path}
    if [ ! -d "graph_project" ]; then
        mkdir graph_project
    fi
    cmake --graphviz=graph_project/graph_cmake ..
    cd ${current_path}
fi

if [ "$1" == "all" ]; then
    source build.sh lint
    source build.sh build
    source build.sh test
    source build.sh benchmark
    source build.sh run
fi

if [ "$1" != "lint" -a  "$1" != "build" -a "$1" != "run" -a "$1" != "test" -a \
     "$1" != "graph" -a "$1" != "all" -a "$1" != "benchmark" ]; then
    echo "source build.sh lint      (check code style)"
    echo "source build.sh build     (build project)"
    echo "source build.sh run       (run main)"
    echo "source build.sh test      (run gtests)"
    echo "source build.sh benchmark (run benchmark tests)"
    echo "source build.sh graph     (generate graph project)"
    echo "source build.sh all       (check code style, build, run main and tests)"
fi
