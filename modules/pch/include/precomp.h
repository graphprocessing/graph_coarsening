// Copyright [year] <Copyright Owner>
#ifndef MODULES_PCH_INCLUDE_PRECOMP_H_
#define MODULES_PCH_INCLUDE_PRECOMP_H_
// OpenMP
#include <omp.h>
// C++
#include <iostream>
#include <fstream>
#include <random>
#include <climits>
#include <exception>
// STL
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <sstream>
// Graph common
#include "modules/common/include/timer.h"
#include "modules/common/include/randomize.h"
#include "modules/common/include/dsu.h"
// Graph data structures
#include "modules/data_structures/include/graph.h"
#include "modules/data_structures/include/adjacency_list.h"
#include "modules/data_structures/include/csr.h"
#include "modules/data_structures/include/matching.h"
// Graph generators
#include "modules/generators/include/washington_test.h"
#include "modules/generators/include/zadeh_test.h"
#include "modules/generators/include/cube_test.h"
#include "modules/generators/include/cycle_generator.h"
#include "modules/generators/include/stars_generator.h"
#include "modules/generators/include/chain_generator.h"
// Graph algorithms
#include "modules/algorithms/include/random_matching.h"
#include "modules/algorithms/include/hard_matching.h"
#include "modules/algorithms/include/floyd_warshall.h"
#include "modules/algorithms/include/find_bridges.h"
#include "modules/algorithms/include/find_joint_points.h"
#include "modules/algorithms/include/graph_coarsening.h"
#include "modules/algorithms/include/graph_distances.h"
#include "modules/algorithms/include/minimal_spanning_tree.h"
#include "modules/algorithms/include/strongly_connected_components.h"
#include "modules/algorithms/include/edmonds.h"
#include "modules/algorithms/include/pga.h"
#include "modules/algorithms/include/max_weight_matching.h"
#include "modules/algorithms/include/gpa.h"
#include "modules/algorithms/include/LAM.h"
// Import/export
#include "modules/common/include/import.h"
#include "modules/common/include/export.h"
// yaml
#include "3rdparty/libyaml/include/yaml.h"
#include "modules/pipelines/include/parser.h"

#endif  // MODULES_PCH_INCLUDE_PRECOMP_H_
