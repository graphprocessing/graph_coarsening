// Copyright [year] <Copyright Owner>
#include "../include/random_matching_parametric_test.h"
#include "../include/hard_matching_parametric_test.h"
#include "../include/pga_parametric_test.h"
#include "../include/gpa_parametric_test.h"
#include "../include/graph_coarsering_parametric_test.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
