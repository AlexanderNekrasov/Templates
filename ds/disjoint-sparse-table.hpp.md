---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/disjoint-sparse-table.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ T, typename F>\nstruct DisjointSparseTable {\n    int n;\n    std::vector<std::vector<T>>\
    \ table;\n    static constexpr F f = {};\n\n    DisjointSparseTable() {}\n   \
    \ DisjointSparseTable(const std::vector<T> &arr) {\n        n = arr.size();\n\
    \        int b = 1;\n        while ((1 << b) <= n) {\n            ++b;\n     \
    \   }\n        table.push_back(arr);\n        table.back().resize(1 << b);\n \
    \       for (int sz = 2; sz < n; sz *= 2) {\n            table.push_back(std::vector<T>\
    \ (1 << b));\n            for (int mid = sz; mid < (1 << b); mid += 2 * sz) {\n\
    \                table.back()[mid - 1] = table[0][mid - 1];\n                table.back()[mid]\
    \ = table[0][mid];\n                for (int i = 1; i < sz; ++i) {\n         \
    \           table.back()[mid - 1 - i] = f(table[0][mid - 1 - i], table.back()[mid\
    \ - i]);\n                    table.back()[mid + i] = f(table.back()[mid + i -\
    \ 1], table[0][mid + i]);\n                }\n            }\n        }\n    }\n\
    \n    T get(int l, int r) {\n        assert(0 <= l && l < r && r <= n);\n    \
    \    r--;\n        if (l == r) {\n            return table[0][l];\n        }\n\
    \        int lg = 31 - __builtin_clz(r ^ l);\n        return f(table[lg][l], table[lg][r]);\n\
    \    }\n};\n\n\n"
  code: "#pragma once\n#include <vector>\n\ntemplate<typename T, typename F>\nstruct\
    \ DisjointSparseTable {\n    int n;\n    std::vector<std::vector<T>> table;\n\
    \    static constexpr F f = {};\n\n    DisjointSparseTable() {}\n    DisjointSparseTable(const\
    \ std::vector<T> &arr) {\n        n = arr.size();\n        int b = 1;\n      \
    \  while ((1 << b) <= n) {\n            ++b;\n        }\n        table.push_back(arr);\n\
    \        table.back().resize(1 << b);\n        for (int sz = 2; sz < n; sz *=\
    \ 2) {\n            table.push_back(std::vector<T> (1 << b));\n            for\
    \ (int mid = sz; mid < (1 << b); mid += 2 * sz) {\n                table.back()[mid\
    \ - 1] = table[0][mid - 1];\n                table.back()[mid] = table[0][mid];\n\
    \                for (int i = 1; i < sz; ++i) {\n                    table.back()[mid\
    \ - 1 - i] = f(table[0][mid - 1 - i], table.back()[mid - i]);\n              \
    \      table.back()[mid + i] = f(table.back()[mid + i - 1], table[0][mid + i]);\n\
    \                }\n            }\n        }\n    }\n\n    T get(int l, int r)\
    \ {\n        assert(0 <= l && l < r && r <= n);\n        r--;\n        if (l ==\
    \ r) {\n            return table[0][l];\n        }\n        int lg = 31 - __builtin_clz(r\
    \ ^ l);\n        return f(table[lg][l], table[lg][r]);\n    }\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/disjoint-sparse-table.hpp
  requiredBy: []
  timestamp: '2023-02-25 13:28:05+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/disjoint-sparse-table.hpp
layout: document
redirect_from:
- /library/ds/disjoint-sparse-table.hpp
- /library/ds/disjoint-sparse-table.hpp.html
title: ds/disjoint-sparse-table.hpp
---
