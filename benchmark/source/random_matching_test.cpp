// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "../include/random_matching_test.h"

void random_matching_on_washington_test_csr(benchmark::State& state) {
    CSR graph = washington_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    unsigned m = graph.edges.size();
    state.SetComplexityN(m);
}

void random_matching_on_washington_test_al(benchmark::State& state) {
    AL graph = washington_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    int m = 0;
    for (unsigned i = 0; i < graph.edges.size(); ++i)
        for (unsigned j = 0; j < graph.edges[i].size(); ++j)
            ++m;
    state.SetComplexityN(m);
}

void random_matching_on_zadeh_test_csr(benchmark::State& state) {
    CSR graph = zadeh_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    unsigned m = graph.edges.size();
    state.SetComplexityN(m);
}

void random_matching_on_zadeh_test_al(benchmark::State& state) {
    AL graph = zadeh_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    int m = 0;
    for (unsigned i = 0; i < graph.edges.size(); ++i)
        for (unsigned j = 0; j < graph.edges[i].size(); ++j)
            ++m;
    state.SetComplexityN(m);
}

void random_matching_on_cube_test_csr(benchmark::State& state) {
    CSR graph = cube_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    unsigned m = graph.edges.size();
    state.SetComplexityN(m);
}

void random_matching_on_cube_test_al(benchmark::State& state) {
    AL graph = cube_test(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(random_matching(graph));
    }
    int m = 0;
    for (unsigned i = 0; i < graph.edges.size(); ++i)
        for (unsigned j = 0; j < graph.edges[i].size(); ++j)
            ++m;
    state.SetComplexityN(m);
}
