// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_EDMONDS_H_
#define MODULES_ALGORITHMS_INCLUDE_EDMONDS_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>

Matching edmonds(const CSR<WeightType> & graph) {
    int n = graph.n;
    static int times = 0;
    Matching ans;
    std::vector<bool> isthere(n + 1);
    std::vector<int> base(n + 1), was(n + 1);
    std::vector<int> match(n + 1), p(n + 1), Type(n + 1);
    std::queue<int> Q;

    std::function<int(int, int)>
    LCA = [&](int x, int y) {
        times++;
        x = base[x], y = base[y];
        while (was[x] != times) {
            if (x) {
                was[x] = times;
                x = base[p[match[x]]];
            }
            std::swap(x, y);
        }
        return x;
    };


    std::function<void(int, int, int)>
    blossom = [&](int x, int y, int lca) {
        while (base[x] != lca) {
            p[x] = y;
            y = match[x];
            if (Type[y] == 1) {
                Type[y] = 0;
                Q.push(y);
            }
            base[x] = base[y] = base[lca];
            x = p[y];
        }
    };

    std::function<int(const CSR<WeightType>&, int)>
    find_path = [&](const CSR<WeightType>& graph, int s) {
        for (int i = 1; i <= n; i++) base[i] = i;
        for (int i = 0; i <= n; i++) Type[i] = -1;
        Q = std::queue<int> ();
        Type[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            int Now = Q.front();
            Q.pop();
            for (int i = graph.offset[Now - 1]; i < graph.offset[Now]; i++) {
                int Next = graph.edges[i] + 1;
                if (Type[Next] == -1) {
                    p[Next] = Now;
                    Type[Next] = 1;
                    if (!match[Next]) {
                        for (int to = Next, from = Now; to; from = p[to]) {
                            match[to] = from;
                            std::swap(match[from], to);
                        }
                        return true;
                    }
                    Type[match[Next]] = 0;
                    Q.push(match[Next]);
                } else if (Type[Next] == 0 && base[Now] != base[Next]) {
                    int lca = LCA(Now, Next);
                    blossom(Now, Next, lca);
                    blossom(Next, Now, lca);
                }
            }
        }
        return false;
    };
    for (int i = n; i >= 1; i--)
        if (!match[i]) ans.n += find_path(graph, i);
    for (int i = 1; i <= n; i++) {
        if (!isthere[i] && match[i]) {
            ans.edge_b.push_back(i - 1);
            ans.edge_e.push_back(match[i] - 1);
            isthere[match[i]] = true;
        }
    }
    return ans;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_EDMONDS_H_
