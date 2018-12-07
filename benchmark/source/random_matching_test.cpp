// Copyright [year] <Copyright Owner>
#include "../include/random_matching_test.h"

void random_matching_on_washington_test_csr(benchmark::State& state) {
    CSR graph = washington_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    state.SetComplexityN(3 * state.range(0) + 3);
}

void random_matching_on_washington_test_al(benchmark::State& state) {
    AL graph = washington_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    state.SetComplexityN(3 * state.range(0) + 3);
}

void random_matching_on_zadeh_test_csr(benchmark::State& state) {
    CSR graph = zadeh_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    state.SetComplexityN(6 * state.range(0));
}

void random_matching_on_zadeh_test_al(benchmark::State& state) {
    AL graph = zadeh_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    state.SetComplexityN(6 * state.range(0));
}

void random_matching_on_cube_test_csr(benchmark::State& state) {
    CSR graph = cube_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    state.SetComplexityN(state.range(0) * state.range(0) * state.range(0));
}

void random_matching_on_cube_test_al(benchmark::State& state) {
    AL graph = cube_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    state.SetComplexityN(state.range(0) * state.range(0) * state.range(0));
}
