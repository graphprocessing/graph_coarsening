// Copyright [year] <Copyright Owner>
#include "modules/pch/include/precomp.h"
#include "modules/pipelines/pipeline_management.h"

int main(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        CSR <int> graph;
        std::cout << "Reading " << argv[i] << std::endl;
        graph.read(argv[i]);
        Pipeline::launch(argv[i]);
    }
    return 0;
}
