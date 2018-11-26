// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_RANDOM_MATCHING_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_RANDOM_MATCHING_PARAMETRIC_TEST_H_
#include <random>
#include <vector>
#include "../../3rdparty/gtest/gtest.h"
#include "../../modules/data_structures/include/graph.h"
#include "../../modules/data_structures/include/csr.h"
#include "../../modules/data_structures/include/jds.h"
#include "../../modules/data_structures/include/adjacency_list.h"
#include "../../modules/generators/include/washington_test.h"
#include "../../modules/generators/include/zadeh_test.h"
#include "../../modules/generators/include/cube_test.h"
#include "../../modules/algorithms/include/random_matching.h"

class random_matching_washington_test : public testing::TestWithParam<int> {
 public:
    random_matching_washington_test() {
        value = GetParam();
    }

    void correct_random_matching_on_csr() {
        CSR csr = washington_test(value);
        std::vector <char> used(csr.n, 0);
        auto matching = random_matching(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j)
                    ASSERT_NE(0, used[csr.edges[j].first]);
            }
        }
    }

    void correct_random_matching_on_al() {
        AL al = washington_test(value);
        std::vector <char> used(al.n, 0);
        auto matching = random_matching(al);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < al.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < al.n; ++i) {
            if (!used[i]) {
                for (unsigned j = 0; j < al.edges[i].size(); ++j)
                    ASSERT_NE(0, used[al.edges[i][j].first]);
            }
        }
    }

 private:
    int value;
};

class random_matching_zadeh_test : public testing::TestWithParam<int> {
 public:
    random_matching_zadeh_test() {
        value = GetParam();
    }

    void correct_random_matching_on_csr() {
        CSR csr = zadeh_test(value);
        std::vector <char> used(csr.n, 0);
        auto matching = random_matching(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j)
                    ASSERT_NE(0, used[csr.edges[j].first]);
            }
        }
    }

    void correct_random_matching_on_al() {
        AL al = zadeh_test(value);
        std::vector <char> used(al.n, 0);
        auto matching = random_matching(al);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < al.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < al.n; ++i) {
            if (!used[i]) {
                for (unsigned j = 0; j < al.edges[i].size(); ++j)
                    ASSERT_NE(0, used[al.edges[i][j].first]);
            }
        }
    }

 private:
    int value;
};

class random_matching_cube_test : public testing::TestWithParam<int> {
 public:
    random_matching_cube_test() {
        value = GetParam();
    }

    void correct_random_matching_on_csr() {
        CSR csr = cube_test(value);
        std::vector <char> used(csr.n, 0);
        auto matching = random_matching(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j)
                    ASSERT_NE(0, used[csr.edges[j].first]);
            }
        }
    }

    void correct_random_matching_on_al() {
        AL al = cube_test(value);
        std::vector <char> used(al.n, 0);
        auto matching = random_matching(al);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < al.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < al.n; ++i) {
            if (!used[i]) {
                for (unsigned j = 0; j < al.edges[i].size(); ++j)
                    ASSERT_NE(0, used[al.edges[i][j].first]);
            }
        }
    }

 private:
    int value;
};

std::vector <int> generate_samples(int from, int to, int n = 20) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector <int> result;
    for (int i = 0; i < n; ++i)
        result.push_back(std::uniform_int_distribution<int>(from, to)
                                (generator));
    return result;
}

std::vector <int> washington_samples = generate_samples(0, 1e6);
std::vector <int> zadeh_samples = generate_samples(0, 1e3);
std::vector <int> cube_samples = generate_samples(0, 100);

TEST_P(random_matching_washington_test,
                    correct_random_matching_on_csr) {
    correct_random_matching_on_csr();
}

TEST_P(random_matching_washington_test,
                    correct_random_matching_on_al) {
    correct_random_matching_on_al();
}

TEST_P(random_matching_zadeh_test,
                    correct_random_matching_on_csr) {
    correct_random_matching_on_csr();
}

TEST_P(random_matching_zadeh_test,
                    correct_random_matching_on_al) {
    correct_random_matching_on_al();
}

TEST_P(random_matching_cube_test,
                    correct_random_matching_on_csr) {
    correct_random_matching_on_csr();
}

TEST_P(random_matching_cube_test,
                    correct_random_matching_on_al) {
    correct_random_matching_on_al();
}

INSTANTIATE_TEST_CASE_P(random_matching_test, random_matching_washington_test,
                    testing::ValuesIn(washington_samples));

INSTANTIATE_TEST_CASE_P(random_matching_test2, random_matching_washington_test,
                    testing::ValuesIn(zadeh_samples));

INSTANTIATE_TEST_CASE_P(random_matching_test3, random_matching_washington_test,
                    testing::ValuesIn(cube_samples));

#endif  // TESTS_INCLUDE_RANDOM_MATCHING_PARAMETRIC_TEST_H_
