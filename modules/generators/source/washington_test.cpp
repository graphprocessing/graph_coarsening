// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"
static const int max_weight = 100000;

AL washington_test(int n, bool weighted) {
    AL graph;
    try {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> weight(1, weighted ? max_weight : 1);
        graph.n = 3 * n + 3;
        graph.edges.resize(graph.n);
        graph.edges[0].push_back({1, weight(generator)});
        for (int i = 2; i < n + 2; ++i)
            graph.edges[1].push_back({i, weight(generator)});
        for (int i = n + 2; i < 2 * n + 2; ++i)
            graph.edges[i - n].push_back({i, weight(generator)});
        for (int i = n + 2; i < 2 * n + 2; ++i)
            graph.edges[i].push_back({2 * n + 2, weight(generator)});
        for (int i = 2 * n + 3; i < 3 * n + 3; ++i)
            graph.edges[i - 1].push_back({i, weight(generator)});
    }
    catch (std::bad_alloc ba) {
        std::cerr << ba.what() << std::endl;
    }
    return graph;
}

