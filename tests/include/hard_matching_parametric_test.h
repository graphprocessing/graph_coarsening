// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_HARD_MATCHING_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_HARD_MATCHING_PARAMETRIC_TEST_H_
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
#include "../../modules/algorithms/include/hard_matching.h"

class hard_matching_washington_test : public testing::TestWithParam<int> {
 public:
    hard_matching_washington_test() {
        value = GetParam();
    }

    void hard_matching_on_al() {
        AL al = washington_test(value);
        Matching matching = hard_matching(al);
        std::vector <int> ed(al.n, 0);
        int k = 1;
        for (int i = 0; i < matching.n; i++) {
            ed[matching.edge_b[i]] = k;
            ed[matching.edge_e[i]] = k;
            ++k;
        }
        for (int i = 0; i < matching.n; i++) {
            int to = matching.edge_b[i],
                to1 = matching.edge_e[i];
            for (unsigned j = 0; j < al.edges[to].size(); j++) {
                int v = al.edges[to][j].first;
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (unsigned j = 0; j < al.edges[to1].size(); j++) {
                int v = al.edges[to1][j].first;
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }
    void hard_matching_on_csr() {
        CSR csr = washington_test(value);
        Matching matching = hard_matching(csr);
        std::vector <int> ed(csr.n, 0);
        int k = 1;
        for (int i = 0; i < matching.n; i++) {
            ed[matching.edge_b[i]] = k;
            ed[matching.edge_e[i]] = k;
            ++k;
        }
        for (int i = 0; i < matching.n; i++) {
            int to = matching.edge_b[i],
                to1 = matching.edge_e[i];
            for (int j = csr.offset[to]; j < csr.offset[to + 1]; ++j) {
                int v = csr.edges[j].first;
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (int j = csr.offset[to1]; j < csr.offset[to1 + 1]; ++j) {
                int v = csr.edges[j].first;
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }

 private:
    int value;
};

TEST_P(hard_matching_washington_test, al) {
    hard_matching_on_al();
}

TEST_P(hard_matching_washington_test, csr) {
    hard_matching_on_csr();
}

INSTANTIATE_TEST_CASE_P(hard_matching_test, hard_matching_washington_test,
                    testing::Values(2));

#endif  // TESTS_INCLUDE_HARD_MATCHING_PARAMETRIC_TEST_H_
