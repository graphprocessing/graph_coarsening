// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#include "../../pch/include/precomp.h"

#if 0
template <typename WeightType>
CSR<WeightType> graph_coarsening(const CSR<WeightType>& graph,
                                    const Matching& match) {
    CSR <WeightType> g;
    std::map <int, int> Map;
    int sz = static_cast<int>(graph.n);
    std::vector <WeightType> new_vertex(sz, 0);
    for (int i = 0; i < match.n; i++) {
        Map[match.edge_b[i]] = i;
        Map[match.edge_e[i]] = i;
        WeightType weight = 0;
        for (int j = graph.offset[match.edge_b[i]];
            j < graph.offset[match.edge_b[i] + 1]; j++) {
            if (graph.edges[j] == match.edge_e[i]) {
                weight = graph.weights[j];
                break;
            }
        }
        new_vertex[i] = weight;
    }
    int t = match.n - 1;
    std::map <int, int> Map1;
    for (int i = 0; i < graph.n; i++) {
        if (!Map.count(i)) {
            Map[i] = ++t;
            Map1[t] = i;
        }
    }
    g.offset.push_back(0);
    int cur_offset_num = 0;
    for (int i = 0; i < match.n; i++) {
        WeightType weight = new_vertex[i];
        std::set <int> used;
        int cur_vert = Map[match.edge_b[i]];
        used.insert(cur_vert);
        int p1_b = graph.offset[match.edge_b[i]];
        int p1_e = graph.offset[match.edge_b[i] + 1];
        int p2_b = graph.offset[match.edge_e[i]];
        int p2_e = graph.offset[match.edge_e[i] + 1];
        while (p1_b < p1_e) {
            int to = Map[graph.edges[p1_b]];
            if (used.find(to) == used.end()) {
                used.insert(to);
                g.edges.push_back(to);
                cur_offset_num++;
                WeightType weight1 = 0;
                if (to < match.n) {
                    for (int j = p1_b, k = 0;
                                    (j < p1_e) && (k < 2); j++) {
                        if (match.edge_b[to] == graph.edges[j]) {
                            weight1 += graph.weights[j];
                            k++;
                        }
                        if (match.edge_e[to] == graph.edges[j]) {
                            weight1 += graph.weights[j];
                            k++;
                        }
                    }
                    for (int j = p2_b, k = 0;
                                    (j < p2_e) && (k < 2); j++) {
                        if (match.edge_b[to] == graph.edges[j]) {
                            weight1 += graph.weights[j];
                            k++;
                        }
                        if (match.edge_e[to] == graph.edges[j]) {
                            weight1 += graph.weights[j];
                            k++;
                        }
                    }
                } else {
                    weight1 = graph.weights[p1_b];
                }
                g.weights.push_back(weight + weight1 +
                                            new_vertex[to]);
            }
            p1_b++;
        }
        while (p2_b < p2_e) {
            int to = Map[graph.edges[p2_b]];
            if (used.find(to) == used.end()) {
                used.insert(to);
                g.edges.push_back(to);
                cur_offset_num++;
                WeightType weight1 = 0;
                if (to < match.n) {
                    for (int j = p2_b, k = 0;
                                    (j < p2_e) && (k < 2); j++) {
                        if (match.edge_b[to] == graph.edges[j]) {
                            weight1 += graph.weights[j];
                            k++;
                        }
                        if (match.edge_e[to] == graph.edges[j]) {
                            weight1 += graph.weights[j];
                            k++;
                        }
                    }
                } else {
                    weight1 = graph.weights[p2_b];
                }
                g.weights.push_back(weight + weight1 +
                                            new_vertex[to]);
            }
            p2_b++;
        }
        g.offset.push_back(cur_offset_num);
    }
    for (int i = match.n; i <= t; i++) {
        int p_b = graph.offset[Map1[i]];
        int p_e = graph.offset[Map1[i] + 1];
        std::set <int> used;
        for (int j = p_b; j < p_e; j++) {
            int to = Map[graph.edges[j]];
            if (used.find(to) == used.end()) {
                used.insert(to);
                g.edges.push_back(to);
                cur_offset_num++;
                WeightType weight1 = 0;
                if (to < match.n) {
                    for (int j1 = j, k = 0;
                                    (j1 < p_e) && (k < 2); j1++) {
                        if (match.edge_b[to] == graph.edges[j1]) {
                            weight1 += graph.weights[j1];
                            k++;
                        }
                        if (match.edge_e[to] == graph.edges[j1]) {
                            weight1 += graph.weights[j1];
                            k++;
                        }
                    }
                } else {
                    weight1 = graph.weights[j];
                }
                g.weights.push_back(weight1 + new_vertex[to]);
            }
        }
        g.offset.push_back(cur_offset_num);
    }
    g.n = t + 1;
    return g;
}
#endif

#if 0
template <typename WeightType, typename MatchingFunction>
CSR<WeightType> graph_coarsening(const CSR<WeightType>& graph,
                                  MatchingFunction get_matching) {
    AL <WeightType> new_graph;
    std::vector <int> parent(graph.n);
    std::vector <int> rank(graph.n);
    auto make_set = [&] (int v) {
        parent[v] = v;
        rank[v] = 0;
    };
    std::function<int(int)> finds_set = [&] (int v) {
        if (v == parent[v])
            return v;
        return parent[v] = finds_set (parent[v]);
    };
    auto union_set = [&] (int a, int b) {
        a = finds_set(a);
        b = finds_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                std::swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) {
                ++rank[a];
            }
        }
    };
    AL<WeightType> new_graphs = graph;
    for (int i = 0; i < graph.n; i++) {
        make_set(i);
    }
    std::vector <char> used(graph.n, false);
    std::vector <int> hash(graph.n);
    std::map <int, WeightType> new_weights;
    for (int i = 0; i < new_graphs.n; i++) {
        int hash_i = 0;
        for (int j = 0; j < new_graphs.edges[i].size(); j++) {
            int to = new_graphs.edges[i][j];
            hash_i += to;
        }
        hash[i] = hash_i;
    }
    for (int i = 0; i < graph.n; i++) {
        for (int j = 0; j < new_graphs.n; j++) {
            if (i == j) {
                continue;
            } else {
                if (hash[i] == hash[j]) {
                    std::set <int> r;
                    WeightType weight = 0;
                    for (int i1 = 0; i1 < new_graphs.edges[i].size();
                         i1++) {
                        int to = new_graphs.edges[i][i1];
                        weight = std::max(weight, new_graphs.weights[i][i1]);
                        r.insert(to);
                    }
                    int size = r.size();
                    for (int i1 = 0; i1 < new_graphs.edges[j].size();
                         i1++) {
                        int to = new_graphs.edges[j][i1];
                        weight = std::max(weight, new_graphs.weights[i][i1]);
                        r.insert(to);
                    }
                    if (size == r.size()) {
                        union_set(i, j);
                        new_weights[finds_set(i)] += weight;
                    }
                }
            }
        }
    }
    std::set <std::pair<int, int>> used1;
    AL<WeightType> new_graph_1;
    new_graph_1.n = graph.n;
    new_graph_1.edges.resize(graph.n);
    new_graph_1.weights.resize(graph.n);
    for (int i = 0; i < new_graphs.n; i++) {
        for (int j = 0; j < new_graphs.edges[i].size(); j++) {
            int to = new_graphs.edges[i][j];
            WeightType w = new_graphs.weights[i][j];
            int a = finds_set(i);
            int b = finds_set(to);
            if (a != b) {
                if (used1.find(std::make_pair(a, b)) == used1.end()) {
                    used1.insert(std::make_pair(a, b));
                    new_graph_1.edges[a].push_back(b);
                    new_graph_1.weights[a].push_back(w + new_weights[a]
                                                     + new_weights[b]);
                }
            }
        }
    }
    for (int i = 0; i < graph.n; i++) {
        parent[i] = 0;
    }
    for (int i = 0; i < graph.n; i++) {
        rank[i] = 0;
    }
    std::map <int, WeightType> m1;
    for (int i = 0; i < graph.n; i++) {
        make_set(i);
    }
    Matching match = get_matching(new_graph_1);
    for (int i = 0; i < match.n; i++) {
        union_set(match.edge_e[i], match.edge_b[i]);
    }
    int new_size = graph.n;
    new_graph.edges.resize(new_size);
    new_graph.weights.resize(new_size);
    new_graph.n = new_size;
    std::set <int> a1;
    int new_size1 = 0;
    for (int i = 0; i < new_graph_1.n; i++) {
        for (int j = 0; j < new_graph_1.edges[i].size(); j++) {
            int to = new_graph_1.edges[i][j];
            WeightType weight = new_graph_1.weights[i][j];
            int a = finds_set(i);
            int b = finds_set(to);
            if (a == b) {
                continue;
            } else {
                a1.insert(a);
                a1.insert(b);
                new_graph.edges[a].push_back(b);
                new_graph.weights[a].push_back(weight);
            }
        }
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
    for (int i = 0; i < new_graph.n; i++) {
        for (int j = 0; j < new_graph.edges[i].size(); j++) {
            int to = new_graph.edges[i][j];
            WeightType weight = new_graph.weights[i][j];
            nr.edges[ng[i]].push_back(ng[to]);
            nr.weights[ng[i]].push_back(weight);
        }
    }
    return nr;
}

#endif
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
    int new_size = graph.n;
    new_graph.edges.resize(new_size);
    new_graph.weights.resize(new_size);
    new_graph.weight_vertex.resize(new_size, 1);
    new_graph.n = new_size;
    std::set <int> a1;
    int new_size1 = 0;
    for (int i = 0; i < new_graph_1.n; i++) {
        for (unsigned j = 0; j < new_graph_1.edges[i].size(); j++) {
            int to = new_graph_1.edges[i][j];
            WeightType weight = new_graph_1.weights[i][j];
            int a = dsu.get(i);
            int b = dsu.get(to);
            if (a == b) {
                continue;
            } else {
                a1.insert(a);
                a1.insert(b);
                new_graph.edges[a].push_back(b);
                new_graph.weights[a].push_back(weight);
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
    return nr;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_

