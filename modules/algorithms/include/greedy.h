// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GREEDY_H_
#define MODULES_ALGORITHMS_INCLUDE_GREEDY_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>

Matching greedy(const CSR<WeightType> & graph) {
    int n = graph.n;
    Matching ans;
    std::vector<bool> isMarked(n);
    std::vector<std::pair<WeightType, std::pair<int, int>>> edge;

    for (int i = 0; i < n; i++) {
        for (int j = graph.offset[i]; j < graph.offset[i + 1]; j++) {
            auto x = std::make_pair(i, graph.edges[j]);
            edge.push_back(std::make_pair(graph.weights[j], x));
        }
    }
    std::sort(edge.begin(), edge.end());
    for (int i = edge.size() - 1; i >= 0; i--) {
        int vert_a = edge[i].second.first;
        int vert_b = edge[i].second.second;
        if (!isMarked[vert_a] && !isMarked[vert_b]) {
            isMarked[vert_a] = isMarked[vert_b] = true;
            ans.edge_b.push_back(vert_a);
            ans.edge_e.push_back(vert_b);
        }
    }
    return ans;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_GREEDY_H_
