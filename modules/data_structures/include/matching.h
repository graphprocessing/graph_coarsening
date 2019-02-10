// Copyright [year] <Copyright Owner>
#ifndef MODULES_DATA_STRUCTURES_INCLUDE_MATCHING_H_
#define MODULES_DATA_STRUCTURES_INCLUDE_MATCHING_H_
#include <vector>
#include "../../pch/include/precomp.h"

struct Matching {
 public:
    int n = 0;
    std::vector <int> edge_b;
    std::vector <int> edge_e;
};

#endif  // MODULES_DATA_STRUCTURES_INCLUDE_MATCHING_H_
