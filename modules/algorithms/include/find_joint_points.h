// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
#define MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
#include "../../pch/include/precomp.h"

template <typename WeightType>
void find_joint_points(std::set <int>* joint_points, const CSR<WeightType>& graph);

template <typename WeightType>
int count_joint_points(const CSR<WeightType>& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
