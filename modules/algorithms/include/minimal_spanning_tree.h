// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_MINIMAL_SPANNING_TREE_H_
#define MODULES_ALGORITHMS_INCLUDE_MINIMAL_SPANNING_TREE_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
WeightType get_cost_of_minimal_spanning_tree(const CSR<WeightType>& graph) {
    AL <WeightType> al_graph(graph);
    std::vector <std::pair <WeightType, std::pair <int, int>>> edges;
    for (int i = 0; i < al_graph.n; ++i)
        for (unsigned j = 0; j < al_graph.edges[i].size(); ++j)
            edges.push_back({al_graph.weights[i][j],
                    {i, al_graph.edges[i][j]}});
    std::sort(begin(edges), end(edges));
    DSU dsu(graph.n);
    WeightType cost = 0;
    for (unsigned i = 0; i < edges.size(); ++i) {
        int a = edges[i].second.first,
            b = edges[i].second.second;
        WeightType w = edges[i].first;
        if (dsu.get(a) != dsu.get(b)) {
            cost += w;
            dsu.unite(a, b);
        }
    }
    return cost;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_MINIMAL_SPANNING_TREE_H_
