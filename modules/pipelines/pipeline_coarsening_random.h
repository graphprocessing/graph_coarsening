// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_PIPELINE_COARSENING_RANDOM_H_
#define MODULES_PIPELINES_PIPELINE_COARSENING_RANDOM_H_
#include "../pch/include/precomp.h"
#include "./pipeline_management.h"

namespace Pipeline {
    int p2() {
        auto f = [&](const std::string& s) -> std::string {
            CSR<double> graph;
            graph.read(s);
            for (int i = 0; i < 10; ++i)
                graph = graph_coarsening(graph, random_matching(graph));
            std::string outstr = "../graph_data/"
                            "pipeline_coarsening_random.bin";
            graph.write(outstr);
            return outstr;
        };
        pipelines.push_back(f);
        pipeline_names.push_back("pipeline_coarsening_random");
        return 0;
    }
    int p2_ = p2();
}  // namespace Pipeline
#endif  // MODULES_PIPELINES_PIPELINE_COARSENING_RANDOM_H_
