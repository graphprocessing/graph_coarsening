// Copyright [year] <Copyright Owner>
#include "modules/pch/include/precomp.h"

static std::random_device rd;
static std::mt19937 generator(rd());

std::vector <int> generate_samples(int from, int to, int n = 20) {
    std::vector <int> result;
    for (int i = 0; i < n; ++i)
        result.push_back(std::uniform_int_distribution<int>(from, to)
                                (generator));
    return result;
}

std::vector <std::pair <int, int>>
            generate_pair_samples(int from, int to, int n = 20) {
    std::vector <int> r1 = generate_samples(from, to, n);
    std::vector <int> r2 = generate_samples(from, to, n);
    std::vector <std::pair <int, int>> result;
    for (int i = 0; i < n; ++i)
        result.emplace_back(r1[i], r2[i]);
    return result;
}

#include "../include/random_matching_parametric_test.h"
#include "../include/hard_matching_parametric_test.h"
#include "../include/pga_parametric_test.h"
#include "../include/gpa_parametric_test.h"
#include "../include/graph_coarsering_parametric_test.h"
#include "../include/edmonds_parametric_test.h"
#include "../include/lam_parametric_test.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
