// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#include "../../pch/include/precomp.h"

template <typename WeightType, typename MatchingFunction>
CSR<WeightType> graph_coarsening(const CSR<WeightType>& graph,
                                  MatchingFunction get_matching) {
    AL <WeightType> new_graph;
    DSU dsu(graph.n);
    AL <WeightType> new_graphs = graph;
    std::vector <int> hash(graph.n);
    for (int i = 0; i < graph.n; i++) {
        int hash_i = i;
        for (unsigned j = 0; j < new_graphs.edges[i].size(); j++) {
            int to = new_graphs.edges[i][j];
            hash_i += to;
        }
        hash[i] = hash_i;
    }
    std::vector <char> used(graph.n);
    for (int i = 0; i < graph.n; i++) {
        for (unsigned j = 0; j < new_graphs.edges[i].size(); j++) {
            int to = new_graphs.edges[i][j];
            if (hash[i] == hash[to]) {
                std::set <int> check;
                for (unsigned i1 = 0; i1 < new_graphs.edges[i].size(); i1++) {
                    int to1 = new_graphs.edges[i][i1];
                    check.insert(to1);
                }
                int size_check = static_cast<int>(check.size());
                for (unsigned i1 = 0; i1 < new_graphs.edges[to].size(); i1++) {
                    int to1 = new_graphs.edges[to][i1];
                    check.insert(to1);
                }
                if (size_check != static_cast<int>(check.size())) {
                    continue;
                } else {
                    dsu.unite(i, to);
                    used[to] = true;
                    new_graphs.weight_vertex[dsu.get(i)] =
                    new_graphs.weight_vertex[i] + new_graph.weight_vertex[to];
                }
            }
        }
    }
    std::set <std::pair<int, int>> used1;
    AL<WeightType> new_graph_1;
    new_graph_1.n = graph.n;
    new_graph_1.edges.resize(graph.n);
    new_graph_1.weights.resize(graph.n);
    new_graph_1.weight_vertex.resize(graph.n, 1);
    for (int i = 0; i < new_graphs.n; i++) {
        for (unsigned j = 0; j < new_graphs.edges[i].size(); j++) {
            int to = new_graphs.edges[i][j];
            WeightType w = new_graphs.weights[i][j];
            int a = dsu.get(i);
            int b = dsu.get(to);
            if (a != b) {
                if (used1.find(std::make_pair(a, b)) == used1.end()) {
                    used1.insert(std::make_pair(a, b));
                    new_graph_1.edges[a].push_back(b);
                    new_graph_1.weights[a].push_back(w);
                }
            }
        }
    }
    std::map <int, WeightType> m1;
    dsu = DSU(graph.n);
    Matching match = get_matching(new_graph_1);
    std::map <int, int> new_graph_weight;
    new_graph.weight_vertex.resize(graph.n, 1);
    for (int i = 0; i < match.n; i++) {
        dsu.unite(match.edge_e[i], match.edge_b[i]);
        new_graph.weight_vertex[dsu.get(match.edge_e[i])]
        = new_graph_1.weight_vertex[match.edge_e[i]] +
            new_graph_1.weight_vertex[match.edge_b[i]];
    }
    std::map <std::pair<int, int>, WeightType> new_weights;
    for (int i = 0; i < new_graph_1.n; i++) {
        for (unsigned j = 0; j < new_graph_1.edges[i].size(); j++) {
            int to = new_graph_1.edges[i][j];
            WeightType weight = new_graph_1.weights[i][j];
            int a = dsu.get(i);
            int b = dsu.get(to);
            new_weights[std::make_pair(a, b)] += weight;
        }
    }
    int new_size = graph.n;
    new_graph.edges.resize(new_size);
    new_graph.weights.resize(new_size);
    new_graph.weight_vertex.resize(new_size, 1);
    new_graph.n = new_size;
    std::set <int> a1;
    int new_size1 = 0;
    std::set <std::pair<int, int>> is_here;
    for (int i = 0; i < new_graph_1.n; i++) {
        for (unsigned j = 0; j < new_graph_1.edges[i].size(); j++) {
            int to = new_graph_1.edges[i][j];
            int a = dsu.get(i);
            int b = dsu.get(to);
            WeightType weight = new_weights[std::make_pair(a, b)];
            if (a == b) {
                continue;
            } else {
                a1.insert(a);
                a1.insert(b);
                if (is_here.find(std::make_pair(a, b)) == is_here.end()) {
                    is_here.insert(std::make_pair(a, b));
                            new_graph.edges[a].push_back(b);
                            new_graph.weights[a].push_back(weight);
                }
            }
        }
    }
    for (int i = 0; i < new_graph_1.n; i++) {
        new_graph.weight_vertex[i] =
        std::max(new_graph.weight_vertex[i], new_graph_1.weight_vertex[i]);
    }
    std::map <int, int> ng;
    int k = 0;
    for (auto it : a1) {
        ng[it] = k;
        ++k;
    }
    new_size1 = k;
    AL<WeightType> nr;
    nr.n = new_size1;
    nr.edges.resize(new_size1);
    nr.weights.resize(new_size1);
    nr.weight_vertex.resize(new_size1, 1);
    if (new_size1 > 0) {
        for (int i = 0; i < new_graph.n; i++) {
            for (unsigned j = 0; j < new_graph.edges[i].size(); j++) {
                int to = new_graph.edges[i][j];
                WeightType weight = new_graph.weights[i][j];
                nr.edges[ng[i]].push_back(ng[to]);
                nr.weights[ng[i]].push_back(weight);
            }
        }
        for (int i = 0; i < new_graph_1.n; i++) {
            nr.weight_vertex[ng[i]] = new_graph.weight_vertex[i];
        }
    }
    return nr;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
