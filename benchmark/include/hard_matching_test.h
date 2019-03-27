// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_HARD_MATCHING_TEST_H_
#define BENCHMARK_INCLUDE_HARD_MATCHING_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "benchmark/benchmark.h"

void hard_matching_on_washington_test_csr(benchmark::State& state);
void hard_matching_on_zadeh_test_csr(benchmark::State& state);
void hard_matching_on_cube_test_csr(benchmark::State& state);

BENCHMARK(hard_matching_on_washington_test_csr)->Range(2, 1e6)->Complexity();
BENCHMARK(hard_matching_on_zadeh_test_csr)->Range(2, 1e3)->Complexity();
BENCHMARK(hard_matching_on_cube_test_csr)->Range(2, 50)->Complexity();

#endif  // BENCHMARK_INCLUDE_HARD_MATCHING_TEST_H_

