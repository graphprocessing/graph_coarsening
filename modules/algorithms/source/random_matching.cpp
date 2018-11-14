// Copyright [year] <Copyright Owner>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include "../../data_structures/include/adjacency_list.h"
#include "../../data_structures/include/csr.h"

std::vector <std::pair <int, int>> random_matching(AL graph) {
    int n = graph.n;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector <std::pair <int, int>> matching;
    std::vector <char> used(n, 0);
    std::vector <int> permutation(n);
    for (int i = 0; i < n; ++i)
        permutation[i] = i;
    std::random_shuffle(permutation.begin(), permutation.end(), [&](int a) {
        std::uniform_int_distribution<int> sort_dist(0, a);
        return sort_dist(generator);
    });
    for (int i : permutation) {
        if (!used[i]) {
            int vertex = i;
            int sz = graph.edges[vertex].size();
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
                int res = dist(generator);
                if (!used[graph.edges[vertex][res].first]) {
                    next = graph.edges[vertex][res].first;
                }
            }
            used[vertex] = true;
            used[next] = true;
            matching.emplace_back(vertex, next);
            vertex = next;
        }
    }
    return matching;
}
