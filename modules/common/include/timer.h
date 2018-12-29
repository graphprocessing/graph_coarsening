// Copyright [year] <Copyright Owner>
#ifndef MODULES_COMMON_INCLUDE_TIMER_H_
#define MODULES_COMMON_INCLUDE_TIMER_H_
#include "../../pch/include/precomp.h"

namespace Timer {
    template <typename T, typename... Args>
    double calculate(T func, Args... args) {
        double start = omp_get_wtime();
        func(args...);
        return omp_get_wtime() - start;
    }
}

#endif  // MODULES_COMMON_INCLUDE_TIMER_H_
