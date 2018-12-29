// Copyright 2017 Nesterov Alexander
#ifndef BENCHMARK_INCLUDE_EXAMPLE_BENCHMARK_TEST_H_
#define BENCHMARK_INCLUDE_EXAMPLE_BENCHMARK_TEST_H_

#include <benchmark/benchmark.h>
#include "../../modules/pch/include/precomp.h"

void BM_StringCreation(benchmark::State& state);
BENCHMARK(BM_StringCreation);

void BM_StringCopy(benchmark::State& state);
BENCHMARK(BM_StringCopy);

void BM_StringCompare(benchmark::State& state);
BENCHMARK(BM_StringCompare)
    ->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

#endif  // BENCHMARK_INCLUDE_EXAMPLE_BENCHMARK_TEST_H_
