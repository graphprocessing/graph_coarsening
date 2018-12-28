// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

int get_cost_of_minimal_spanning_tree(const CSR& graph) {
    AL al_graph(graph);
    std::vector <std::pair <int, std::pair <int, int>>> edges;
    for (int i = 0; i < al_graph.n; ++i)
        for (unsigned j = 0; j < al_graph.edges[i].size(); ++j)
            edges.push_back({al_graph.edges[i][j].second,
                    {i, al_graph.edges[i][j].first}});
    std::sort(begin(edges), end(edges));
    DSU dsu(graph.n);
    int cost = 0;
    for (unsigned i = 0; i < edges.size(); ++i) {
        int a = edges[i].second.first,
            b = edges[i].second.second,
            w = edges[i].first;
        if (dsu.get(a) != dsu.get(b)) {
            cost += w;
            dsu.unite(a, b);
        }
    }
    return cost;
}
