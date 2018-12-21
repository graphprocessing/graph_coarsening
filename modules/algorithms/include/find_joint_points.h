// Copyright [year] <Copyright Owner>
#ifndef MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
#define MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
#include "../../pch/include/precomp.h"

void find_joint_points(std::set <int>* joint_points, const CSR& graph);
int count_joint_points(const CSR& graph);

#endif  // MODULES_ALGORITHMS_INCLUDE_FIND_JOINT_POINTS_H_
