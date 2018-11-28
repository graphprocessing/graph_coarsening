// Copyright [year] <Copyright Owner>
#include <string>
#include <algorithm>
#include "../include/example_benchmark_test.h"

void BM_StringCreation(benchmark::State& state) {
    for (auto _ : state)
      std::string empty_string;
}

void BM_StringCopy(benchmark::State& state) {
    std::string x = "hello";
    for (auto _ : state)
      std::string copy(x);
}

void BM_StringCompare(benchmark::State& state) {
    std::string s1(state.range(0), '-');
    std::string s2(state.range(0), '-');
    for (auto _ : state) {
      benchmark::DoNotOptimize(s1.compare(s2));
    }
    state.SetComplexityN(state.range(0));
}
