// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

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
