// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_MAX_WEIGHT_MATCHING_H_
#define MODULES_ALGORITHMS_INCLUDE_MAX_WEIGHT_MATCHING_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
Matching max_weight_matching(const AL<WeightType> &graph) {
    std::vector <Matching> m;
    std::vector <int> w;
    std::set <std::pair <int, int>> was;
    m.emplace_back(Matching());
    w.emplace_back(0);
    int cnt = 1;
    for (int i = 0; i < graph.n; ++i) {
        if (graph.edges[i].size() == 1 || i + 1 == graph.n) {
            std::vector <int> was(graph.n);
            int v = i;
            was[v] = true;
            for (unsigned j = 0; j < graph.edges[v].size(); ++j) {
                if (!was[graph.edges[v][j]]) {
                    was[graph.edges[v][j]] = 1;
                    Matching mat;
                    mat.edge_b.push_back(i);
                    mat.edge_e.push_back(graph.edges[v][j]);
                    ++mat.n;
                    m.push_back(mat);
                    w.emplace_back(graph.weights[v][j]);
                    v = graph.edges[v][j];
                    ++cnt;
                    break;
                }
            }
            bool is_done = false;
            while (true) {
                if (is_done) break;
                is_done = true;
                for (unsigned j = 0; j < graph.edges[v].size(); ++j) {
                    if (!was[graph.edges[v][j]]) {
                        was[graph.edges[v][j]] = 1;
                        if (graph.weights[v][j] + w[cnt - 2] > w[cnt - 1]) {
                            w.emplace_back(graph.weights[v][j] + w[cnt - 2]);
                            Matching mat = m[cnt - 2];
                            mat.edge_b.push_back(v);
                            mat.edge_e.push_back(graph.edges[v][j]);
                            ++mat.n;
                            m.push_back(mat);
                        } else {
                            w.push_back(w[cnt - 1]);
                            m.push_back(m[cnt - 1]);
                        }
                        v = graph.edges[v][j];
                        ++cnt;
                        is_done = false;
                        break;
                    }
                }
            }
            break;
        }
    }
    return m.back();
}

#endif  // MODULES_ALGORITHMS_INCLUDE_MAX_WEIGHT_MATCHING_H_
