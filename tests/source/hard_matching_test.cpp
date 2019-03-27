// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

TEST(hard_matching_test, basic_washington_test_csr_2_int) {
    CSR<int> graph = washington_test<int>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0, b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_washington_test_al_2_int) {
    AL<int> graph = washington_test<int>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0, b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            int len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_washington_test_csr_2_double) {
    CSR<double> graph = washington_test<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_washington_test_al_2_double) {
    AL<double> graph = washington_test<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_washington_test_csr_1_int) {
    CSR<int> graph = washington_test<int>(1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    for (unsigned i = 0; i < matching.edge_b.size(); i++) {
        expect.edge_e.push_back(matching.edge_e[i]);
        expect.edge_b.push_back(matching.edge_e[i] + 1);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
    EXPECT_EQ(matching.edge_e, expect.edge_e);
}

TEST(hard_matching_test, basic_washington_test_al_1_int) {
    AL<int> graph = washington_test<int>(1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    for (unsigned i = 0; i < matching.edge_b.size(); i++) {
        expect.edge_e.push_back(matching.edge_e[i]);
        expect.edge_b.push_back(matching.edge_e[i] + 1);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
    EXPECT_EQ(matching.edge_e, expect.edge_e);
}


TEST(hard_matching_test, basic_washington_test_csr_1_double) {
    CSR<double> graph = washington_test<double>(1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    for (unsigned i = 0; i < matching.edge_b.size(); i++) {
        expect.edge_e.push_back(matching.edge_e[i]);
        expect.edge_b.push_back(matching.edge_e[i] + 1);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
    EXPECT_EQ(matching.edge_e, expect.edge_e);
}

TEST(hard_matching_test, basic_washington_test_al_1_double) {
    AL<double> graph = washington_test<double>(1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    for (unsigned i = 0; i < matching.edge_b.size(); i++) {
        expect.edge_e.push_back(matching.edge_e[i]);
        expect.edge_b.push_back(matching.edge_e[i] + 1);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
    EXPECT_EQ(matching.edge_e, expect.edge_e);
}

TEST(hard_matching_test, basic_washington_test_csr_4_int) {
    CSR<int> graph = washington_test<int>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0, b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_washington_test_al_4_int) {
    AL<int> graph = washington_test<int>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0, b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            int len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_washington_test_csr_4_double) {
    CSR<double> graph = washington_test<double>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_washington_test_al_4_double) {
    AL<double> graph = washington_test<double>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_zadeh_test_csr_2_int) {
    CSR<int> graph = zadeh_test<int>(1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_zadeh_test_al_2_int) {
    AL<int> graph = zadeh_test<int>(1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_zadeh_test_csr_2_double) {
    CSR<double> graph = zadeh_test<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_zadeh_test_al_2_double) {
    AL<double> graph = zadeh_test<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}


TEST(hard_matching_test, basic_zadeh_test_csr_4_int) {
    CSR<int> graph = zadeh_test<int>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0, b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_zadeh_test_al_4_int) {
    AL<int> graph = zadeh_test<int>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0, b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            int len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_zadeh_test_csr_4_double) {
    CSR<double> graph = zadeh_test<double>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_zadeh_test_al_4_double) {
    AL<double> graph = zadeh_test<double>(4, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_stars_generator_csr_2_int) {
    CSR <int> graph = stars_generator<int>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_stars_generator_csr_2_double) {
    CSR <double> graph = stars_generator<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_stars_generator_al_2_int) {
    AL <int> graph = stars_generator<int>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            int len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_stars_generator_al_2_double) {
    AL <double> graph = stars_generator<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_cycle_generator_csr_2_int) {
    CSR <int> graph = cycle_generator<int>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_cycle_generator_csr_2_double) {
    CSR <double> graph = cycle_generator<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_cycle_generator_al_2_int) {
    AL <int> graph = cycle_generator<int>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            int len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_cycle_generator_al_2_double) {
    AL <double> graph = cycle_generator<double>(2, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_chain_generator_csr_2_int) {
    CSR <int> graph = chain_generator<int>(2, 1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_chain_generator_csr_2_double) {
    CSR <double> graph = chain_generator<double>(2, 1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (int j = graph.offset[to]; j < graph.offset[to + 1]; j++) {
            int to1 = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_chain_generator_al_2_int) {
    AL <int> graph = chain_generator<int>(2, 1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        int maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            int len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

TEST(hard_matching_test, basic_chain_generatorr_al_2_double) {
    AL <double> graph = chain_generator<double>(2, 1, true);
    Matching matching = hard_matching(graph);
    Matching expect;
    std::vector <char> used;
    used.resize(graph.n);
    for (unsigned i = 0; i < matching.edge_e.size(); i++) {
        int to = matching.edge_e[i];
        expect.edge_e.push_back(to);
        double maxlen = 0;
        int b = -1;
        used[to] = true;
        for (unsigned j = 0; j < graph.edges[to].size(); j++) {
            int to1 = graph.edges[to][j];
            double len = graph.weights[to][j];
            if (len > maxlen && !used[to1]) {
                maxlen = len;
                b = to1;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}

