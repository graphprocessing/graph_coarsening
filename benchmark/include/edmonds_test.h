// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_EDMONDS_TEST_H_
#define BENCHMARK_INCLUDE_EDMONDS_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "benchmark/benchmark.h"

void edmonds_on_washington_test_csr(benchmark::State& state);
void edmonds_on_zadeh_test_csr(benchmark::State& state);
void edmonds_on_cube_test_csr(benchmark::State& state);

BENCHMARK(edmonds_on_washington_test_csr)->Range(2, 5e3)->Complexity();
BENCHMARK(edmonds_on_zadeh_test_csr)->Range(2, 5e2)->Complexity();
BENCHMARK(edmonds_on_cube_test_csr)->Range(2, 32)->Complexity();

#endif  // BENCHMARK_INCLUDE_EDMONDS_TEST_H_
