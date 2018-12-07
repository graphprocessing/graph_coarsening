// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_RANDOM_MATCHING_TEST_H_
#define BENCHMARK_INCLUDE_RANDOM_MATCHING_TEST_H_

#include <benchmark/benchmark.h>
#include "../../modules/algorithms/include/random_matching.h"
#include "../../modules/generators/include/washington_test.h"
#include "../../modules/generators/include/zadeh_test.h"
#include "../../modules/generators/include/cube_test.h"

void random_matching_on_washington_test_csr(benchmark::State& state);
void random_matching_on_washington_test_al(benchmark::State& state);
void random_matching_on_zadeh_test_csr(benchmark::State& state);
void random_matching_on_zadeh_test_al(benchmark::State& state);
void random_matching_on_cube_test_csr(benchmark::State& state);
void random_matching_on_cube_test_al(benchmark::State& state);

BENCHMARK(random_matching_on_washington_test_csr)->Range(2, 1e6)->Complexity();
BENCHMARK(random_matching_on_washington_test_al)->Range(2, 1e6)->Complexity();
BENCHMARK(random_matching_on_zadeh_test_csr)->Range(2, 1e3)->Complexity();
BENCHMARK(random_matching_on_zadeh_test_al)->Range(2, 1e3)->Complexity();
BENCHMARK(random_matching_on_cube_test_csr)->Range(2, 50)->Complexity();
BENCHMARK(random_matching_on_cube_test_al)->Range(2, 50)->Complexity();

#endif  // BENCHMARK_INCLUDE_RANDOM_MATCHING_TEST_H_
