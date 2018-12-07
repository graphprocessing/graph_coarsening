// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_GENERATORS_TEST_H_
#define BENCHMARK_INCLUDE_GENERATORS_TEST_H_

#include <benchmark/benchmark.h>
#include "../../modules/algorithms/include/random_matching.h"
#include "../../modules/generators/include/washington_test.h"
#include "../../modules/generators/include/zadeh_test.h"
#include "../../modules/generators/include/cube_test.h"

void washington_test_creation_csr(benchmark::State& state);
void washington_test_creation_al(benchmark::State& state);
void zadeh_test_creation_csr(benchmark::State& state);
void zadeh_test_creation_al(benchmark::State& state);
void cube_test_creation_csr(benchmark::State& state);
void cube_test_creation_al(benchmark::State& state);

BENCHMARK(washington_test_creation_csr)->Range(2, 1e6)->Complexity();
BENCHMARK(washington_test_creation_al)->Range(2, 1e6)->Complexity();
BENCHMARK(zadeh_test_creation_csr)->Range(2, 1e3)->Complexity();
BENCHMARK(zadeh_test_creation_al)->Range(2, 1e3)->Complexity();
BENCHMARK(cube_test_creation_csr)->Range(2, 50)->Complexity();
BENCHMARK(cube_test_creation_al)->Range(2, 50)->Complexity();

#endif  // BENCHMARK_INCLUDE_GENERATORS_TEST_H_
