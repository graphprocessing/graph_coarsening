// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
std::vector <WeightType> vertexes_eccentricity(const CSR<WeightType>& graph) {
    std::vector <std::vector <WeightType>> matrix;
    floyd_warshall(&matrix, graph);
    std::vector <WeightType> ecc(graph.n, 0);
    for (unsigned i = 0; i < matrix.size(); ++i)
        for (unsigned j = 0; j < matrix[i].size(); ++j)
            ecc[i] = std::max(ecc[i], matrix[i][j]);
    return ecc;
}

template <typename WeightType>
WeightType graph_radius(const CSR<WeightType>& graph) {
    std::vector <WeightType> ecc = vertexes_eccentricity(graph);
    WeightType rad = 200000;
    for (WeightType e : ecc)
        rad = std::min(rad, e);
    return rad;
}

template <typename WeightType>
WeightType graph_diameter(const CSR<WeightType>& graph) {
    std::vector <WeightType> ecc = vertexes_eccentricity(graph);
    WeightType diam = 0;
    for (WeightType e : ecc)
        diam = std::max(diam, e);
    return diam;
}

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
