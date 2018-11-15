// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
#define MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
#include <utility>
#include <vector>
#include "../../data_structures/include/adjacency_list.h"
#include "../../data_structures/include/csr.h"
#include "../../data_structures/include/matching.h"

Matching random_matching(const AL& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
