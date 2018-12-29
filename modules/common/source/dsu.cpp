// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

DSU::DSU(int n, ...) {
    p.resize(n);
    for (int i = 0; i < n; ++i)
        p[i] = i;
    rank.assign(n, 0);
}

int DSU::get(int v) {
    return (v == p[v]) ? v : (p[v] = get(p[v]));
}

void DSU::unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (rank[a] < rank[b])
            std::swap(a, b);
        p[b] = a;
        if (rank[a] == rank[b])
        ++rank[a];
    }
}
