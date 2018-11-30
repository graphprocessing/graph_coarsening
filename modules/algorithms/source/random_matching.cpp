// Copyright [year] <Copyright Owner>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../data_structures/include/adjacency_list.h"
#include "../../data_structures/include/csr.h"
#include "../../data_structures/include/matching.h"
#include "../../common/include/randomize.h"

Matching random_matching(const AL& graph, int distribution,
            int vertexes_in_matching, int random_seed) {
    int n = graph.n;
    std::random_device rd;
    std::mt19937 generator(rd());
    Matching matching;
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
                if (!used[graph.edges[vertex][i].first]) {
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
                if (!used[graph.edges[vertex][res].first]) {
                    next = graph.edges[vertex][res].first;
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

Matching random_matching(const CSR& graph, int distribution,
            int vertexes_in_matching, int random_seed) {
    int n = graph.n;
    std::random_device rd;
    std::mt19937 generator(rd());
    Matching matching;
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
                if (!used[graph.edges[i].first]) {
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
                if (!used[graph.edges[begin + res].first]) {
                    next = graph.edges[begin + res].first;
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
