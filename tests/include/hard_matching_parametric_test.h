// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_HARD_MATCHING_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_HARD_MATCHING_PARAMETRIC_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

class hard_matching_washington_test : public testing::TestWithParam<int> {
 public:
    hard_matching_washington_test() {
        value = GetParam();
    }

    void hard_matching_on_al() {
        AL<int> al = washington_test<int>(value);
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
                int v = al.edges[to][j];
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (unsigned j = 0; j < al.edges[to1].size(); j++) {
                int v = al.edges[to1][j];
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }
    void hard_matching_on_csr() {
        CSR<int> csr = washington_test<int>(value);
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
                int v = csr.edges[j];
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (int j = csr.offset[to1]; j < csr.offset[to1 + 1]; ++j) {
                int v = csr.edges[j];
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }
    void test_hard_matching_on_al() {
        AL<int> al = washington_test<int>(value);
        Matching matching = hard_matching(al);
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }
    void test_hard_matching_on_csr() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = hard_matching(csr);
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

 private:
    int value;
};

class hard_matching_zadeh_test : public testing::TestWithParam<int> {
 public:
    hard_matching_zadeh_test() {
        value = GetParam();
    }

    void hard_matching_on_al() {
        AL<int> al = zadeh_test<int>(value);
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
                int v = al.edges[to][j];
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (unsigned j = 0; j < al.edges[to1].size(); j++) {
                int v = al.edges[to1][j];
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }
    void hard_matching_on_csr() {
        CSR<int> csr = zadeh_test<int>(value);
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
                int v = csr.edges[j];
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (int j = csr.offset[to1]; j < csr.offset[to1 + 1]; ++j) {
                int v = csr.edges[j];
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }
    void test_hard_matching_on_al() {
        AL<int> al = zadeh_test<int>(value);
        Matching matching = hard_matching(al);
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }
    void test_hard_matching_on_csr() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = hard_matching(csr);
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

 private:
    int value;
};

class hard_matching_cube_test : public testing::TestWithParam<int> {
 public:
    hard_matching_cube_test() {
        value = GetParam();
    }

    void hard_matching_on_al() {
        AL<int> al = cube_test<int>(value);
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
                int v = al.edges[to][j];
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (unsigned j = 0; j < al.edges[to1].size(); j++) {
                int v = al.edges[to1][j];
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }
    void hard_matching_on_csr() {
        CSR<int> csr = cube_test<int>(value);
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
                int v = csr.edges[j];
                if (v != to1) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
            for (int j = csr.offset[to1]; j < csr.offset[to1 + 1]; ++j) {
                int v = csr.edges[j];
                if (v != to) {
                    ASSERT_NE(ed[to1], ed[v]);
                }
            }
        }
    }
    void test_hard_matching_on_al() {
        AL<int> al = cube_test<int>(value);
        Matching matching = hard_matching(al);
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }
    void test_hard_matching_on_csr() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = hard_matching(csr);
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

 private:
    int value;
};

std::vector <int> hard_washington_samples = generate_samples(0, 50, 5);
std::vector <int> hard_zadeh_samples = generate_samples(0, 50, 5);
std::vector <int> hard_cube_samples = generate_samples(0, 10, 5);

TEST_P(hard_matching_washington_test, al) {
    hard_matching_on_al();
}

TEST_P(hard_matching_washington_test, csr) {
    hard_matching_on_csr();
}

TEST_P(hard_matching_washington_test, al1) {
    test_hard_matching_on_al();
}

TEST_P(hard_matching_washington_test, csr1) {
    test_hard_matching_on_csr();
}

TEST_P(hard_matching_zadeh_test, al) {
    hard_matching_on_al();
}

TEST_P(hard_matching_zadeh_test, csr) {
    hard_matching_on_csr();
}

TEST_P(hard_matching_zadeh_test, al1) {
    test_hard_matching_on_al();
}

TEST_P(hard_matching_zadeh_test, csr1) {
    test_hard_matching_on_csr();
}

TEST_P(hard_matching_cube_test, al) {
    hard_matching_on_al();
}

TEST_P(hard_matching_cube_test, csr) {
    hard_matching_on_csr();
}

TEST_P(hard_matching_cube_test, al1) {
    test_hard_matching_on_al();
}

TEST_P(hard_matching_cube_test, csr1) {
    test_hard_matching_on_csr();
}

INSTANTIATE_TEST_SUITE_P(hard_matching_test, hard_matching_washington_test,
                    testing::ValuesIn(hard_washington_samples));

INSTANTIATE_TEST_SUITE_P(hard_matching_test, hard_matching_zadeh_test,
                    testing::ValuesIn(hard_zadeh_samples));

INSTANTIATE_TEST_SUITE_P(hard_matching_test, hard_matching_cube_test,
                    testing::ValuesIn(hard_cube_samples));
#endif  // TESTS_INCLUDE_HARD_MATCHING_PARAMETRIC_TEST_H_
