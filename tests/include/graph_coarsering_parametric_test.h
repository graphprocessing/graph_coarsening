// Copyright [year] <Copyright Owner>
#ifndef TESTS_INCLUDE_GRAPH_COARSERING_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_GRAPH_COARSERING_PARAMETRIC_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "gtest/gtest.h"

class GC_washington_test: public testing::TestWithParam<int> {
 public:
    GC_washington_test() {
        value = GetParam();
    }

    void correct_GC_hard_matching() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
            return hard_matching<int>(graph);
        });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_random_matching() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
            return random_matching<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_edmonds() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
            return edmonds<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_PGA() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return PGA<int>(graph,
                    [](const CSR<int>& graph) -> Matching {
                        return random_matching<int>(graph);
                    });
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_GPA() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
            return GPA<int>(graph,
                [](const CSR<int>& graph) -> Matching {
                    return random_matching<int>(graph);
                });
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_LAM() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return LAM<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

 private:
    int value;
};

class GC_zadeh_test: public testing::TestWithParam<int> {
 public:
    GC_zadeh_test() {
        value = GetParam();
    }

    void correct_GC_hard_matching() {
        CSR<int> graph1 = zadeh_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return hard_matching<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_random_matching() {
        CSR<int> graph1 = zadeh_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return random_matching<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_edmonds() {
        CSR<int> graph1 = zadeh_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return edmonds<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_PGA() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return PGA<int>(graph,
                    [](const CSR<int>& graph) -> Matching {
                        return random_matching<int>(graph);
                    });
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_GPA() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
            return GPA<int>(graph,
                [](const CSR<int>& graph) -> Matching {
                    return random_matching<int>(graph);
                });
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_LAM() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return LAM<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

 private:
    int value;
};

class GC_cube_test: public testing::TestWithParam<int> {
 public:
    GC_cube_test() {
        value = GetParam();
    }

    void correct_GC_hard_matching() {
        CSR<int> graph1 = cube_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return hard_matching<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_random_matching() {
        CSR<int> graph1 = cube_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return random_matching<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_edmonds() {
        CSR<int> graph1 = cube_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return edmonds<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_PGA() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return PGA<int>(graph,
                    [](const CSR<int>& graph) -> Matching {
                        return random_matching<int>(graph);
                    });
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_GPA() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
            return GPA<int>(graph,
                [](const CSR<int>& graph) -> Matching {
                    return random_matching<int>(graph);
                });
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

    void correct_GC_LAM() {
        CSR<int> graph1 = washington_test<int>(value);
        int size = graph1.edges.size();
        CSR<int> graph = graph_coarsening(graph1,
            [](const CSR<int>& graph) -> Matching {
                return LAM<int>(graph);
            });
        int size1 = graph.edges.size();
        EXPECT_EQ(true, size > size1);
    }

 private:
    int value;
};

std::vector <int> gc_washington_samples = generate_samples(1, 100, 5);
std::vector <int> gc_zadeh_samples = generate_samples(1, 50, 5);
std::vector <int> gc_cube_samples = generate_samples(2, 10, 5);

TEST_P(GC_washington_test, hard_matching) {
    correct_GC_hard_matching();
}

TEST_P(GC_washington_test, random_matching) {
    correct_GC_random_matching();
}

TEST_P(GC_washington_test, edmonds) {
    correct_GC_edmonds();
}

TEST_P(GC_washington_test, PGA) {
    correct_GC_PGA();
}

TEST_P(GC_washington_test, GPA) {
    correct_GC_GPA();
}

TEST_P(GC_washington_test, LAM) {
    correct_GC_LAM();
}

TEST_P(GC_zadeh_test, hard_matching) {
    correct_GC_hard_matching();
}

TEST_P(GC_zadeh_test, random_matching) {
    correct_GC_random_matching();
}

TEST_P(GC_zadeh_test, edmonds) {
    correct_GC_edmonds();
}

TEST_P(GC_zadeh_test, PGA) {
    correct_GC_PGA();
}

TEST_P(GC_zadeh_test, GPA) {
    correct_GC_GPA();
}

TEST_P(GC_zadeh_test, LAM) {
    correct_GC_LAM();
}

TEST_P(GC_cube_test, hard_matching) {
    correct_GC_hard_matching();
}

TEST_P(GC_cube_test, random_matching) {
    correct_GC_random_matching();
}

TEST_P(GC_cube_test, edmonds) {
    correct_GC_edmonds();
}

TEST_P(GC_cube_test, PGA) {
    correct_GC_PGA();
}

TEST_P(GC_cube_test, GPA) {
    correct_GC_GPA();
}

TEST_P(GC_cube_test, LAM) {
    correct_GC_LAM();
}

INSTANTIATE_TEST_SUITE_P(GC_test1, GC_washington_test,
                         testing::ValuesIn(gc_washington_samples));

INSTANTIATE_TEST_SUITE_P(GC_test2, GC_zadeh_test,
                         testing::ValuesIn(gc_zadeh_samples));

INSTANTIATE_TEST_SUITE_P(GC_test3, GC_cube_test,
                         testing::ValuesIn(gc_cube_samples));

#endif  // TESTS_INCLUDE_GRAPH_COARSERING_PARAMETRIC_TEST_H_
