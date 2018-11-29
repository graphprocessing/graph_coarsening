// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#define MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
#include <utility>
#include <vector>
#include "../../data_structures/include/csr.h"
#include "../../data_structures/include/matching.h"

CSR graph_coarsening(const CSR& graph, const Matching& match);

#endif  // MODULES_ALGORITHMS_INCLUDE_GRAPH_COARSENING_H_
