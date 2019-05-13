// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "../include/random_matching_test.h"

void max_weight_matching_on_cycle_generator_csr(benchmark::State& state) {
    CSR <int> graph = cycle_generator<int>(state.range(0));
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(max_weight_matching<int>(graph));
    }
    unsigned m = graph.edges.size();
    state.SetComplexityN(m);
}
