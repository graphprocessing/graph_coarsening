// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_EDMONDS_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_EDMONDS_PARAMETRIC_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

class edmonds_washington_test : public testing::TestWithParam<int> {
 public:
    edmonds_washington_test() {
        value = GetParam();
    }

    void edmonds_on_csr() {
        CSR<int> csr = washington_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = edmonds<int>(csr);
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

class edmonds_zadeh_test : public testing::TestWithParam<int> {
 public:
    edmonds_zadeh_test() {
        value = GetParam();
    }

    void edmonds_on_csr() {
        CSR<int> csr = zadeh_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = edmonds<int>(csr);
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

class edmonds_cube_test : public testing::TestWithParam<int> {
 public:
    edmonds_cube_test() {
        value = GetParam();
    }

    void edmonds_on_csr() {
        CSR<int> csr = cube_test<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = edmonds<int>(csr);
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

class edmonds_cycle_generator : public testing::TestWithParam<int> {
 public:
    edmonds_cycle_generator() {
        value = GetParam();
    }

    void edmonds_on_csr() {
        CSR<int> csr = cycle_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = edmonds<int>(csr);
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

class edmonds_stars_generator : public testing::TestWithParam<int> {
 public:
    edmonds_stars_generator() {
        value = GetParam();
    }

    void edmonds_on_csr() {
        CSR<int> csr = stars_generator<int>(value);
        std::vector <char> used(csr.n, 0);
        auto matching = edmonds<int>(csr);
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

class edmonds_chain_generator : public
                                testing::TestWithParam<std::pair <int, int>> {
 public:
    edmonds_chain_generator() {
        value = GetParam();
    }

    void edmonds_on_csr() {
        CSR<int> csr = chain_generator<int>(value.first, value.second);
        std::vector <char> used(csr.n, 0);
        auto matching = edmonds<int>(csr);
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

std::vector <int> edmonds_washington_samples = generate_samples(0, 100, 5);
std::vector <int> edmonds_zadeh_samples = generate_samples(0, 50, 5);
std::vector <int> edmonds_cube_samples = generate_samples(0, 10, 5);
std::vector <int> edmonds_cycle_samples = generate_samples(0, 1000, 5);
std::vector <int> edmonds_stars_samples = generate_samples(0, 200, 5);
std::vector <std::pair <int, int>> edmonds_chain_samples =
                                            generate_pair_samples(0, 50, 5);

TEST_P(edmonds_washington_test, csr) {
    edmonds_on_csr();
}

TEST_P(edmonds_zadeh_test, csr) {
    edmonds_on_csr();
}

TEST_P(edmonds_cube_test, csr) {
    edmonds_on_csr();
}

TEST_P(edmonds_cycle_generator, csr) {
    edmonds_on_csr();
}

TEST_P(edmonds_stars_generator, csr) {
    edmonds_on_csr();
}

TEST_P(edmonds_chain_generator, csr) {
    edmonds_on_csr();
}

INSTANTIATE_TEST_SUITE_P(edmonds_test, edmonds_washington_test,
                    testing::ValuesIn(edmonds_washington_samples));

INSTANTIATE_TEST_SUITE_P(edmonds_test, edmonds_zadeh_test,
                    testing::ValuesIn(edmonds_zadeh_samples));

INSTANTIATE_TEST_SUITE_P(edmonds_test, edmonds_cube_test,
                    testing::ValuesIn(edmonds_cube_samples));

INSTANTIATE_TEST_SUITE_P(edmonds_test, edmonds_cycle_generator,
                    testing::ValuesIn(edmonds_cycle_samples));

INSTANTIATE_TEST_SUITE_P(edmonds_test, edmonds_stars_generator,
                    testing::ValuesIn(edmonds_stars_samples));

INSTANTIATE_TEST_SUITE_P(edmonds_test, edmonds_chain_generator,
                    testing::ValuesIn(edmonds_chain_samples));

#endif  // TESTS_INCLUDE_EDMONDS_PARAMETRIC_TEST_H_
