---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/vertex-cover-small-ans.hpp
    title: graph/vertex-cover-small-ans.hpp
  - icon: ':warning:'
    path: graph/vertex-cover.hpp
    title: graph/vertex-cover.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/maximum-independent-set.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\nusing UnweightedGraph = vector<vector<int>>;\n\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false, bool is_1origin = true) {\n    UnweightedGraph\
    \ g((size_t)N);\n    if (M == -1)\n        M = N - 1;\n    for (int _ = 0; _ <\
    \ M; _++) {\n        int x, y;\n        cin >> x >> y;\n        if (is_1origin)\
    \ {\n            x--;\n            y--;\n        }\n        g[(size_t) x].push_back(y);\n\
    \        if (!is_directed)\n            g[(size_t) y].push_back(x);\n    }\n \
    \   return g;\n}\n#line 4 \"graph/maximum-independent-set.hpp\"\n\nvector<int>\
    \ maximumIndependentSet(const UnweightedGraph &g) {\n    assert(sz(g) <= 64);\n\
    \    int n = sz(g);\n    vector<ull> gb(n, 0);\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j : g[i]) {\n            gb[i] |= 1ULL << j;\n        }\n\
    \        gb[i] |= 1ULL << i;\n        gb[i] ^= ULLONG_MAX;\n    }\n    int k =\
    \ (n + 1) / 2;\n    unordered_map<ull, ull> memo;\n    //vector<ull> memo(1ULL\
    \ << k, ULLONG_MAX);\n    auto rec = [&](auto rec, ull mask, int bit) -> ull {\n\
    \        if (mask == 0)\n            return 0;\n        if (mask < (1ULL << k)\
    \ && memo.find(mask) != memo.end()) {\n            return memo[mask]; \n     \
    \   }\n        if (mask & (1ULL << bit)) {\n            auto ans1 = rec(rec, mask\
    \ ^ (1ULL << bit), bit - 1);\n            auto ans2 = rec(rec, mask & gb[bit],\
    \ bit - 1) | (1ULL << bit);\n            if (__builtin_popcountll(ans1) < __builtin_popcountll(ans2))\
    \ {\n                ans1 = ans2;\n            }\n            if (mask < (1ULL\
    \ << k)) {\n                memo[mask] = ans1;\n            }\n            return\
    \ ans1;\n        } else {\n            return rec(rec, mask, bit - 1);\n     \
    \   }\n    };\n    auto ans = rec(rec, (1ULL << n) - 1, n - 1);\n    vector<int>\
    \ ans2;\n    for (int i = 0; i < n; i++) {\n        if (ans & (1ULL << i)) {\n\
    \            ans2.push_back(i);\n        }\n    }\n    return ans2;\n}\n"
  code: "#pragma once\n\n#include \"graph-template.hpp\"\n\nvector<int> maximumIndependentSet(const\
    \ UnweightedGraph &g) {\n    assert(sz(g) <= 64);\n    int n = sz(g);\n    vector<ull>\
    \ gb(n, 0);\n    for (int i = 0; i < n; i++) {\n        for (int j : g[i]) {\n\
    \            gb[i] |= 1ULL << j;\n        }\n        gb[i] |= 1ULL << i;\n   \
    \     gb[i] ^= ULLONG_MAX;\n    }\n    int k = (n + 1) / 2;\n    unordered_map<ull,\
    \ ull> memo;\n    //vector<ull> memo(1ULL << k, ULLONG_MAX);\n    auto rec = [&](auto\
    \ rec, ull mask, int bit) -> ull {\n        if (mask == 0)\n            return\
    \ 0;\n        if (mask < (1ULL << k) && memo.find(mask) != memo.end()) {\n   \
    \         return memo[mask]; \n        }\n        if (mask & (1ULL << bit)) {\n\
    \            auto ans1 = rec(rec, mask ^ (1ULL << bit), bit - 1);\n          \
    \  auto ans2 = rec(rec, mask & gb[bit], bit - 1) | (1ULL << bit);\n          \
    \  if (__builtin_popcountll(ans1) < __builtin_popcountll(ans2)) {\n          \
    \      ans1 = ans2;\n            }\n            if (mask < (1ULL << k)) {\n  \
    \              memo[mask] = ans1;\n            }\n            return ans1;\n \
    \       } else {\n            return rec(rec, mask, bit - 1);\n        }\n   \
    \ };\n    auto ans = rec(rec, (1ULL << n) - 1, n - 1);\n    vector<int> ans2;\n\
    \    for (int i = 0; i < n; i++) {\n        if (ans & (1ULL << i)) {\n       \
    \     ans2.push_back(i);\n        }\n    }\n    return ans2;\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/maximum-independent-set.hpp
  requiredBy:
  - graph/vertex-cover.hpp
  - graph/vertex-cover-small-ans.hpp
  timestamp: '2022-07-12 17:31:52+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximum-independent-set.hpp
layout: document
redirect_from:
- /library/graph/maximum-independent-set.hpp
- /library/graph/maximum-independent-set.hpp.html
title: graph/maximum-independent-set.hpp
---
