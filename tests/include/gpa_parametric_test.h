// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_GPA_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_GPA_PARAMETRIC_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

class GPA_washington_test : public testing::TestWithParam<int> {
 public:
    GPA_washington_test() {
        value = GetParam();
    }

    void correct_GPA_hard_matching() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_random_matching() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_edmonds() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_max_weight_matching() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const AL<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

 private:
    int value;
};

class GPA_zadeh_test : public testing::TestWithParam<int> {
 public:
    GPA_zadeh_test() {
        value = GetParam();
    }

    void correct_GPA_hard_matching() {
        CSR<int> csr = zadeh_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_random_matching() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_edmonds() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_max_weight_matching() {
        CSR<int> csr = zadeh_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const AL<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

 private:
    int value;
};

class GPA_cube_test : public testing::TestWithParam<int> {
 public:
    GPA_cube_test() {
        value = GetParam();
    }

    void correct_GPA_hard_matching() {
        CSR<int> csr = cube_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_random_matching() {
        CSR<int> csr = cube_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_edmonds() {
        CSR<int> csr = cube_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_max_weight_matching() {
        CSR<int> csr = cube_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const AL<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

 private:
    int value;
};

class GPA_cycle_generator : public testing::TestWithParam<int> {
 public:
    GPA_cycle_generator() {
        value = GetParam();
    }

    void correct_GPA_hard_matching() {
        CSR<int> csr = cycle_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_random_matching() {
        CSR<int> csr = cycle_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_edmonds() {
        CSR<int> csr = cycle_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_max_weight_matching() {
        CSR<int> csr = cycle_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const AL<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

 private:
    int value;
};

class GPA_stars_generator : public testing::TestWithParam<int> {
 public:
    GPA_stars_generator() {
        value = GetParam();
    }

    void correct_GPA_hard_matching() {
        CSR<int> csr = stars_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_random_matching() {
        CSR<int> csr = stars_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_edmonds() {
        CSR<int> csr = stars_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_max_weight_matching() {
        CSR<int> csr = stars_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const AL<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

 private:
    int value;
};

class GPA_chain_generator :
                    public testing::TestWithParam<std::pair <int, int>> {
 public:
    GPA_chain_generator() {
        value = GetParam();
    }

    void correct_GPA_hard_matching() {
        CSR<int> csr = chain_generator<int>(value.first, value.second);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_random_matching() {
        CSR<int> csr = chain_generator<int>(value.first, value.second);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_edmonds() {
        CSR<int> csr = chain_generator<int>(value.first, value.second);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

    void correct_GPA_max_weight_matching() {
        CSR<int> csr = chain_generator<int>(value.first, value.second);
        std::vector <char> used(csr.n, 0);
        auto matching = GPA(csr, [](const AL<int>& graph) -> Matching {
            return max_weight_matching<int>(graph);
        });
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
    }

 private:
    std::pair <int, int> value;
};

std::vector <int> gpa_washington_samples = generate_samples(0, 100, 5);
std::vector <int> gpa_zadeh_samples = generate_samples(0, 50, 5);
std::vector <int> gpa_cube_samples = generate_samples(0, 10, 5);
std::vector <int> gpa_cycle_samples = generate_samples(0, 1000, 5);
std::vector <int> gpa_stars_samples = generate_samples(0, 200, 5);
std::vector <std::pair <int, int>> gpa_chain_samples =
                                            generate_pair_samples(0, 50, 5);

TEST_P(GPA_washington_test, hard_matching) {
    correct_GPA_hard_matching();
}

TEST_P(GPA_washington_test, random_matching) {
    correct_GPA_random_matching();
}

TEST_P(GPA_washington_test, edmonds) {
    correct_GPA_edmonds();
}

TEST_P(GPA_washington_test, max_weight_matching) {
    correct_GPA_max_weight_matching();
}

TEST_P(GPA_zadeh_test, hard_matching) {
    correct_GPA_hard_matching();
}

TEST_P(GPA_zadeh_test, random_matching) {
    correct_GPA_random_matching();
}

TEST_P(GPA_zadeh_test, edmonds) {
    correct_GPA_edmonds();
}

TEST_P(GPA_zadeh_test, max_weight_matching) {
    correct_GPA_max_weight_matching();
}

TEST_P(GPA_cube_test, hard_matching) {
    correct_GPA_hard_matching();
}

TEST_P(GPA_cube_test, random_matching) {
    correct_GPA_random_matching();
}

TEST_P(GPA_cube_test, edmonds) {
    correct_GPA_edmonds();
}

TEST_P(GPA_cube_test, max_weight_matching) {
    correct_GPA_max_weight_matching();
}

TEST_P(GPA_cycle_generator, hard_matching) {
    correct_GPA_hard_matching();
}

TEST_P(GPA_cycle_generator, random_matching) {
    correct_GPA_random_matching();
}

TEST_P(GPA_cycle_generator, edmonds) {
    correct_GPA_edmonds();
}

TEST_P(GPA_cycle_generator, max_weight_matching) {
    correct_GPA_max_weight_matching();
}

TEST_P(GPA_stars_generator, hard_matching) {
    correct_GPA_hard_matching();
}

TEST_P(GPA_stars_generator, random_matching) {
    correct_GPA_random_matching();
}

TEST_P(GPA_stars_generator, edmonds) {
    correct_GPA_edmonds();
}

TEST_P(GPA_stars_generator, max_weight_matching) {
    correct_GPA_max_weight_matching();
}

TEST_P(GPA_chain_generator, hard_matching) {
    correct_GPA_hard_matching();
}

TEST_P(GPA_chain_generator, random_matching) {
    correct_GPA_random_matching();
}

TEST_P(GPA_chain_generator, edmonds) {
    correct_GPA_edmonds();
}

TEST_P(GPA_chain_generator, max_weight_matching) {
    correct_GPA_max_weight_matching();
}

INSTANTIATE_TEST_SUITE_P(GPA_test1, GPA_washington_test,
                    testing::ValuesIn(gpa_washington_samples));

INSTANTIATE_TEST_SUITE_P(GPA_test2, GPA_zadeh_test,
                    testing::ValuesIn(gpa_zadeh_samples));

INSTANTIATE_TEST_SUITE_P(GPA_test3, GPA_cube_test,
                    testing::ValuesIn(gpa_cube_samples));

INSTANTIATE_TEST_SUITE_P(GPA_test4, GPA_cycle_generator,
                    testing::ValuesIn(gpa_cycle_samples));

INSTANTIATE_TEST_SUITE_P(GPA_test5, GPA_stars_generator,
                    testing::ValuesIn(gpa_stars_samples));

INSTANTIATE_TEST_SUITE_P(GPA_test6, GPA_chain_generator,
                    testing::ValuesIn(gpa_chain_samples));

#endif  // TESTS_INCLUDE_GPA_PARAMETRIC_TEST_H_
