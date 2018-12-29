// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

static std::vector <char> used;
static std::vector <int> in, check;
static int timer;

template <typename WeightType>
static void dfs(const AL<WeightType>& graph, std::set <int>* joint_points,
        int x, int p = -1) {
    used[x] = 1;
    in[x] = check[x] = ++timer;
    std::vector <std::pair <int, int>> neighbours;
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
}

template <typename WeightType>
void find_joint_points(std::set <int>* joint_points, const CSR<WeightType>& graph) {
    timer = 0;
    used.clear(), used.resize(graph.n);
    used.assign(graph.n, 0);
    in.clear(), in.resize(graph.n);
    check.clear(), check.resize(graph.n);
    AL <WeightType> al_graph(graph);
    for (int i = 0; i < al_graph.n; ++i)
        if (!used[i])
            dfs(al_graph, joint_points, i);
}

template <typename WeightType>
int count_joint_points(const CSR<WeightType>& graph) {
    std::set <int> joint_points;
    find_joint_points(&joint_points, graph);
    return joint_points.size();
}
