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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph-utils.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\nusing UnweightedGraph = vector<vector<int>>;\n\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false, bool is_1origin = true) {\n    UnweightedGraph\
    \ g((size_t)N);\n    if (M == -1)\n        M = N - 1;\n    for (int _ = 0; _ <\
    \ M; _++) {\n        int x, y;\n        cin >> x >> y;\n        if (is_1origin)\
    \ {\n            x--;\n            y--;\n        }\n        g[(size_t) x].push_back(y);\n\
    \        if (!is_directed)\n            g[(size_t) y].push_back(x);\n    }\n \
    \   return g;\n}\n#line 4 \"graph/graph-utils.hpp\"\n\nUnweightedGraph subgraph(UnweightedGraph\
    \ g, vector<int> vs) {\n    sort(all(vs));\n    UnweightedGraph g2(sz(vs));\n\
    \    for (int i = 0; i < (int) vs.size(); i++) {\n        for (int j : g[vs[i]])\
    \ {\n            auto it = lower_bound(all(vs), j);\n            if (it != vs.end()\
    \ && *it == j) {\n                g2[i].push_back(lower_bound(all(vs), j) - vs.begin());\n\
    \            }\n        }\n    }\n    return g2;\n}\n"
  code: "#pragma once\n\n#include \"graph-template.hpp\"\n\nUnweightedGraph subgraph(UnweightedGraph\
    \ g, vector<int> vs) {\n    sort(all(vs));\n    UnweightedGraph g2(sz(vs));\n\
    \    for (int i = 0; i < (int) vs.size(); i++) {\n        for (int j : g[vs[i]])\
    \ {\n            auto it = lower_bound(all(vs), j);\n            if (it != vs.end()\
    \ && *it == j) {\n                g2[i].push_back(lower_bound(all(vs), j) - vs.begin());\n\
    \            }\n        }\n    }\n    return g2;\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/graph-utils.hpp
  requiredBy:
  - graph/vertex-cover-small-ans.hpp
  timestamp: '2022-07-12 17:31:52+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph-utils.hpp
layout: document
redirect_from:
- /library/graph/graph-utils.hpp
- /library/graph/graph-utils.hpp.html
title: graph/graph-utils.hpp
---
