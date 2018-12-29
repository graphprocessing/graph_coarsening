// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_PREPARE_H_
#define MODULES_PIPELINES_PREPARE_H_
#include "../pch/include/precomp.h"

namespace Pipeline {
    std::vector <std::string> graph_files;
    void prepare() {
        CSR<double> graph = washington_test<double>(2);
        graph_files.push_back("../graph_data/sample_washington_test.bin");
        graph.write(graph_files.back());
    }
}  // namespace Pipeline

#endif  // MODULES_PIPELINES_PREPARE_H_
