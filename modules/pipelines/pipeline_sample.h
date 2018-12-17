// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_PIPELINE_SAMPLE_H_
#define MODULES_PIPELINES_PIPELINE_SAMPLE_H_
#include <string>
#include "./launch.h"
#include "../data_structures/include/graph.h"
#include "../data_structures/include/csr.h"
namespace Pipeline {
    int p1() {
        const std::string f = [&](const std::string& s) {
            CSR graph;
            graph.read(s);
            // Graph_coarsening
            const std::string outstr = "..\..\..\graph_data\pipeline1";
            graph.write(outstr);
            return outstr;
        };
        pipelines.push_back(f);
    }
    int p1_ = p1();
}  // namespace Pipeline
#endif  // MODULES_PIPELINES_PIPELINE_SAMPLE_H_
