---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bipartite-graph.hpp
    title: graph/bipartite-graph.hpp
  - icon: ':warning:'
    path: graph/maxflow.hpp
    title: graph/maxflow.hpp
  - icon: ':warning:'
    path: graph/vertex-cover-small-ans.hpp
    title: graph/vertex-cover-small-ans.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/queue.hpp\"\n\ntemplate<typename T>\nstruct simple_queue\
    \ {\n    vector<T> arr;\n    int pos = 0;\n    void reserve(int n) { arr.reserve(n);\
    \ }\n    int size() const { return sz(arr) - pos; }\n    bool empty() { return\
    \ pos == sz(arr); }\n    void push(const T& t) { arr.push_back(t); }\n    T& front()\
    \ {\n        return arr[pos];\n    }\n    void clear() {\n        arr.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct simple_queue {\n    vector<T>\
    \ arr;\n    int pos = 0;\n    void reserve(int n) { arr.reserve(n); }\n    int\
    \ size() const { return sz(arr) - pos; }\n    bool empty() { return pos == sz(arr);\
    \ }\n    void push(const T& t) { arr.push_back(t); }\n    T& front() {\n     \
    \   return arr[pos];\n    }\n    void clear() {\n        arr.clear();\n      \
    \  pos = 0;\n    }\n    void pop() { pos++; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/queue.hpp
  requiredBy:
  - graph/bipartite-graph.hpp
  - graph/maxflow.hpp
  - graph/vertex-cover-small-ans.hpp
  timestamp: '2022-07-12 17:31:52+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/queue.hpp
layout: document
redirect_from:
- /library/ds/queue.hpp
- /library/ds/queue.hpp.html
title: ds/queue.hpp
---
