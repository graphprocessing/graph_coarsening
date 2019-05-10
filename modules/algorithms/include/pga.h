// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_PGA_H_
#define MODULES_ALGORITHMS_INCLUDE_PGA_H_
#include "../../pch/include/precomp.h"

template <typename WeightType, typename MatchingFunction>
Matching PGA(const CSR<WeightType> &graph, MatchingFunction match) {
    Matching result;
    int size = graph.n;
    std::vector <int> ed(size);
    std::vector <int> ed1(size);
    std::vector <char> used1(size, false);
    std::set <std::pair<int, int>> used;
    for (int i = 0; i < size; i++) {
        ed1[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ed1.begin(), ed1.end(), g);
    std::copy(ed1.begin(), ed1.end(), ed.begin());
    auto deg = [&](int k) {
        int deg_ans = 0;
        for (int i = graph.offset[k]; i < graph.offset[k + 1]; i++) {
            if (used.find(std::make_pair(k, graph.edges[i]))
                == used.end()) {
                deg_ans++;
            }
        }
        if (deg_ans > 0) {
            return true;
        } else {
            return false;
        }
    };
    auto is_edge = [&]() {
        int edge_ans = 0;
        for (int i = 0; i < graph.n; i++) {
            for (int j = graph.offset[i]; j < graph.offset[i + 1]; j++) {
                if (used.find(std::make_pair(i, graph.edges[i]))
                    == used.end()) {
                    edge_ans++;
                }
            }
        }
        return edge_ans;
    };
    while (is_edge() != 0) {
        AL <WeightType> P;
        P.n = size;
        P.edges.resize(size);
        P.weights.resize(size);
        P.weight_vertex.resize(size);
        int v = -1;
        for (unsigned i = 0; i < ed.size(); i++) {
            if (deg(ed[i]) && !used1[ed[i]]) {
                v = ed[i];
                break;
            }
        }
        if (v == -1) break;
        while (deg(v)) {
            if (used1[v]) break;
            int e = -1;
            WeightType weight = -1;
            for (int i = graph.offset[v]; i < graph.offset[v + 1]; i++) {
                if (graph.weights[i] > weight &&
                used.find(std::make_pair(v, graph.edges[i])) == used.end() &&
                !used1[graph.edges[i]]) {
                    e = graph.edges[i];
                    weight = graph.weights[i];
                }
            }
            used1[v] = true;
            for (int i = graph.offset[v]; i < graph.offset[v + 1]; i++) {
                used.insert(std::make_pair(v, graph.edges[i]));
            }
            if (e == -1) break;
            P.edges[v].push_back(e);
            P.weights[v].push_back(weight);
            v = e;
        }
        Matching result_new = match(P);
        for (int i = 0; i < result_new.n; i++) {
            used1[result_new.edge_b[i]] = true;
            used1[result_new.edge_e[i]] = true;
            result.edge_b.push_back(result_new.edge_b[i]);
            result.edge_e.push_back(result_new.edge_e[i]);
        }
        result.n += result_new.n;
    }
    return result;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_PGA_H_
