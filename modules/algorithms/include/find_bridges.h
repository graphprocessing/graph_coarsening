// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_FIND_BRIDGES_H_
#define MODULES_ALGORITHMS_INCLUDE_FIND_BRIDGES_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
void find_bridges(std::set <std::pair <int, WeightType>>* bridges, const CSR<WeightType>& graph) {
    std::vector <char> used;
    std::vector <int> in, check;
    int timer;
    std::function <void(const AL<WeightType>&, std::set <std::pair <int, WeightType>>*, int, int)>
        dfs = [&](const AL<WeightType>& graph, std::set <std::pair <int, WeightType>>* bridges, int x, int p) {
        used[x] = 1;
        in[x] = check[x] = ++timer;
        std::vector <std::pair <int, WeightType>> neighbours;
        graph.get_neighbours(&neighbours, x, x);
        for (std::pair <int, WeightType> vertex : neighbours) {
            int y = vertex.first;
            if (y != p) {
                if (!used[y]) {
                    dfs(graph, bridges, y, x);
                    check[x] = std::min(check[x], check[y]);
                    if (check[y] > in[x]) {
                        int X = x, Y = y;
                        if (X > Y)
                            std::swap(X, Y);
                        bridges->insert({X, Y});
                    }
                } else {
                    check[x] = std::min(check[x], in[y]);
                }
            }
        }
    };
    timer = 0;
    used.clear(), used.resize(graph.n);
    used.assign(graph.n, 0);
    in.clear(), in.resize(graph.n);
    check.clear(), check.resize(graph.n);
    AL <WeightType> al_graph(graph);
    for (int i = 0; i < al_graph.n; ++i)
        if (!used[i])
            dfs(al_graph, bridges, i, -1);
}

template <typename WeightType>
int count_bridges(const CSR<WeightType>& graph) {
    std::set <std::pair <int, WeightType>> bridges;
    find_bridges(&bridges, graph);
    return bridges.size();
}


#endif  // MODULES_ALGORITHMS_INCLUDE_FIND_BRIDGES_H_
