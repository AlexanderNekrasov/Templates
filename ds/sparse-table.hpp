#pragma once
#include <functional>
#include <vector>

template<typename T, typename Cmp=std::less<>>
struct SparseTable {
    int n;
    std::vector<std::vector<T>> table;
    Cmp cmp;

    inline T f(T a, T b) {
        return std::min(a, b, cmp);
    }
    SparseTable() {}
    SparseTable(const std::vector<T> &arr, Cmp cmp_ = Cmp()) : n(arr.size()), cmp(cmp_) {
        int b = 1;
        while ((1 << b) <= n) {
            ++b;
        }
        table.push_back(arr);
        for (int i = 1; i < b; ++i) {
            table.push_back(table.back());
            for (int j = 0; j + (1 << i) <= n; ++j) {
                table[i][j] = f(table[i][j], table[i][j + (1 << (i - 1))]);
            }
        }
    }

    // [l, r)
    T get(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        int b = 31 - __builtin_clz(r - l);
        return f(table[b][l], table[b][r - (1 << b)]);
    }

};
