// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_FLOYD_WARSHALL_H_
#define MODULES_ALGORITHMS_INCLUDE_FLOYD_WARSHALL_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
void floyd_warshall(std::vector <std::vector <WeightType>>* matrix,
                            const CSR<WeightType>& graph) {
    int n = graph.n;
    matrix->resize(n);
    for (int i = 0; i < n; ++i)
        (*matrix)[i].assign(n, 200000);
    for (int i = 0; i < n; ++i)
        for (int j = graph.offset[i]; j < graph.offset[i+1]; ++j)
            (*matrix)[i][graph.edges[j]] = graph.weights[j];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                (*matrix)[i][j] = std::min((*matrix)[i][j],
                                    (*matrix)[i][k] + (*matrix)[k][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if ((*matrix)[i][j] == 200000)
                (*matrix)[i][j] = 0;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_FLOYD_WARSHALL_H_
