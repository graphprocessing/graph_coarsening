// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_GPA_TEST_H_
#define BENCHMARK_INCLUDE_GPA_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "benchmark/benchmark.h"

void gpa_on_washington_test_csr(benchmark::State& state);
void gpa_on_zadeh_test_csr(benchmark::State& state);
void gpa_on_cube_test_csr(benchmark::State& state);

BENCHMARK(gpa_on_washington_test_csr)->Range(2, 1e4)->Complexity();
BENCHMARK(gpa_on_zadeh_test_csr)->Range(2, 2e2)->Complexity();
BENCHMARK(gpa_on_cube_test_csr)->Range(2, 40)->Complexity();

#endif  // BENCHMARK_INCLUDE_GPA_TEST_H_
