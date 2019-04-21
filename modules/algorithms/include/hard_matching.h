// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_HARD_MATCHING_H_
#define MODULES_ALGORITHMS_INCLUDE_HARD_MATCHING_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
Matching hard_matching(const AL<WeightType>& graph) {
    Matching matching;
    int size = graph.n;
    std::vector <int> ed(size);
    std::vector <int> ed1(size);
    for (int i = 0; i < size; i++) {
        ed1[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ed1.begin(), ed1.end(), g);
    std::copy(ed1.begin(), ed1.end(), ed.begin());
    std::vector<int>al_id(size);
    for (int i = 0; i < size; i++) {
        al_id[i] = i + 1;
    }
    for (unsigned i = 0; i < graph.edges.size(); i++) {
        int v = ed[i];
        WeightType max_len = 0;
        int e = -1;
        if (al_id[v] > 0) {
            for (unsigned j = 0; j < graph.edges[v].size(); j++) {
                int to = graph.edges[v][j];
                WeightType len = graph.weights[v][j];
                if (len > max_len && al_id[to] > 0) {
                    max_len = len;
                    e = to;
                }
            }
            if (e != -1 && v != e) {
                al_id[v] = 0, al_id[e] = 0;
                matching.edge_b.push_back(e);
                matching.edge_e.push_back(v);
                ++matching.n;
            }
        }
    }
    return matching;
}

template <typename WeightType>
Matching hard_matching(const CSR<WeightType>& graph) {
    Matching matching;
    int size = graph.n;
    std::vector <int> ed(size);
    std::vector <int> ed1(size);
    for (int i = 0; i < size; i++) {
        ed1[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ed1.begin(), ed1.end(), g);
    std::copy(ed1.begin(), ed1.end(), ed.begin());
    std::vector<int>al_id(size);
    for (int i = 0; i < size; i++) {
        al_id[i] = i + 1;
    }
    for (int i = 0; i < size; i++) {
        int v = ed[i];
        WeightType max_len = 0;
        int e = -1;
        if (al_id[v] > 0) {
            for (int j = graph.offset[v]; j < graph.offset[v + 1]; ++j) {
                int to = graph.edges[j];
                WeightType len = graph.weights[j];
                if (len > max_len && al_id[to] > 0) {
                    max_len = len;
                    e = to;
                }
            }
            if (e != -1 && v != e) {
                al_id[v] = 0, al_id[e] = 0;
                matching.edge_b.push_back(e);
                matching.edge_e.push_back(v);
                ++matching.n;
            }
        }
    }
    return matching;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_HARD_MATCHING_H_
