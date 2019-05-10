// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
struct JDS;

template <typename WeightType>
struct CSR;

template <typename WeightType>
struct AL;

template <typename WeightType>
struct Graph {
 public:
    int n = 0;
    std::vector <int> weight_vertex;
    int bfs(int from, int to);
    std::vector <int> dfs(int root);
    int Dijkstra(int from, int to);
    virtual bool get_neighbours(
        std::vector <std::pair<int, WeightType>>* neighbours,
        int vertex, int anc) const = 0;
    virtual bool read(const std::string& path) = 0;
    virtual bool write(const std::string& path) = 0;
 private:
    void dfs_recursion(std::vector <int>* pd,
        std::vector <char>* pwas, int x, int anc);
};

template <typename WeightType>
int Graph<WeightType>::bfs(int from, int to) {
    std::vector <int> d(n, -1);
    std::queue <int> q;
    d[from] = 0;
    q.push(from);
    while (q.size()) {
        int x = q.front();
        q.pop();
        std::vector <std::pair <int, WeightType>> neighbours;
        get_neighbours(&neighbours, x, x);
        for (auto y : neighbours) {
            if (d[y.first] == -1) {
                q.push(y.first);
                d[y.first] = d[x] + 1;
            }
        }
    }
    return d[to];
}

template <typename WeightType>
void Graph<WeightType>::dfs_recursion(std::vector <int>* pd,
                          std::vector <char>* pwas, int x, int anc) {
    std::vector <int>& d = *pd;
    std::vector <char>& was = *pwas;
    was[x] = 1;
    d[x] = d[anc] + 1;
    std::vector <std::pair <int, WeightType>> neighbours;
    get_neighbours(&neighbours, x, anc);
    for (auto y : neighbours) {
        if (!was[y.first])
            dfs_recursion(&d, &was, y.first, x);
    }
}

template <typename WeightType>
std::vector <int> Graph<WeightType>::dfs(int root) {
    std::vector <int> d(n, 0);
    std::vector <char> was(n, 0);
    dfs_recursion(&d, &was, root, root);
    return d;
}

template <typename WeightType>
int Graph<WeightType>::Dijkstra(int from, int to) {
    const int INF = 1000000000;
    std::vector <int> d(n, INF), p(n);
    d[from] = 0;
    std::set <std::pair<int, int> > s;
    s.insert(std::make_pair(d[from], from));
    while (s.size()) {
        int x = s.begin()->second;
        s.erase(s.begin());
        std::vector <std::pair <int, WeightType>> neighbours;
        get_neighbours(&neighbours, x, x);
        for (auto y : neighbours) {
            if (d[x] + y.second < d[y.first]) {
                s.erase(std::make_pair(d[y.first], y.first));
                d[y.first] = d[x] + y.second;
                s.insert(std::make_pair(d[y.first], y.first));
            }
        }
    }
    return d[to];
}

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_GRAPH_H_
