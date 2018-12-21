// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

static std::vector <char> used;
static std::vector <int> in, check;
static int timer;

static void dfs(const AL& graph, std::set <int>* joint_points,
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

void find_joint_points(std::set <int>* joint_points, const CSR& graph) {
    timer = 0;
    used.clear(), used.resize(graph.n);
    used.assign(graph.n, 0);
    in.clear(), in.resize(graph.n);
    check.clear(), check.resize(graph.n);
    AL al_graph(graph);
    for (int i = 0; i < al_graph.n; ++i)
        for (unsigned j = 0; j < al_graph.edges[i].size(); ++j)
            al_graph.edges[al_graph.edges[i][j].first].
                    push_back({i, al_graph.edges[i][j].second});
    for (int i = 0; i < al_graph.n; ++i) {
        std::sort(al_graph.edges[i].begin(), al_graph.edges[i].end());
        al_graph.edges[i].resize(std::unique(al_graph.edges[i].begin(),
                    al_graph.edges[i].end()) - al_graph.edges[i].begin());
    }
    for (int i = 0; i < al_graph.n; ++i)
        if (!used[i])
            dfs(al_graph, joint_points, i);
}

int count_joint_points(const CSR& graph) {
    std::set <int> joint_points;
    find_joint_points(&joint_points, graph);
    return joint_points.size();
}
