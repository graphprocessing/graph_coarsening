// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_PIPELINE_SAMPLE_H_
#define MODULES_PIPELINES_PIPELINE_SAMPLE_H_
#include "../pch/include/precomp.h"
#include "./pipeline_management.h"

namespace Pipeline {
    int p1() {
        auto f = [&](const std::string& s) -> std::string {
            CSR<double> graph;
            graph.read(s);
            // Graph_coarsening
            std::string outstr = "../graph_data/pipeline_sample.bin";
            graph.write(outstr);
            return outstr;
        };
        pipelines.push_back(f);
        pipeline_names.push_back("pipeline_sample");
        return 0;
    }
    int p1_ = p1();
}  // namespace Pipeline
#endif  // MODULES_PIPELINES_PIPELINE_SAMPLE_H_
