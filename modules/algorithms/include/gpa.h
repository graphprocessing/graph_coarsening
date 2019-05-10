// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GPA_H_
#define MODULES_ALGORITHMS_INCLUDE_GPA_H_
#include "../../pch/include/precomp.h"

template <typename WeightType, typename MatchingFunction>
Matching GPA(const CSR<WeightType> &graph, MatchingFunction get_matching) {
    Matching result;
    struct Edge {
        int b, e;
        WeightType w;
        Edge(int b_, int e_, WeightType w_) : b(b_), e(e_), w(w_) {}
    };
    std::vector <Edge> e;
    AL<WeightType> e1;
    int n = graph.n;
    e1.n = n;
    e1.edges.resize(n);
    e1.weights.resize(n);
    e1.weight_vertex.resize(n);
    auto is_applicable = [&](int edge_index) {
        // closes odd len cycle
        int v = e[edge_index].b, len = 0;
        while (true) {
            if (e1.edges[v].size() == 0)
                break;
            if (v == e[edge_index].b)
                break;
            if (v == e[edge_index].e) {
                if (len % 2 == 1)
                    return false;
                break;
            }
            v = e1.edges[v].front();
            ++len;
        }
        v = e[edge_index].e, len = 0;
        while (true) {
            if (e1.edges[v].size() == 0)
                break;
            if (v == e[edge_index].e)
                break;
            if (v == e[edge_index].b) {
                if (len % 2 == 1)
                    return false;
                break;
            }
            v = e1.edges[v].front();
            ++len;
        }
        // is incident to an inner node
        if (e1.edges[e[edge_index].b].size() == 2u &&
            e1.edges[e[edge_index].e].size() == 2u)
            return false;
        return true;
    };
    std::vector <std::pair <int, WeightType>> neighbours;
    for (int i = 0; i < n; ++i) {
        neighbours.clear();
        graph.get_neighbours(&neighbours, i, i);
        for (unsigned j = 0; j < neighbours.size(); ++j)
            e.emplace_back(i, neighbours[j].first, neighbours[j].second);
    }
    std::sort(begin(e), end(e), [](const Edge& a, const Edge& b) {
        return a.w > b.w;
    });
    // Algo:
    for (unsigned i = 0; i < e.size(); ++i) {
        if (is_applicable(i)) {
            e1.edges[e[i].b].push_back(e[i].e);
            e1.weights[e[i].b].push_back(e[i].w);
            e1.edges[e[i].e].push_back(e[i].b);
            e1.weights[e[i].e].push_back(e[i].w);
        }
    }
    std::vector <char> was(n);
    while (true) {
        int v = 0;
        for (; v < n; ++v)
            if (!was[v])
                break;
        if (v == n)
            break;
        AL <WeightType> t_graph;
        t_graph.n = n;
        t_graph.edges.resize(n);
        t_graph.weights.resize(n);
        t_graph.weight_vertex.resize(n);
        std::vector <int> w = e1.dfs(v);
        for (int i = 0; i < n; ++i) {
            if (w[i]) {
                for (unsigned j = 0; j < e1.edges[i].size(); ++j) {
                    t_graph.edges[i].push_back(e1.edges[i][j]);
                    t_graph.weights[i].push_back(e1.weights[i][j]);
                }
                was[i] = 1;
            }
        }
        Matching t_matching = get_matching(t_graph);
        for (int i = 0; i < t_matching.n; ++i) {
            result.edge_b.push_back(t_matching.edge_b[i]);
            result.edge_e.push_back(t_matching.edge_e[i]);
        }
        result.n += t_matching.n;
    }
    return result;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_GPA_H_
