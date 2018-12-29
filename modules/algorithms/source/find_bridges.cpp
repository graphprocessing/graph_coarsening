// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

static std::vector <char> used;
static std::vector <int> in, check;
static int timer;

template <typename WeightType>
static void dfs(const AL<WeightType>& graph, std::set <std::pair <int, int>>* bridges,
        int x, int p = -1) {
    used[x] = 1;
    in[x] = check[x] = ++timer;
    std::vector <std::pair <int, int>> neighbours;
    graph.get_neighbours(&neighbours, x, x);
    for (std::pair <int, int> vertex : neighbours) {
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
}

template <typename WeightType>
void find_bridges(std::set <std::pair <int, int>>* bridges, const CSR<WeightType>& graph) {
    timer = 0;
    used.clear(), used.resize(graph.n);
    used.assign(graph.n, 0);
    in.clear(), in.resize(graph.n);
    check.clear(), check.resize(graph.n);
    AL <WeightType> al_graph(graph);
    for (int i = 0; i < al_graph.n; ++i)
        if (!used[i])
            dfs(al_graph, bridges, i);
}

template <typename WeightType>
int count_bridges(const CSR<WeightType>& graph) {
    std::set <std::pair <int, int>> bridges;
    find_bridges(&bridges, graph);
    return bridges.size();
}
