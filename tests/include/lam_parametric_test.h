// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_LAM_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_LAM_PARAMETRIC_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

class LAM_washington_test : public testing::TestWithParam<int> {
 public:
    LAM_washington_test() {
        value = GetParam();
    }

    void LAM_on_csr() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = LAM<int>(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j) {
                    if (csr.edges[j] != i) {
                        ASSERT_NE(0, used[csr.edges[j]]);
                    }
                }
            }
        }
    }

 private:
    int value;
};

class LAM_zadeh_test : public testing::TestWithParam<int> {
 public:
    LAM_zadeh_test() {
        value = GetParam();
    }

    void LAM_on_csr() {
        CSR<int> csr = zadeh_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = LAM<int>(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j) {
                    if (csr.edges[j] != i) {
                        ASSERT_NE(0, used[csr.edges[j]]);
                    }
                }
            }
        }
    }

 private:
    int value;
};

class LAM_cube_test : public testing::TestWithParam<int> {
 public:
    LAM_cube_test() {
        value = GetParam();
    }

    void LAM_on_csr() {
        CSR<int> csr = cube_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = LAM<int>(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j) {
                    if (csr.edges[j] != i) {
                        ASSERT_NE(0, used[csr.edges[j]]);
                    }
                }
            }
        }
    }

 private:
    int value;
};

class LAM_cycle_generator : public testing::TestWithParam<int> {
 public:
    LAM_cycle_generator() {
        value = GetParam();
    }

    void LAM_on_csr() {
        CSR<int> csr = cycle_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = LAM<int>(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j) {
                    if (csr.edges[j] != i) {
                        ASSERT_NE(0, used[csr.edges[j]]);
                    }
                }
            }
        }
    }

 private:
    int value;
};

class LAM_stars_generator : public testing::TestWithParam<int> {
 public:
    LAM_stars_generator() {
        value = GetParam();
    }

    void LAM_on_csr() {
        CSR<int> csr = stars_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = LAM<int>(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j) {
                    if (csr.edges[j] != i) {
                        ASSERT_NE(0, used[csr.edges[j]]);
                    }
                }
            }
        }
    }

 private:
    int value;
};

class LAM_chain_generator : public
                                testing::TestWithParam<std::pair <int, int>> {
 public:
    LAM_chain_generator() {
        value = GetParam();
    }

    void LAM_on_csr() {
        CSR<int> csr = chain_generator<int>(value.first, value.second);
        std::vector <char> used(csr.n, 0);
        auto matching = LAM<int>(csr);
        for (int i = 0; i < matching.n; ++i) {
            ++used[matching.edge_b[i]];
            ++used[matching.edge_e[i]];
        }
        for (int i = 0; i < csr.n; ++i)
            ASSERT_TRUE((used[i] == 0) || (used[i] == 1));
        for (int i = 0; i < csr.n; ++i) {
            if (!used[i]) {
                for (int j = csr.offset[i]; j < csr.offset[i+1]; ++j) {
                    if (csr.edges[j] != i) {
                        ASSERT_NE(0, used[csr.edges[j]]);
                    }
                }
            }
        }
    }

 private:
    std::pair <int, int> value;
};

std::vector <int> LAM_washington_samples = generate_samples(0, 100, 5);
std::vector <int> LAM_zadeh_samples = generate_samples(0, 50, 5);
std::vector <int> LAM_cube_samples = generate_samples(0, 10, 5);
std::vector <int> LAM_cycle_samples = generate_samples(0, 1000, 5);
std::vector <int> LAM_stars_samples = generate_samples(0, 200, 5);
std::vector <std::pair <int, int>> LAM_chain_samples =
                                            generate_pair_samples(0, 50, 5);

TEST_P(LAM_washington_test, csr) {
    LAM_on_csr();
}

TEST_P(LAM_zadeh_test, csr) {
    LAM_on_csr();
}

TEST_P(LAM_cube_test, csr) {
    LAM_on_csr();
}

TEST_P(LAM_cycle_generator, csr) {
    LAM_on_csr();
}

TEST_P(LAM_stars_generator, csr) {
    LAM_on_csr();
}

TEST_P(LAM_chain_generator, csr) {
    LAM_on_csr();
}

INSTANTIATE_TEST_SUITE_P(LAM_test, LAM_washington_test,
                    testing::ValuesIn(LAM_washington_samples));

INSTANTIATE_TEST_SUITE_P(LAM_test, LAM_zadeh_test,
                    testing::ValuesIn(LAM_zadeh_samples));

INSTANTIATE_TEST_SUITE_P(LAM_test, LAM_cube_test,
                    testing::ValuesIn(LAM_cube_samples));

INSTANTIATE_TEST_SUITE_P(LAM_test, LAM_cycle_generator,
                    testing::ValuesIn(LAM_cycle_samples));

INSTANTIATE_TEST_SUITE_P(LAM_test, LAM_stars_generator,
                    testing::ValuesIn(LAM_stars_samples));

INSTANTIATE_TEST_SUITE_P(LAM_test, LAM_chain_generator,
                    testing::ValuesIn(LAM_chain_samples));

#endif  // TESTS_INCLUDE_LAM_PARAMETRIC_TEST_H_
