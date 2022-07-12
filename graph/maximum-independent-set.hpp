#pragma once

#include "graph-template.hpp"

vector<int> maximumIndependentSet(const UnweightedGraph &g) {
    assert(sz(g) <= 64);
    int n = sz(g);
    vector<ull> gb(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            gb[i] |= 1ULL << j;
        }
        gb[i] |= 1ULL << i;
        gb[i] ^= ULLONG_MAX;
    }
    int k = (n + 1) / 2;
    unordered_map<ull, ull> memo;
    //vector<ull> memo(1ULL << k, ULLONG_MAX);
    auto rec = [&](auto rec, ull mask, int bit) -> ull {
        if (mask == 0)
            return 0;
        if (mask < (1ULL << k) && memo.find(mask) != memo.end()) {
            return memo[mask]; 
        }
        if (mask & (1ULL << bit)) {
            auto ans1 = rec(rec, mask ^ (1ULL << bit), bit - 1);
            auto ans2 = rec(rec, mask & gb[bit], bit - 1) | (1ULL << bit);
            if (__builtin_popcountll(ans1) < __builtin_popcountll(ans2)) {
                ans1 = ans2;
            }
            if (mask < (1ULL << k)) {
                memo[mask] = ans1;
            }
            return ans1;
        } else {
            return rec(rec, mask, bit - 1);
        }
    };
    auto ans = rec(rec, (1ULL << n) - 1, n - 1);
    vector<int> ans2;
    for (int i = 0; i < n; i++) {
        if (ans & (1ULL << i)) {
            ans2.push_back(i);
        }
    }
    return ans2;
}
