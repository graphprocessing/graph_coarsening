// Copyright [year] <Copyright Owner>
#include "../../modules/pch/include/precomp.h"
#include "../include/generators_test.h"

void washington_test_creation_csr(benchmark::State& state) {
    while (state.KeepRunning()) {
        auto fu = [&]() {
            CSR csr = washington_test(state.range(0));
            return csr;
        };
        benchmark::DoNotOptimize(fu());
    }
    state.SetComplexityN(3 * state.range(0) + 3);
}

void washington_test_creation_al(benchmark::State& state) {
    while (state.KeepRunning()) {
        auto fu = [&]() {
            AL al = washington_test(state.range(0));
            return al;
        };
        benchmark::DoNotOptimize(fu());
    }
    state.SetComplexityN(state.range(0) + 3);
}

void zadeh_test_creation_csr(benchmark::State& state) {
    while (state.KeepRunning()) {
        auto fu = [&]() {
            CSR csr = zadeh_test(state.range(0));
            return csr;
        };
        benchmark::DoNotOptimize(fu());
    }
    state.SetComplexityN(6 * state.range(0));
}

void zadeh_test_creation_al(benchmark::State& state) {
    while (state.KeepRunning()) {
        auto fu = [&]() {
            AL al = zadeh_test(state.range(0));
            return al;
        };
        benchmark::DoNotOptimize(fu());
    }
    state.SetComplexityN(6 * state.range(0));
}

void cube_test_creation_csr(benchmark::State& state) {
    while (state.KeepRunning()) {
        auto fu = [&]() {
            CSR csr = cube_test(state.range(0));
            return csr;
        };
        benchmark::DoNotOptimize(fu());
    }
    state.SetComplexityN(state.range(0) * state.range(0) * state.range(0));
}

void cube_test_creation_al(benchmark::State& state) {
    while (state.KeepRunning()) {
        auto fu = [&]() {
            AL al = cube_test(state.range(0));
            return al;
        };
        benchmark::DoNotOptimize(fu());
    }
    state.SetComplexityN(state.range(0) * state.range(0) * state.range(0));
}
