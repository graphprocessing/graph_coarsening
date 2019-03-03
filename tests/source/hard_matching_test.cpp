// Copyright [year] <Copyright Owner>
#include <gtest/gtest.h>
#include "../../modules/pch/include/precomp.h"


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
            int to = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
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
            int to = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
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
            int to = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
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
            int to = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
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
            int to = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
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
            int to = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
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
            int to = graph.edges[j];
            int len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
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
            int to = graph.edges[j];
            double len = graph.weights[j];
            if (len > maxlen && !used[to]) {
                maxlen = len;
                b = to;
            }
        }
        used[b] = true;
        expect.edge_b.push_back(b);
    }
    EXPECT_EQ(matching.edge_b, expect.edge_b);
}
