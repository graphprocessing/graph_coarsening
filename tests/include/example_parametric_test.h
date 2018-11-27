// Copyright 2017 Nesterov Alexander
#ifndef TESTS_INCLUDE_EXAMPLE_PARAMETRIC_TEST_H_
#define TESTS_INCLUDE_EXAMPLE_PARAMETRIC_TEST_H_

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../../modules/data_structures/include/graph.h"


class ExampleParametricTest : public testing::TestWithParam<std::string> {
 public:
    ExampleParametricTest() {
        graph = GetParam();
    }

    void doTest_1() {
        EXPECT_GT(graph.size(), static_cast<unsigned>(0));
    }

    void doTest_2() {
        EXPECT_GT(graph.size(), static_cast<unsigned>(1));
    }

    void doTest_3() {
        EXPECT_GT(graph.size(), static_cast<unsigned>(2));
    }

 private:
    std::string graph;
};

std::vector<std::string> graph_sample = {
    std::string("earth"),
    std::string("princeton"),
    std::string("topcoder"),
};

TEST_P(ExampleParametricTest, Test_1) { doTest_1(); }
TEST_P(ExampleParametricTest, Test_2) { doTest_2(); }
TEST_P(ExampleParametricTest, Test_3) { doTest_3(); }

INSTANTIATE_TEST_CASE_P(example, ExampleParametricTest,
                            testing::ValuesIn(graph_sample));

#endif  // TESTS_INCLUDE_EXAMPLE_PARAMETRIC_TEST_H_
