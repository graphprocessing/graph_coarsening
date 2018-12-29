// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
#define MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
void find_joint_points(std::set <int>* joint_points, const CSR<WeightType>& graph) {
    std::vector <char> used;
    std::vector <int> in, check;
    int timer;
    std::function <void(const AL<WeightType>&, std::set <int>*, int, int)> dfs =
        [&](const AL<WeightType>& graph, std::set <int>* joint_points, int x, int p) {
        used[x] = 1;
        in[x] = check[x] = ++timer;
        std::vector <std::pair <int, WeightType>> neighbours;
        graph.get_neighbours(&neighbours, x, x);
        int children = 0;
        for (std::pair <int, int> vertex : neighbours) {
            int y = vertex.first;
            if (y != p) {
                if (!used[y]) {
                    dfs(graph, joint_points, y, x);
                    check[x] = std::min(check[x], check[y]);
                    if (check[y] >= in[x] && p != -1)
                        joint_points->insert(x);
                    ++children;
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
            dfs(al_graph, joint_points, i, -1);
}

template <typename WeightType>
int count_joint_points(const CSR<WeightType>& graph) {
    std::set <int> joint_points;
    find_joint_points(&joint_points, graph);
    return joint_points.size();
}

#endif  // MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
