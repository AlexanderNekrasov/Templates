---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':warning:'
    path: graph/maximum-independent-set.hpp
    title: graph/maximum-independent-set.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/vertex-cover-small-ans.hpp
    title: graph/vertex-cover-small-ans.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/vertex-cover.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\nusing UnweightedGraph = vector<vector<int>>;\n\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false, bool is_1origin = true) {\n    UnweightedGraph\
    \ g((size_t)N);\n    if (M == -1)\n        M = N - 1;\n    for (int _ = 0; _ <\
    \ M; _++) {\n        int x, y;\n        cin >> x >> y;\n        if (is_1origin)\
    \ {\n            x--;\n            y--;\n        }\n        g[(size_t) x].push_back(y);\n\
    \        if (!is_directed)\n            g[(size_t) y].push_back(x);\n    }\n \
    \   return g;\n}\n#line 2 \"template/macro.hpp\"\n\n#define all(v) (v).begin(),(v).end()\n\
    #define rall(v) (v).rbegin(),(v).rend()\n#define sz(v) (int((v).size()))\n#line\
    \ 2 \"graph/maximum-independent-set.hpp\"\n\n#line 4 \"graph/maximum-independent-set.hpp\"\
    \n\nvector<int> maximumIndependentSet(const UnweightedGraph &g) {\n    assert(sz(g)\
    \ <= 64);\n    int n = sz(g);\n    vector<ull> gb(n, 0);\n    for (int i = 0;\
    \ i < n; i++) {\n        for (int j : g[i]) {\n            gb[i] |= 1ULL << j;\n\
    \        }\n        gb[i] |= 1ULL << i;\n        gb[i] ^= ULLONG_MAX;\n    }\n\
    \    int k = (n + 1) / 2;\n    unordered_map<ull, ull> memo;\n    //vector<ull>\
    \ memo(1ULL << k, ULLONG_MAX);\n    auto rec = [&](auto rec, ull mask, int bit)\
    \ -> ull {\n        if (mask == 0)\n            return 0;\n        if (mask <\
    \ (1ULL << k) && memo.find(mask) != memo.end()) {\n            return memo[mask];\
    \ \n        }\n        if (mask & (1ULL << bit)) {\n            auto ans1 = rec(rec,\
    \ mask ^ (1ULL << bit), bit - 1);\n            auto ans2 = rec(rec, mask & gb[bit],\
    \ bit - 1) | (1ULL << bit);\n            if (__builtin_popcountll(ans1) < __builtin_popcountll(ans2))\
    \ {\n                ans1 = ans2;\n            }\n            if (mask < (1ULL\
    \ << k)) {\n                memo[mask] = ans1;\n            }\n            return\
    \ ans1;\n        } else {\n            return rec(rec, mask, bit - 1);\n     \
    \   }\n    };\n    auto ans = rec(rec, (1ULL << n) - 1, n - 1);\n    vector<int>\
    \ ans2;\n    for (int i = 0; i < n; i++) {\n        if (ans & (1ULL << i)) {\n\
    \            ans2.push_back(i);\n        }\n    }\n    return ans2;\n}\n#line\
    \ 6 \"graph/vertex-cover.hpp\"\n\nvector<int> vertexCover2(const UnweightedGraph\
    \ &g) {\n    int n = sz(g);\n    vector<int> used(n, 1);\n    auto is = maximumIndependentSet(g);\n\
    \    for (int el : is) {\n        used[el] = 0;\n    }\n    vector<int> ans;\n\
    \    for (int i = 0; i < n; i++)\n        if (used[i])\n            ans.push_back(i);\n\
    \    return ans;\n}\n\nvoid vertexCoverErase(vector<vector<bool>> &g, vector<int>\
    \ &vs, int u) {\n    int n = sz(g);\n    for (int i = 0; i < n; i++) {\n     \
    \   if (i != u) {\n            g[i].erase(g[i].begin() + u);\n        }\n    }\n\
    \    vs.erase(vs.begin() + u);\n    g.erase(g.begin() + u);\n}\n\nvoid vertexCoverClean(vector<vector<bool>>\
    \ &g, vector<int> &vs) {\n    int n = sz(g);\n    for (int i = n - 1; i >= 0;\
    \ i--) {\n        int d = accumulate(all(g[i]), 0);\n        if (d == 0)\n   \
    \         vertexCoverErase(g, vs, i);\n    }\n}\n\npair<int, vector<int>> vertexCoverAns(vector<vector<bool>>\
    \ &g, int k, vector<int> &vs, vector<int> &cur_ans) {\n    if (k < 0)\n      \
    \  return {1e9, {-1}};\n    if (g.empty())\n        return {0, cur_ans};\n   \
    \ if (k == 0)\n        return {1e9, {-1}};\n    int n = sz(g);\n    vector<int>\
    \ deg(n, 0);\n    for (int i = 0; i < n; i++) {\n        deg[i] = accumulate(all(g[i]),\
    \ 0);\n    }\n    int w = 0;\n    for (int i = 1; i < n; i++) {\n        if (deg[w]\
    \ < deg[i])\n            w = i;\n    }\n    pair<int, vector<int>> ans = {1e9,\
    \ {-1}};\n    auto g1 = g;\n    auto vs1 = vs;\n    auto cur_ans1 = cur_ans;\n\
    \    cur_ans1.push_back(vs[w]);\n    vertexCoverErase(g1, vs1, w);\n    vertexCoverClean(g1,\
    \ vs1);\n    auto ans1 = vertexCoverAns(g1, k - 1, vs1, cur_ans1);\n    ans1.first++;\n\
    \    ans = min(ans, ans1);\n    auto g2 = g;\n    auto vs2 = vs;\n    auto cur_ans2\
    \ = cur_ans;\n    for (int j = n - 1; j >= 0; j--) {\n        if (g[w][j]) {\n\
    \            vertexCoverErase(g2, vs2, j);\n            cur_ans2.push_back(vs[j]);\n\
    \        }\n    }\n    vertexCoverClean(g2, vs2);\n    auto ans2 = vertexCoverAns(g2,\
    \ k - deg[w], vs2, cur_ans2);\n    ans2.first += deg[w];\n    ans = min(ans, ans2);\n\
    \    return ans;\n}\n\nvector<int> vertexCover(const UnweightedGraph &g, int k)\
    \ {\n    int n = sz(g);\n    vector<vector<bool>> g2(n, vector<bool>(n));\n  \
    \  for (int i = 0; i < n; i++) {\n        for (int j : g[i]) {\n            g2[i][j]\
    \ = 1;\n        }\n    }\n    vector<int> allvs(n);\n    iota(all(allvs), 0);\n\
    \    vector<int> cur_ans;\n    auto ans = vertexCoverAns(g2, k, allvs, cur_ans);\n\
    \    if (ans.first == 1000000000) {\n        return {-1};\n    }\n    return ans.second;\n\
    }\n"
  code: "#pragma once\n\n#include \"graph-template.hpp\"\n#include \"../template/macro.hpp\"\
    \n#include \"maximum-independent-set.hpp\"\n\nvector<int> vertexCover2(const UnweightedGraph\
    \ &g) {\n    int n = sz(g);\n    vector<int> used(n, 1);\n    auto is = maximumIndependentSet(g);\n\
    \    for (int el : is) {\n        used[el] = 0;\n    }\n    vector<int> ans;\n\
    \    for (int i = 0; i < n; i++)\n        if (used[i])\n            ans.push_back(i);\n\
    \    return ans;\n}\n\nvoid vertexCoverErase(vector<vector<bool>> &g, vector<int>\
    \ &vs, int u) {\n    int n = sz(g);\n    for (int i = 0; i < n; i++) {\n     \
    \   if (i != u) {\n            g[i].erase(g[i].begin() + u);\n        }\n    }\n\
    \    vs.erase(vs.begin() + u);\n    g.erase(g.begin() + u);\n}\n\nvoid vertexCoverClean(vector<vector<bool>>\
    \ &g, vector<int> &vs) {\n    int n = sz(g);\n    for (int i = n - 1; i >= 0;\
    \ i--) {\n        int d = accumulate(all(g[i]), 0);\n        if (d == 0)\n   \
    \         vertexCoverErase(g, vs, i);\n    }\n}\n\npair<int, vector<int>> vertexCoverAns(vector<vector<bool>>\
    \ &g, int k, vector<int> &vs, vector<int> &cur_ans) {\n    if (k < 0)\n      \
    \  return {1e9, {-1}};\n    if (g.empty())\n        return {0, cur_ans};\n   \
    \ if (k == 0)\n        return {1e9, {-1}};\n    int n = sz(g);\n    vector<int>\
    \ deg(n, 0);\n    for (int i = 0; i < n; i++) {\n        deg[i] = accumulate(all(g[i]),\
    \ 0);\n    }\n    int w = 0;\n    for (int i = 1; i < n; i++) {\n        if (deg[w]\
    \ < deg[i])\n            w = i;\n    }\n    pair<int, vector<int>> ans = {1e9,\
    \ {-1}};\n    auto g1 = g;\n    auto vs1 = vs;\n    auto cur_ans1 = cur_ans;\n\
    \    cur_ans1.push_back(vs[w]);\n    vertexCoverErase(g1, vs1, w);\n    vertexCoverClean(g1,\
    \ vs1);\n    auto ans1 = vertexCoverAns(g1, k - 1, vs1, cur_ans1);\n    ans1.first++;\n\
    \    ans = min(ans, ans1);\n    auto g2 = g;\n    auto vs2 = vs;\n    auto cur_ans2\
    \ = cur_ans;\n    for (int j = n - 1; j >= 0; j--) {\n        if (g[w][j]) {\n\
    \            vertexCoverErase(g2, vs2, j);\n            cur_ans2.push_back(vs[j]);\n\
    \        }\n    }\n    vertexCoverClean(g2, vs2);\n    auto ans2 = vertexCoverAns(g2,\
    \ k - deg[w], vs2, cur_ans2);\n    ans2.first += deg[w];\n    ans = min(ans, ans2);\n\
    \    return ans;\n}\n\nvector<int> vertexCover(const UnweightedGraph &g, int k)\
    \ {\n    int n = sz(g);\n    vector<vector<bool>> g2(n, vector<bool>(n));\n  \
    \  for (int i = 0; i < n; i++) {\n        for (int j : g[i]) {\n            g2[i][j]\
    \ = 1;\n        }\n    }\n    vector<int> allvs(n);\n    iota(all(allvs), 0);\n\
    \    vector<int> cur_ans;\n    auto ans = vertexCoverAns(g2, k, allvs, cur_ans);\n\
    \    if (ans.first == 1000000000) {\n        return {-1};\n    }\n    return ans.second;\n\
    }\n"
  dependsOn:
  - graph/graph-template.hpp
  - template/macro.hpp
  - graph/maximum-independent-set.hpp
  isVerificationFile: false
  path: graph/vertex-cover.hpp
  requiredBy:
  - graph/vertex-cover-small-ans.hpp
  timestamp: '2022-07-12 17:31:52+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/vertex-cover.hpp
layout: document
redirect_from:
- /library/graph/vertex-cover.hpp
- /library/graph/vertex-cover.hpp.html
title: graph/vertex-cover.hpp
---
