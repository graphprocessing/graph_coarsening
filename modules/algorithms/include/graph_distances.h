// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
std::vector <int> vertexes_eccentricity(const CSR<WeightType>& graph);

template <typename WeightType>
int graph_radius(const CSR<WeightType>& graph);

template <typename WeightType>
int graph_diameter(const CSR<WeightType>& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
