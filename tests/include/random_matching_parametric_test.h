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
#include "../../modules/algorithms/include/random_matching.h"

class random_matching_parametric_test : public testing::TestWithParam<int> {
 public:
    random_matching_parametric_test() {
        value = GetParam();
    }

    void do_test_1() {
        CSR csr = washington_test(value);
        std::vector <char> used(csr.n, 0);
        auto matching = random_matching(csr);
        for (int i = 0; i < matching.n; ++i)
            used[matching.edge_b[i]] = used[matching.edge_e[i]] = true;
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j)
                    ASSERT_EQ(true, used[csr.edges[j].first]);
            }
        }
    }

    void do_test_2() {
        AL al = washington_test(value);
        std::vector <char> used(al.n, 0);
        auto matching = random_matching(al);
        for (int i = 0; i < matching.n; ++i)
            used[matching.edge_b[i]] = used[matching.edge_e[i]] = true;
        for (int i = 0; i < al.n; ++i) {
            if (!used[i]) {
                for (unsigned j = 0; j < al.edges[i].size(); ++j)
                    ASSERT_EQ(true, used[al.edges[i][j].first]);
            }
        }
    }

    void do_test_3() {
        
    }

 private:
    int value;
};

std::vector <int> generate_samples(int n) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector <int> result;
    for (int i = 0; i < n; ++i)
        result.push_back(std::uniform_int_distribution<int>(1e5, 1e6)(generator));
    return result;
}

std::vector <int> samples = generate_samples(10);

TEST_P(random_matching_parametric_test, correct_random_matching_on_csr) {
    do_test_1();
}

TEST_P(random_matching_parametric_test, correct_random_matching_on_al) {
    do_test_2();
}

INSTANTIATE_TEST_CASE_P(random_matching_test, random_matching_parametric_test,
                        testing::ValuesIn(samples));

#endif  // TESTS_INCLUDE_RANDOM_MATCHING_PARAMETRIC_TEST_H_