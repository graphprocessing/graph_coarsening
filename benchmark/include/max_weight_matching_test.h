// Copyright [year] <Copyright Owner>
#ifndef BENCHMARK_INCLUDE_MAX_WEIGHT_MATCHING_TEST_H_
#define BENCHMARK_INCLUDE_MAX_WEIGHT_MATCHING_TEST_H_
#include "../../modules/pch/include/precomp.h"
#include "benchmark/benchmark.h"

void max_weight_matching_on_cycle_generator_csr(benchmark::State& state);

BENCHMARK(max_weight_matching_on_cycle_generator_csr)->
            Range(2, 1e6)->Complexity();

#endif  // BENCHMARK_INCLUDE_MAX_WEIGHT_MATCHING_TEST_H_
