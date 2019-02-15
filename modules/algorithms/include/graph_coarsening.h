// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
CSR<WeightType> graph_coarsening(const CSR<WeightType>& graph,
                                    const Matching& match) {
    CSR <WeightType> g;
    std::map <int, int> Map;
    int sz = static_cast<int>(graph.n);
    std::vector <int> new_vertex(sz, 0);
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
                    weight1 = graph.weights[p1_b];
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

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
