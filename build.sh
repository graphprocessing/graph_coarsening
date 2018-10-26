if [ ! -d "build" ]; then
    mkdir build
fi

cd build
cmake ..
make -j4
./modules/application/Graph_Partition
cd ..

