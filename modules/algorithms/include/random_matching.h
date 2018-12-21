// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
#define MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
#include "../../pch/include/precomp.h"

Matching random_matching(const AL& graph, int distribution = 0,
            int vertexes_in_matching = INT_MAX, int random_seed = -1);
Matching random_matching(const CSR& graph, int distribution = 0,
            int vertexes_in_matching = INT_MAX, int random_seed = -1);

#endif  // MODULES_ALGORITHMS_INCLUDE_RANDOM_MATCHING_H_
