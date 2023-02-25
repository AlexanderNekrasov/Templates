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
  bundledCode: "#line 2 \"ds/sparse-table.hpp\"\n#include <functional>\n#include <vector>\n\
    \ntemplate<typename T, typename Cmp=std::less<>>\nstruct SparseTable {\n    int\
    \ n;\n    std::vector<std::vector<T>> table;\n    Cmp cmp;\n\n    inline T f(T\
    \ a, T b) {\n        return std::min(a, b, cmp);\n    }\n    SparseTable() {}\n\
    \    SparseTable(const std::vector<T> &arr, Cmp cmp_ = Cmp()) : n(arr.size()),\
    \ cmp(cmp_) {\n        int b = 1;\n        while ((1 << b) <= n) {\n         \
    \   ++b;\n        }\n        table.push_back(arr);\n        for (int i = 1; i\
    \ < b; ++i) {\n            table.push_back(table.back());\n            for (int\
    \ j = 0; j + (1 << i) <= n; ++j) {\n                table[i][j] = f(table[i][j],\
    \ table[i][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    // [l,\
    \ r)\n    T get(int l, int r) {\n        assert(0 <= l && l < r && r <= n);\n\
    \        int b = 31 - __builtin_clz(r - l);\n        return f(table[b][l], table[b][r\
    \ - (1 << b)]);\n    }\n\n};\n"
  code: "#pragma once\n#include <functional>\n#include <vector>\n\ntemplate<typename\
    \ T, typename Cmp=std::less<>>\nstruct SparseTable {\n    int n;\n    std::vector<std::vector<T>>\
    \ table;\n    Cmp cmp;\n\n    inline T f(T a, T b) {\n        return std::min(a,\
    \ b, cmp);\n    }\n    SparseTable() {}\n    SparseTable(const std::vector<T>\
    \ &arr, Cmp cmp_ = Cmp()) : n(arr.size()), cmp(cmp_) {\n        int b = 1;\n \
    \       while ((1 << b) <= n) {\n            ++b;\n        }\n        table.push_back(arr);\n\
    \        for (int i = 1; i < b; ++i) {\n            table.push_back(table.back());\n\
    \            for (int j = 0; j + (1 << i) <= n; ++j) {\n                table[i][j]\
    \ = f(table[i][j], table[i][j + (1 << (i - 1))]);\n            }\n        }\n\
    \    }\n\n    // [l, r)\n    T get(int l, int r) {\n        assert(0 <= l && l\
    \ < r && r <= n);\n        int b = 31 - __builtin_clz(r - l);\n        return\
    \ f(table[b][l], table[b][r - (1 << b)]);\n    }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse-table.hpp
  requiredBy: []
  timestamp: '2023-02-25 13:28:05+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/sparse-table.hpp
layout: document
redirect_from:
- /library/ds/sparse-table.hpp
- /library/ds/sparse-table.hpp.html
title: ds/sparse-table.hpp
---
