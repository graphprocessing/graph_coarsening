// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_PGA_TEST_H_
#define BENCHMARK_INCLUDE_PGA_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "benchmark/benchmark.h"

void pga_on_washington_test_csr(benchmark::State& state);
void pga_on_zadeh_test_csr(benchmark::State& state);
void pga_on_cube_test_csr(benchmark::State& state);

BENCHMARK(pga_on_washington_test_csr)->Range(2, 1e3)->Complexity();
BENCHMARK(pga_on_zadeh_test_csr)->Range(2, 1e2)->Complexity();
BENCHMARK(pga_on_cube_test_csr)->Range(2, 40)->Complexity();

#endif  // BENCHMARK_INCLUDE_PGA_TEST_H_
