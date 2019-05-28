// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_PGA_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_PGA_PARAMETRIC_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

class pga_washington_test : public testing::TestWithParam<int> {
 public:
    pga_washington_test() {
        value = GetParam();
    }

    void pga_on_csr_random() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
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

    void pga_on_csr_hard() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
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

    void pga_on_csr_edmonds() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
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

    void pga_on_csr_max_weight() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
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

    void test_pga_on_csr_random() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_hard() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_edmonds() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_max_weight() {
        CSR<int> csr = washington_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
           return max_weight_matching<int>(graph);
        });
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

class pga_zadeh_test : public testing::TestWithParam<int> {
 public:
    pga_zadeh_test() {
        value = GetParam();
    }

    void pga_on_csr_random() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
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

     void pga_on_csr_hard() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
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

     void pga_on_csr_edmonds() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
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

    void pga_on_csr_max_weight() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
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

    void test_pga_on_csr_random() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_hard() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_edmonds() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_max_weight() {
        CSR<int> csr = zadeh_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
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

class pga_cube_test : public testing::TestWithParam<int> {
 public:
    pga_cube_test() {
        value = GetParam();
    }

    void pga_on_csr_random() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
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

    void pga_on_csr_hard() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
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

    void pga_on_csr_edmonds() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
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

    void pga_on_csr_max_weight() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
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

    void test_pga_on_csr_random() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_hard() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_edmonds() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        std::map <int, int> m;
        for (int i = 0; i < matching.n; i++) {
            m[matching.edge_e[i]]++;
            m[matching.edge_b[i]]++;
        }
        for (auto it : m) {
            EXPECT_EQ(1, it.second);
        }
    }

    void test_pga_on_csr_max_weight() {
        CSR<int> csr = cube_test<int>(value);
        Matching matching = PGA(csr, [](const CSR<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
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

std::vector <int> pga_washington_samples = generate_samples(0, 50, 5);
std::vector <int> pga_zadeh_samples = generate_samples(0, 50, 5);
std::vector <int> pga_cube_samples = generate_samples(0, 10, 5);


TEST_P(pga_washington_test, csr) {
    pga_on_csr_random();
}

TEST_P(pga_washington_test, csr1) {
    pga_on_csr_hard();
}

TEST_P(pga_washington_test, csr2) {
    pga_on_csr_edmonds();
}

TEST_P(pga_washington_test, csr3) {
    pga_on_csr_max_weight();
}

TEST_P(pga_washington_test, csr4) {
    test_pga_on_csr_random();
}

TEST_P(pga_washington_test, csr5) {
    test_pga_on_csr_hard();
}

TEST_P(pga_washington_test, csr6) {
    test_pga_on_csr_edmonds();
}

TEST_P(pga_washington_test, csr7) {
    test_pga_on_csr_max_weight();
}

TEST_P(pga_zadeh_test, csr) {
    pga_on_csr_random();
}

TEST_P(pga_zadeh_test, csr1) {
    pga_on_csr_hard();
}

TEST_P(pga_zadeh_test, csr2) {
    pga_on_csr_edmonds();
}

TEST_P(pga_zadeh_test, csr3) {
    pga_on_csr_max_weight();
}

TEST_P(pga_zadeh_test, csr4) {
    test_pga_on_csr_random();
}

TEST_P(pga_zadeh_test, csr5) {
    test_pga_on_csr_hard();
}

TEST_P(pga_zadeh_test, csr6) {
    test_pga_on_csr_edmonds();
}

TEST_P(pga_zadeh_test, csr7) {
    test_pga_on_csr_max_weight();
}

TEST_P(pga_cube_test, csr) {
    pga_on_csr_random();
}

TEST_P(pga_cube_test, csr1) {
    pga_on_csr_hard();
}

TEST_P(pga_cube_test, csr2) {
    pga_on_csr_edmonds();
}

TEST_P(pga_cube_test, csr3) {
    pga_on_csr_max_weight();
}

TEST_P(pga_cube_test, csr4) {
    test_pga_on_csr_random();
}

TEST_P(pga_cube_test, csr5) {
    test_pga_on_csr_hard();
}

TEST_P(pga_cube_test, csr6) {
    test_pga_on_csr_edmonds();
}

TEST_P(pga_cube_test, csr7) {
    test_pga_on_csr_max_weight();
}

INSTANTIATE_TEST_SUITE_P(pga_test, pga_washington_test,
                    testing::ValuesIn(pga_washington_samples));

INSTANTIATE_TEST_SUITE_P(pga_test, pga_zadeh_test,
                    testing::ValuesIn(pga_zadeh_samples));

INSTANTIATE_TEST_SUITE_P(pga_test, pga_cube_test,
                    testing::ValuesIn(pga_cube_samples));
#endif  // TESTS_INCLUDE_PGA_PARAMETRIC_TEST_H_
