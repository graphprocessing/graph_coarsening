// Copyright [year] <Copyright Owner>
#ifndef MODULES_COMMON_INCLUDE_IMPORT_H_
#define MODULES_COMMON_INCLUDE_IMPORT_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
AL <WeightType> convert_to_undirected_graph(const AL <WeightType>& graph) {
    try {
        AL <WeightType> out(graph);
        for (int i = 0; i < out.n; ++i) {
            for (unsigned j = 0; j < out.edges[i].size(); ++j) {
                int to = out.edges[i][j];
                auto search = std::find(out.edges[to].begin(),
                                        out.edges[to].end(), i);
                if (search == out.edges[to].end()) {
                    out.edges[to].push_back(i);
                    out.weights[to].push_back(out.weights[i][j]);
                }
            }
        }
        return out;
    }
    catch (std::bad_alloc& ba) {
        std::cerr << ba.what() << std::endl;
        return graph;
    }
}

#endif  // MODULES_COMMON_INCLUDE_IMPORT_H_
