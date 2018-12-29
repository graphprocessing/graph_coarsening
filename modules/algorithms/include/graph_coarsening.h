// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
CSR<WeightType> graph_coarsening(const CSR<WeightType>& graph, const Matching& match);

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
