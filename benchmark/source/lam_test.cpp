// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "../include/lam_test.h"

void lam_on_washington_test_csr(benchmark::State& state) {
    CSR <int> graph = washington_test<int>(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(LAM(graph));
    }
    unsigned m = graph.edges.size();
    state.SetComplexityN(m);
}

void lam_on_zadeh_test_csr(benchmark::State& state) {
    CSR <int> graph = zadeh_test<int>(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(LAM(graph));
    }
    unsigned m = graph.edges.size();
    state.SetComplexityN(m);
}

void lam_on_cube_test_csr(benchmark::State& state) {
    CSR <int> graph = cube_test<int>(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(LAM(graph));
    }
    unsigned m = graph.edges.size();
    state.SetComplexityN(m);
}
