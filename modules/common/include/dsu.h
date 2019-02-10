// Copyright [year] <Copyright Owner>
#ifndef MODULES_COMMON_INCLUDE_DSU_H_
#define MODULES_COMMON_INCLUDE_DSU_H_
#include <vector>
#include "../../pch/include/precomp.h"

struct DSU {
    std::vector <int> p, rank;
    DSU() = delete;
    DSU(int n, ...);
    int get(int v);
    void unite(int a, int b);
};

#endif  // MODULES_COMMON_INCLUDE_DSU_H_
