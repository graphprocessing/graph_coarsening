if [ "$1" == "lint" ]; then
    python scripts/lint.py ${PWD}
fi

if [ "$1" == "build" ]; then
    if [ ! -d "build" ]; then
        mkdir build
    fi

    cd build
    cmake -D CMAKE_BUILD_TYPE=Release \
          -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
    cppcheck -j4 --project=compile_commands.json &> log_cppcheck
    python ../scripts/static_analysis.py log_cppcheck
    make -j4
    cd ..
fi

if [ "$1" == "run" ]; then
    cd build
    ./modules/application/Graph_Partition
    cd ..
fi

if [ "$1" == "test" ]; then
    cd build
    ./tests/Test_Target
    cd ..
fi

if [ "$1" == "graph" ]; then
    cd build
    if [ ! -d "graph_project" ]; then
        mkdir graph_project
    fi
    cmake --graphviz=graph_project/graph_cmake ..
    cd ..
fi

if [ "$1" != "lint" -a  "$1" != "build" -a "$1" != "run" -a "$1" != "test" -a \
     "$1" != "graph" ]; then
    echo "source build.sh lint  (check code style)"
    echo "source build.sh build (build project)"
    echo "source build.sh run   (run main)"
    echo "source build.sh test  (run gtests)"
    echo "source build.sh graph (generate graph project)"
fi
