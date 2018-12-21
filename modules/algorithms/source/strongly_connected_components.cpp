// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

static std::vector <char> used;
static std::vector <int> order;
static int index;

static void dfs1(const AL& graph, int x) {
    used[x] = 1;
    std::vector <std::pair <int, int>> neighbours;
    graph.get_neighbours(&neighbours, x, x);
    for (auto y : neighbours)
        if (!used[y.first])
            dfs1(graph, y.first);
    order.push_back(x);
}

static void dfs2(const AL& graph, std::vector <int>* comp, int x) {
    used[x] = 1;
    (*comp)[x] = index;
    std::vector <std::pair <int, int>> neighbours;
    graph.get_neighbours(&neighbours, x, x);
    for (auto y : neighbours)
        if (!used[y.first])
            dfs2(graph, comp, y.first);
}

void find_strongly_connected_components(std::vector <int>* comp,
                        const CSR& graph) {
    index = 1;
    used.clear(), used.resize(graph.n);
    order.clear();
    comp->resize(graph.n);
    comp->assign(graph.n, 0);
    AL g, rg;
    g.n = rg.n = graph.n;
    g.edges.resize(graph.n);
    rg.edges.resize(graph.n);
    for (int i = 0; i < graph.n; ++i) {
        std::vector <std::pair <int, int>> neighbours;
        graph.get_neighbours(&neighbours, i, i);
        for (unsigned j = 0; j < neighbours.size(); ++j) {
            g.edges[i].push_back({neighbours[j].first, neighbours[j].second});
            rg.edges[neighbours[j].first].push_back({i, neighbours[j].second});
        }
    }
    used.assign(graph.n, 0);
    for (int i = 0; i < g.n; ++i)
        if (!used[i])
            dfs1(g, i);
    used.assign(graph.n, 0);
    std::reverse(begin(order), end(order));
    for (int y : order) {
        if (!used[y]) {
            dfs2(rg, comp, y);
            ++index;
        }
    }
}
