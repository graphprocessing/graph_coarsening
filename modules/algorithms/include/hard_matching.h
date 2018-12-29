// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_HARD_MATCHING_H_
#define MODULES_ALGORITHMS_INCLUDE_HARD_MATCHING_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
Matching hard_matching(const AL<WeightType>& graph);

template <typename WeightType>
Matching hard_matching(const CSR<WeightType>& gtaph);

#endif  // MODULES_ALGORITHMS_INCLUDE_HARD_MATCHING_H_
