---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: ds/queue.hpp
    title: ds/queue.hpp
  - icon: ':warning:'
    path: graph/maxflow.hpp
    title: graph/maxflow.hpp
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
  bundledCode: "#line 2 \"graph/bipartite-graph.hpp\"\n\n#line 2 \"ds/queue.hpp\"\n\
    \ntemplate<typename T>\nstruct simple_queue {\n    vector<T> arr;\n    int pos\
    \ = 0;\n    void reserve(int n) { arr.reserve(n); }\n    int size() const { return\
    \ sz(arr) - pos; }\n    bool empty() { return pos == sz(arr); }\n    void push(const\
    \ T& t) { arr.push_back(t); }\n    T& front() {\n        return arr[pos];\n  \
    \  }\n    void clear() {\n        arr.clear();\n        pos = 0;\n    }\n    void\
    \ pop() { pos++; }\n};\n#line 3 \"graph/maxflow.hpp\"\n\ntemplate<typename T>\n\
    struct MaxFlow {\n    explicit MaxFlow(int n) : n(n), g(n) {}\n\n    int add_edge(int\
    \ from, int to, T cap) {\n        assert(0 <= from && from < n);\n        assert(0\
    \ <= to && to < n);\n        assert(0 <= cap);\n        int m = sz(pos);\n   \
    \     pos.push_back({from, sz(g[from])});\n        int sz_from = sz(g[from]);\n\
    \        int sz_to = sz(g[to]);\n        if (from == to) {\n            sz_to++;\n\
    \        }\n        g[from].push_back({to, sz_to, cap});\n        g[to].push_back({from,\
    \ sz_from, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        T cap, flow;\n    };\n\n    edge get_edge(int i) {\n        assert(0\
    \ <= i && i < sz(pos));\n        auto _e = g[pos[i].first][pos[i].second];\n \
    \       auto _re = g[_e.to][_e.rev];\n        return {_re.to, _e.to, _e.cap +\
    \ _re.cap, _re.cap};\n    }\n\n    vector<edge> edges() {\n        int m = sz(pos);\n\
    \        vector<edge> ans;\n        for (int i = 0; i < m; i++) {\n          \
    \  ans.push_back(get_edge(i));\n        }\n        return ans;\n    }\n\n    T\
    \ flow(int s, int t) {\n        return flow(s, t, numeric_limits<T>::max());\n\
    \    }\n\n    T flow(int s, int t, T flow_limit) {\n        assert(0 <= s && s\
    \ < n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n        vector<int>\
    \ level(n), iter(n);\n        simple_queue<int> q;\n\n        auto bfs = [&]()\
    \ {\n            fill(all(level), -1);\n            level[s] = 0;\n          \
    \  q.clear();\n            q.push(s);\n            while (!q.empty()) {\n    \
    \            int v = q.front();\n                q.pop();\n                for\
    \ (auto e : g[v]) {\n                    if (e.cap == 0 || level[e.to] >= 0) continue;\n\
    \                    level[e.to] = level[v] + 1;\n                    if (e.to\
    \ == t) return;\n                    q.push(e.to);\n                }\n      \
    \      }\n        };\n        auto dfs = [&](auto self, int v, T up) {\n     \
    \       if (v == s) {\n                return up;\n            }\n           \
    \ T res = 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < sz(g[v]); i++) {\n                auto &e = g[v][i];\n                if\
    \ (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n            \
    \    T d =\n                    self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
    \                if (d <= 0) continue;\n                g[v][i].cap += d;\n  \
    \              g[e.to][e.rev].cap -= d;\n                res += d;\n         \
    \       if (res == up)\n                    return res;\n            }\n     \
    \       level[v] = n;\n            return res;\n        };\n\n        T flow =\
    \ 0;\n        while (flow < flow_limit) {\n            bfs();\n            if\
    \ (level[t] == -1)\n                break;\n            fill(all(iter), 0);\n\
    \            T f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\n    \
    \            break;\n            flow += f;\n        }\n        return flow;\n\
    \    }\n\n    private:\n    int n;\n    vector<pair<int, int>> pos;\n    struct\
    \ _edge {\n        int to, rev;\n        T cap;\n    };\n    vector<vector<_edge>>\
    \ g;\n};\n#line 4 \"graph/bipartite-graph.hpp\"\n\nstruct BipartiteGraph: MaxFlow<ll>\
    \ {\n    int L, R, s, t;\n    bool was_flow;\n\n    explicit BipartiteGraph(int\
    \ N, int M)\n        : MaxFlow<ll>(N + M + 2),\n          L(N),\n          R(M),\n\
    \          s(N + M),\n          t(N + M + 1),\n          was_flow(false) {\n \
    \       for (int i = 0; i < L; i++) {\n            MaxFlow<ll>::add_edge(s, i,\
    \ 1); \n        }\n        for (int i = 0; i < R; i++) {\n            MaxFlow<ll>::add_edge(i\
    \ + L, t, 1);\n        }\n    }\n\n    int add_edge(int a, int b, ll c = 1) {\n\
    \        assert(0 <= a && a < L);\n        assert(0 <= b && b < R);\n        return\
    \ MaxFlow<ll>::add_edge(a, b + L, c);\n    }\n\n    ll flow() {\n        was_flow\
    \ = true;\n        return MaxFlow<ll>::flow(s, t);\n    }\n\n    pair<vector<int>,\
    \ vector<int>> minimumVertexCover() {\n        if (!was_flow)\n            flow();\n\
    \        vector<bool> used = dfsUsed();\n        vector<int> lv, rv;\n       \
    \ for (int i = 0; i < L; i++) {\n            if (!used[i]) {\n               \
    \ lv.push_back(i);\n            }\n        }\n        for (int i = 0; i < R; i++)\
    \ {\n            if (used[i + L]) {\n                rv.push_back(i);\n      \
    \      }\n        }\n        return {lv, rv};\n    }\n\n    private:\n    vector<bool>\
    \ dfsUsed() {\n        vector<vector<int>> g(L + R);\n        vector<bool> matched(L);\n\
    \        for (auto &e : MaxFlow<ll>::edges()) {\n            if (e.from == s ||\
    \ e.to == t)\n                continue;\n            if (e.flow > 0) {\n     \
    \           g[e.to].push_back(e.from);\n                matched[e.from] = true;\n\
    \            } else {\n                g[e.from].push_back(e.to);\n          \
    \  }\n        }\n        vector<bool> used(L + R);\n        auto dfs = [&](auto\
    \ dfs, int v) -> void {\n            used[v] = 1;\n            for (int u : g[v])\n\
    \                if (!used[u])\n                    dfs(dfs, u);\n        };\n\
    \        for (int i = 0; i < L; i++) {\n            if (!matched[i] && !used[i])\
    \ {\n                dfs(dfs, i);\n            }\n        }\n        return used;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include \"maxflow.hpp\"\n\nstruct BipartiteGraph: MaxFlow<ll>\
    \ {\n    int L, R, s, t;\n    bool was_flow;\n\n    explicit BipartiteGraph(int\
    \ N, int M)\n        : MaxFlow<ll>(N + M + 2),\n          L(N),\n          R(M),\n\
    \          s(N + M),\n          t(N + M + 1),\n          was_flow(false) {\n \
    \       for (int i = 0; i < L; i++) {\n            MaxFlow<ll>::add_edge(s, i,\
    \ 1); \n        }\n        for (int i = 0; i < R; i++) {\n            MaxFlow<ll>::add_edge(i\
    \ + L, t, 1);\n        }\n    }\n\n    int add_edge(int a, int b, ll c = 1) {\n\
    \        assert(0 <= a && a < L);\n        assert(0 <= b && b < R);\n        return\
    \ MaxFlow<ll>::add_edge(a, b + L, c);\n    }\n\n    ll flow() {\n        was_flow\
    \ = true;\n        return MaxFlow<ll>::flow(s, t);\n    }\n\n    pair<vector<int>,\
    \ vector<int>> minimumVertexCover() {\n        if (!was_flow)\n            flow();\n\
    \        vector<bool> used = dfsUsed();\n        vector<int> lv, rv;\n       \
    \ for (int i = 0; i < L; i++) {\n            if (!used[i]) {\n               \
    \ lv.push_back(i);\n            }\n        }\n        for (int i = 0; i < R; i++)\
    \ {\n            if (used[i + L]) {\n                rv.push_back(i);\n      \
    \      }\n        }\n        return {lv, rv};\n    }\n\n    private:\n    vector<bool>\
    \ dfsUsed() {\n        vector<vector<int>> g(L + R);\n        vector<bool> matched(L);\n\
    \        for (auto &e : MaxFlow<ll>::edges()) {\n            if (e.from == s ||\
    \ e.to == t)\n                continue;\n            if (e.flow > 0) {\n     \
    \           g[e.to].push_back(e.from);\n                matched[e.from] = true;\n\
    \            } else {\n                g[e.from].push_back(e.to);\n          \
    \  }\n        }\n        vector<bool> used(L + R);\n        auto dfs = [&](auto\
    \ dfs, int v) -> void {\n            used[v] = 1;\n            for (int u : g[v])\n\
    \                if (!used[u])\n                    dfs(dfs, u);\n        };\n\
    \        for (int i = 0; i < L; i++) {\n            if (!matched[i] && !used[i])\
    \ {\n                dfs(dfs, i);\n            }\n        }\n        return used;\n\
    \    }\n};\n"
  dependsOn:
  - graph/maxflow.hpp
  - ds/queue.hpp
  isVerificationFile: false
  path: graph/bipartite-graph.hpp
  requiredBy:
  - graph/vertex-cover-small-ans.hpp
  timestamp: '2022-07-12 17:31:52+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite-graph.hpp
layout: document
redirect_from:
- /library/graph/bipartite-graph.hpp
- /library/graph/bipartite-graph.hpp.html
title: graph/bipartite-graph.hpp
---
