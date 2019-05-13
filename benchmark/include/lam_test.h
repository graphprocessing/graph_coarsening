// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_LAM_TEST_H_
#define BENCHMARK_INCLUDE_LAM_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "benchmark/benchmark.h"

void lam_on_washington_test_csr(benchmark::State& state);
void lam_on_zadeh_test_csr(benchmark::State& state);
void lam_on_cube_test_csr(benchmark::State& state);

BENCHMARK(lam_on_washington_test_csr)->Range(2, 1e4)->Complexity();
BENCHMARK(lam_on_zadeh_test_csr)->Range(2, 5e2)->Complexity();
BENCHMARK(lam_on_cube_test_csr)->Range(2, 50)->Complexity();

#endif  // BENCHMARK_INCLUDE_LAM_TEST_H_
