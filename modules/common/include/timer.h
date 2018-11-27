// Copyright [year] <Copyright Owner>
#ifndef MODULES_COMMON_INCLUDE_TIMER_H_
#define MODULES_COMMON_INCLUDE_TIMER_H_
#include <bits/stdc++.h>

namespace Timer {
    template <typename T, typename... Args>
    double calculate(T func, Args... args) {
        auto start = std::chrono::high_resolution_clock::now();
        func(args...);
        return std::chrono::duration_cast<std::chrono::duration<double>>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
}

#endif  // MODULES_COMMON_INCLUDE_TIMER_H_
