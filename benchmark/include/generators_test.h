// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_GENERATORS_TEST_H_
#define BENCHMARK_INCLUDE_GENERATORS_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "benchmark/benchmark.h"

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
