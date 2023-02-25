#pragma once
#include <vector>

template<typename T, typename F>
struct DisjointSparseTable {
    int n;
    std::vector<std::vector<T>> table;
    static constexpr F f = {};

    DisjointSparseTable() {}
    DisjointSparseTable(const std::vector<T> &arr) {
        n = arr.size();
        int b = 1;
        while ((1 << b) <= n) {
            ++b;
        }
        table.push_back(arr);
        table.back().resize(1 << b);
        for (int sz = 2; sz < n; sz *= 2) {
            table.push_back(std::vector<T> (1 << b));
            for (int mid = sz; mid < (1 << b); mid += 2 * sz) {
                table.back()[mid - 1] = table[0][mid - 1];
                table.back()[mid] = table[0][mid];
                for (int i = 1; i < sz; ++i) {
                    table.back()[mid - 1 - i] = f(table[0][mid - 1 - i], table.back()[mid - i]);
                    table.back()[mid + i] = f(table.back()[mid + i - 1], table[0][mid + i]);
                }
            }
        }
    }

    T get(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        r--;
        if (l == r) {
            return table[0][l];
        }
        int lg = 31 - __builtin_clz(r ^ l);
        return f(table[lg][l], table[lg][r]);
    }
};


