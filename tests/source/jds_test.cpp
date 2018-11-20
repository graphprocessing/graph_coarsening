// Copyright [year] <Copyright Owner>
#include <iostream>
#include <vector>
#include <random>
#include "../../3rdparty/gtest/gtest.h"
#include "../../modules/data_structures/include/graph.h"
#include "../../modules/data_structures/include/csr.h"
#include "../../modules/data_structures/include/jds.h"
#include "../../modules/generators/include/washington_test.h"
#include "../../modules/generators/include/zadeh_test.h"
#include "../../modules/algorithms/include/random_matching.h"
#include "../../modules/algorithms/include/hard_matching.h"

static std::random_device rd;
static std::mt19937 generator(rd());
