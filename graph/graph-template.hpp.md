---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/graph-utils.hpp
    title: graph/graph-utils.hpp
  - icon: ':warning:'
    path: graph/maximum-independent-set.hpp
    title: graph/maximum-independent-set.hpp
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
  bundledCode: "#line 2 \"graph/graph-template.hpp\"\n\nusing UnweightedGraph = vector<vector<int>>;\n\
    \nUnweightedGraph graph(int N, int M = -1, bool is_directed = false, bool is_1origin\
    \ = true) {\n    UnweightedGraph g((size_t)N);\n    if (M == -1)\n        M =\
    \ N - 1;\n    for (int _ = 0; _ < M; _++) {\n        int x, y;\n        cin >>\
    \ x >> y;\n        if (is_1origin) {\n            x--;\n            y--;\n   \
    \     }\n        g[(size_t) x].push_back(y);\n        if (!is_directed)\n    \
    \        g[(size_t) y].push_back(x);\n    }\n    return g;\n}\n"
  code: "#pragma once\n\nusing UnweightedGraph = vector<vector<int>>;\n\nUnweightedGraph\
    \ graph(int N, int M = -1, bool is_directed = false, bool is_1origin = true) {\n\
    \    UnweightedGraph g((size_t)N);\n    if (M == -1)\n        M = N - 1;\n   \
    \ for (int _ = 0; _ < M; _++) {\n        int x, y;\n        cin >> x >> y;\n \
    \       if (is_1origin) {\n            x--;\n            y--;\n        }\n   \
    \     g[(size_t) x].push_back(y);\n        if (!is_directed)\n            g[(size_t)\
    \ y].push_back(x);\n    }\n    return g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph-template.hpp
  requiredBy:
  - graph/vertex-cover.hpp
  - graph/maximum-independent-set.hpp
  - graph/vertex-cover-small-ans.hpp
  - graph/graph-utils.hpp
  timestamp: '2022-07-12 17:31:52+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph-template.hpp
layout: document
redirect_from:
- /library/graph/graph-template.hpp
- /library/graph/graph-template.hpp.html
title: graph/graph-template.hpp
---
