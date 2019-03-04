// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
#define MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
#include "../../pch/include/precomp.h"
template <typename WeightType>
Matching random_matching(const AL<WeightType>& graph, int distribution = 0,
            int vertexes_in_matching = INT_MAX, int random_seed = -1) {
    int n = graph.n;
    std::random_device rd;
    std::mt19937 generator(rd());
    Matching matching;
    if (vertexes_in_matching <= 0)
        return matching;
    std::vector <char> used(n, 0);
    std::vector <int> permutation(n);
    for (int i = 0; i < n; ++i)
        permutation[i] = i;
    randomize_permutation(&permutation, distribution, random_seed);
    int seed = random_seed;
    for (int i = 0; i < n; ++i) {
        if (!used[permutation[i]]) {
            int vertex = permutation[i];
            int sz = graph.edges[vertex].size();
            if (!sz)
                continue;
            int next = -2;
            for (int i = 0; i < sz; ++i) {
                if (!used[graph.edges[vertex][i]] &&
                                    graph.edges[vertex][i] != vertex) {
                    next = -1;
                    break;
                }
            }
            if (next == -2)
                continue;
            std::uniform_int_distribution<int> dist(0, sz - 1);
            while (next == -1) {
                int res;
                if (seed == -1) {
                    res = dist(generator);
                } else {
                    std::mt19937 fixed_generator(seed++);
                    res = dist(fixed_generator);
                }
                if (!used[graph.edges[vertex][res]] &&
                                    graph.edges[vertex][res] != vertex) {
                    next = graph.edges[vertex][res];
                }
            }
            used[vertex] = true;
            used[next] = true;
            matching.edge_b.push_back(vertex);
            matching.edge_e.push_back(next);
            ++matching.n;
            if (matching.n >= static_cast<int>(vertexes_in_matching))
                break;
        }
    }
    return matching;
}

template <typename WeightType>
Matching random_matching(const CSR<WeightType>& graph, int distribution = 0,
            int vertexes_in_matching = INT_MAX, int random_seed = -1) {
    int n = graph.n;
    std::random_device rd;
    std::mt19937 generator(rd());
    Matching matching;
    if (vertexes_in_matching <= 0)
        return matching;
    std::vector <char> used(n, 0);
    std::vector <int> permutation(n);
    for (int i = 0; i < n; ++i)
        permutation[i] = i;
    randomize_permutation(&permutation, distribution, random_seed);
    int seed = random_seed;
    for (int i = 0; i < n; ++i) {
        if (!used[permutation[i]]) {
            int vertex = permutation[i];
            int next = -2;
            const int& begin = graph.offset[vertex];
            const int& end = graph.offset[vertex+1];
            if (begin == end)
                continue;
            for (int i = begin; i < end; ++i) {
                if (!used[graph.edges[i]] && graph.edges[i] != vertex) {
                    next = -1;
                    break;
                }
            }
            if (next == -2)
                continue;
            std::uniform_int_distribution<int> dist(0, end - begin - 1);
            while (next == -1) {
                int res;
                if (seed == -1) {
                    res = dist(generator);
                } else {
                    std::mt19937 fixed_generator(seed++);
                    res = dist(fixed_generator);
                }
                if (!used[graph.edges[begin + res]] &&
                                    graph.edges[begin + res] != vertex) {
                    next = graph.edges[begin + res];
                }
            }
            used[vertex] = true;
            used[next] = true;
            matching.edge_b.push_back(vertex);
            matching.edge_e.push_back(next);
            ++matching.n;
            if (matching.n >= static_cast<int>(vertexes_in_matching))
                break;
        }
    }
    return matching;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
