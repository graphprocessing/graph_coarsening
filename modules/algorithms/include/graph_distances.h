// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
#include "../../pch/include/precomp.h"

std::vector <int> vertexes_eccentricity(const CSR& graph);
int graph_radius(const CSR& graph);
int graph_diameter(const CSR& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_DISTANCES_H_
