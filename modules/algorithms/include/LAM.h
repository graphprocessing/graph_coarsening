// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_LAM_H_
#define MODULES_ALGORITHMS_INCLUDE_LAM_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>

Matching LAM(const CSR<WeightType> & graph) {
    int n = graph.n;
    Matching ans;
    std::vector<std::pair<int, int>> edge;
    std::set<int> u;
    std::vector<WeightType> w;
    std::vector<bool> isFree(n);
    for (int i = 0; i < n; i++) {
        for (int j = graph.offset[i]; j < graph.offset[i + 1]; j++) {
            edge.push_back(std::make_pair(i, graph.edges[j]));
            u.insert(j);
            w.push_back(graph.weights[j]);
        }
        isFree[i] = true;
    }

    std::function<void(int)>
    try_match = [&](int k) {
        std::set<int> ca, cb;
        if (isFree[edge[k].first] && isFree[edge[k].second]) {
            int start_edge = graph.offset[edge[k].first];
            int end_edge = graph.offset[edge[k].first + 1];
            for (int i = start_edge; i < end_edge; i++) {
                if (u.find(i) == u.end()) continue;
                ca.insert(i);
                if (w[i] > w[k]) {
                    try_match(i);
                }
            }
            start_edge = graph.offset[edge[k].second];
            end_edge = graph.offset[edge[k].second + 1];
            for (int i = start_edge; i < end_edge; i++) {
                if (u.find (i) == u.end()) continue;
                cb.insert(i);
                if (w[i] > w[k]) {
                    try_match(i);
                }
            }
        }
        if (!isFree[edge[k].first] && !isFree[edge[k].second]) {
            for (int x : ca) u.erase(x);
            for (int x : cb) u.erase(x);
            u.erase(k);
            return;
        }

        if (!isFree[edge[k].first] && isFree[edge[k].second]) {
            for (int x : ca) u.erase(x);
            u.erase(k);
            return;
        }

        if (isFree[edge[k].first] && !isFree[edge[k].second]) {
            for (int x : cb)u.erase(x);
            u.erase(k);
            return;
        }

        if (isFree[edge[k].first] && isFree[edge[k].second]) {
            for (int x : ca) u.erase(x);
            for (int x : cb) u.erase(x);
            u.erase(k);
            ans.edge_b.push_back(edge[k].first);
            ans.edge_e.push_back(edge[k].second);
            isFree[edge[k].first] = isFree[edge[k].second] = false;
        }
    };

    while (u.size() > 0) {
        try_match(*(u.begin()));
    }

    ans.n = ans.edge_b.size();

    return ans;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_LAM_H_
