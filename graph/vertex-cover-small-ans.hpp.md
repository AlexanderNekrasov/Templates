---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: ds/queue.hpp
    title: ds/queue.hpp
  - icon: ':warning:'
    path: graph/bipartite-graph.hpp
    title: graph/bipartite-graph.hpp
  - icon: ':warning:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':warning:'
    path: graph/graph-utils.hpp
    title: graph/graph-utils.hpp
  - icon: ':warning:'
    path: graph/maxflow.hpp
    title: graph/maxflow.hpp
  - icon: ':warning:'
    path: graph/maximum-independent-set.hpp
    title: graph/maximum-independent-set.hpp
  - icon: ':warning:'
    path: graph/vertex-cover.hpp
    title: graph/vertex-cover.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/vertex-cover-small-ans.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\nusing UnweightedGraph = vector<vector<int>>;\n\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false, bool is_1origin = true) {\n    UnweightedGraph\
    \ g((size_t)N);\n    if (M == -1)\n        M = N - 1;\n    for (int _ = 0; _ <\
    \ M; _++) {\n        int x, y;\n        cin >> x >> y;\n        if (is_1origin)\
    \ {\n            x--;\n            y--;\n        }\n        g[(size_t) x].push_back(y);\n\
    \        if (!is_directed)\n            g[(size_t) y].push_back(x);\n    }\n \
    \   return g;\n}\n#line 2 \"graph/graph-utils.hpp\"\n\n#line 4 \"graph/graph-utils.hpp\"\
    \n\nUnweightedGraph subgraph(UnweightedGraph g, vector<int> vs) {\n    sort(all(vs));\n\
    \    UnweightedGraph g2(sz(vs));\n    for (int i = 0; i < (int) vs.size(); i++)\
    \ {\n        for (int j : g[vs[i]]) {\n            auto it = lower_bound(all(vs),\
    \ j);\n            if (it != vs.end() && *it == j) {\n                g2[i].push_back(lower_bound(all(vs),\
    \ j) - vs.begin());\n            }\n        }\n    }\n    return g2;\n}\n#line\
    \ 2 \"graph/bipartite-graph.hpp\"\n\n#line 2 \"ds/queue.hpp\"\n\ntemplate<typename\
    \ T>\nstruct simple_queue {\n    vector<T> arr;\n    int pos = 0;\n    void reserve(int\
    \ n) { arr.reserve(n); }\n    int size() const { return sz(arr) - pos; }\n   \
    \ bool empty() { return pos == sz(arr); }\n    void push(const T& t) { arr.push_back(t);\
    \ }\n    T& front() {\n        return arr[pos];\n    }\n    void clear() {\n \
    \       arr.clear();\n        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\
    #line 3 \"graph/maxflow.hpp\"\n\ntemplate<typename T>\nstruct MaxFlow {\n    explicit\
    \ MaxFlow(int n) : n(n), g(n) {}\n\n    int add_edge(int from, int to, T cap)\
    \ {\n        assert(0 <= from && from < n);\n        assert(0 <= to && to < n);\n\
    \        assert(0 <= cap);\n        int m = sz(pos);\n        pos.push_back({from,\
    \ sz(g[from])});\n        int sz_from = sz(g[from]);\n        int sz_to = sz(g[to]);\n\
    \        if (from == to) {\n            sz_to++;\n        }\n        g[from].push_back({to,\
    \ sz_to, cap});\n        g[to].push_back({from, sz_from, 0});\n        return\
    \ m;\n    }\n\n    struct edge {\n        int from, to;\n        T cap, flow;\n\
    \    };\n\n    edge get_edge(int i) {\n        assert(0 <= i && i < sz(pos));\n\
    \        auto _e = g[pos[i].first][pos[i].second];\n        auto _re = g[_e.to][_e.rev];\n\
    \        return {_re.to, _e.to, _e.cap + _re.cap, _re.cap};\n    }\n\n    vector<edge>\
    \ edges() {\n        int m = sz(pos);\n        vector<edge> ans;\n        for\
    \ (int i = 0; i < m; i++) {\n            ans.push_back(get_edge(i));\n       \
    \ }\n        return ans;\n    }\n\n    T flow(int s, int t) {\n        return\
    \ flow(s, t, numeric_limits<T>::max());\n    }\n\n    T flow(int s, int t, T flow_limit)\
    \ {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n    \
    \    assert(s != t);\n        vector<int> level(n), iter(n);\n        simple_queue<int>\
    \ q;\n\n        auto bfs = [&]() {\n            fill(all(level), -1);\n      \
    \      level[s] = 0;\n            q.clear();\n            q.push(s);\n       \
    \     while (!q.empty()) {\n                int v = q.front();\n             \
    \   q.pop();\n                for (auto e : g[v]) {\n                    if (e.cap\
    \ == 0 || level[e.to] >= 0) continue;\n                    level[e.to] = level[v]\
    \ + 1;\n                    if (e.to == t) return;\n                    q.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, T up) {\n            if (v == s) {\n                return up;\n    \
    \        }\n            T res = 0;\n            int level_v = level[v];\n    \
    \        for (int& i = iter[v]; i < sz(g[v]); i++) {\n                auto &e\
    \ = g[v][i];\n                if (level_v <= level[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n                T d =\n                    self(self, e.to,\
    \ min(up - res, g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n\
    \                g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n\
    \                res += d;\n                if (res == up)\n                 \
    \   return res;\n            }\n            level[v] = n;\n            return\
    \ res;\n        };\n\n        T flow = 0;\n        while (flow < flow_limit) {\n\
    \            bfs();\n            if (level[t] == -1)\n                break;\n\
    \            fill(all(iter), 0);\n            T f = dfs(dfs, t, flow_limit - flow);\n\
    \            if (!f)\n                break;\n            flow += f;\n       \
    \ }\n        return flow;\n    }\n\n    private:\n    int n;\n    vector<pair<int,\
    \ int>> pos;\n    struct _edge {\n        int to, rev;\n        T cap;\n    };\n\
    \    vector<vector<_edge>> g;\n};\n#line 4 \"graph/bipartite-graph.hpp\"\n\nstruct\
    \ BipartiteGraph: MaxFlow<ll> {\n    int L, R, s, t;\n    bool was_flow;\n\n \
    \   explicit BipartiteGraph(int N, int M)\n        : MaxFlow<ll>(N + M + 2),\n\
    \          L(N),\n          R(M),\n          s(N + M),\n          t(N + M + 1),\n\
    \          was_flow(false) {\n        for (int i = 0; i < L; i++) {\n        \
    \    MaxFlow<ll>::add_edge(s, i, 1); \n        }\n        for (int i = 0; i <\
    \ R; i++) {\n            MaxFlow<ll>::add_edge(i + L, t, 1);\n        }\n    }\n\
    \n    int add_edge(int a, int b, ll c = 1) {\n        assert(0 <= a && a < L);\n\
    \        assert(0 <= b && b < R);\n        return MaxFlow<ll>::add_edge(a, b +\
    \ L, c);\n    }\n\n    ll flow() {\n        was_flow = true;\n        return MaxFlow<ll>::flow(s,\
    \ t);\n    }\n\n    pair<vector<int>, vector<int>> minimumVertexCover() {\n  \
    \      if (!was_flow)\n            flow();\n        vector<bool> used = dfsUsed();\n\
    \        vector<int> lv, rv;\n        for (int i = 0; i < L; i++) {\n        \
    \    if (!used[i]) {\n                lv.push_back(i);\n            }\n      \
    \  }\n        for (int i = 0; i < R; i++) {\n            if (used[i + L]) {\n\
    \                rv.push_back(i);\n            }\n        }\n        return {lv,\
    \ rv};\n    }\n\n    private:\n    vector<bool> dfsUsed() {\n        vector<vector<int>>\
    \ g(L + R);\n        vector<bool> matched(L);\n        for (auto &e : MaxFlow<ll>::edges())\
    \ {\n            if (e.from == s || e.to == t)\n                continue;\n  \
    \          if (e.flow > 0) {\n                g[e.to].push_back(e.from);\n   \
    \             matched[e.from] = true;\n            } else {\n                g[e.from].push_back(e.to);\n\
    \            }\n        }\n        vector<bool> used(L + R);\n        auto dfs\
    \ = [&](auto dfs, int v) -> void {\n            used[v] = 1;\n            for\
    \ (int u : g[v])\n                if (!used[u])\n                    dfs(dfs,\
    \ u);\n        };\n        for (int i = 0; i < L; i++) {\n            if (!matched[i]\
    \ && !used[i]) {\n                dfs(dfs, i);\n            }\n        }\n   \
    \     return used;\n    }\n};\n#line 2 \"template/macro.hpp\"\n\n#define all(v)\
    \ (v).begin(),(v).end()\n#define rall(v) (v).rbegin(),(v).rend()\n#define sz(v)\
    \ (int((v).size()))\n#line 3 \"template/util.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <string>\n\ntemplate<typename T>\nvoid unq(std::vector<T>\
    \ &arr) {\n    sort(all(arr));\n    arr.erase(unique(all(arr)), arr.end());\n\
    }\nvoid unq(std::string &arr) {\n    sort(all(arr));\n    arr.erase(unique(all(arr)),\
    \ arr.end());\n}\n#line 2 \"graph/vertex-cover.hpp\"\n\n#line 2 \"graph/maximum-independent-set.hpp\"\
    \n\n#line 4 \"graph/maximum-independent-set.hpp\"\n\nvector<int> maximumIndependentSet(const\
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
    \     ans2.push_back(i);\n        }\n    }\n    return ans2;\n}\n#line 6 \"graph/vertex-cover.hpp\"\
    \n\nvector<int> vertexCover2(const UnweightedGraph &g) {\n    int n = sz(g);\n\
    \    vector<int> used(n, 1);\n    auto is = maximumIndependentSet(g);\n    for\
    \ (int el : is) {\n        used[el] = 0;\n    }\n    vector<int> ans;\n    for\
    \ (int i = 0; i < n; i++)\n        if (used[i])\n            ans.push_back(i);\n\
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
    }\n#line 8 \"graph/vertex-cover-small-ans.hpp\"\n\n// Finds vertex cover on big\
    \ graphs, where it is known that \n// size of vertex cover is small, works in\
    \ O((n+m)log(n)+k^3+1.63^k)\n// returns {-1} if vertex cover size is greater than\
    \ k.\nvector<int> vertexCoverSmallAns(UnweightedGraph g, int k) {\n    int n =\
    \ (int) g.size();\n    // **Buss's reduction**\n    // Every vertex with a degree\
    \ > k should be in the vertex cover\n    vector<int> ans;\n    vector<char> used(n);\n\
    \    for (int i = 0; i < n; i++) {\n        if ((int) g[i].size() > k) {\n   \
    \         used[i] = 1;\n            ans.push_back(i);\n        }\n    }\n    //\
    \ g2 = g \\ ans \\ { v \\in V | deg v = 0 }\n    vector<int> vs2;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (!used[i] && any_of(all(g[i]), [&](int v) {\
    \ return !used[v]; }))\n            vs2.push_back(i);\n    }\n    UnweightedGraph\
    \ g2 = subgraph(g, vs2);\n    for (auto &el : g2) {\n        unq(el);\n    }\n\
    \    // Now g2 should contain at most k+k^2 vertices and at most k^2 edges\n \
    \   {\n        int cntEdges = 0;\n        for (int i = 0; i < sz(g2); i++)\n \
    \           cntEdges += g2[i].size();\n        cntEdges >>= 1;\n        if (sz(g2)\
    \ > k + k * k || cntEdges > k * k) {\n            return {-1};\n        }\n  \
    \  }\n    // Construct a solution to LP problem using vertex cover on bipartite\
    \ graph \n    BipartiteGraph g3(sz(g2), sz(g2));\n    for (int i = 0; i < sz(g2);\
    \ i++) {\n        for (int j : g2[i]) {\n            g3.add_edge(i, j);\n    \
    \    }\n    }\n    auto vc_ = g3.minimumVertexCover();\n    if (sz(vc_.first)\
    \ + sz(vc_.second) > 2 * (k - sz(ans))) {\n        return {-1};\n    }\n    vector<int>\
    \ cnt(sz(g2));\n    for (int v : vc_.first) {\n        cnt[v]++;\n    }\n    for\
    \ (int v : vc_.second) {\n        cnt[v]++;\n    }\n    vector<int> v12;\n   \
    \ for (int i = 0; i < sz(g2); i++) {\n        if (cnt[i] == 2) {\n           \
    \ ans.push_back(vs2[i]);\n            used[i] = 1;\n        } else if (cnt[i]\
    \ == 1) {\n            v12.push_back(i);\n        }\n    }\n    auto g4 = subgraph(g2,\
    \ v12);\n    for (auto &el : g4) {\n        unq(el);\n    }\n    assert(sz(g4)\
    \ <= 2 * k);\n\n    // Construct vertex cover on small graph\n    auto ans2 =\
    \ vertexCover(g4, k - sz(ans));\n    // auto ans2 = vertexCover2(g4);\n    if\
    \ ((ans2.size() == 1 && ans2[0] == -1) || sz(ans2) > k - sz(ans)) {\n        return\
    \ {-1};\n    }\n    for (int el : ans2) {\n        ans.push_back(vs2[v12[el]]);\n\
    \    }\n\n    // check that ans is vertex cover (not checking if it is minimum)\n\
    \    used.assign(n, 0);\n    for (int el : ans) {\n        used[el] = 1;\n   \
    \ }\n    for (int i = 0; i < n; i++) {\n        for (int j : g[i]) {\n       \
    \     assert(used[i] || used[j]);\n        }\n    }\n    return ans;\n}\n"
  code: "#pragma once\n\n#include \"graph-template.hpp\"\n#include \"graph-utils.hpp\"\
    \n#include \"bipartite-graph.hpp\"\n#include \"../template/util.hpp\"\n#include\
    \ \"vertex-cover.hpp\"\n\n// Finds vertex cover on big graphs, where it is known\
    \ that \n// size of vertex cover is small, works in O((n+m)log(n)+k^3+1.63^k)\n\
    // returns {-1} if vertex cover size is greater than k.\nvector<int> vertexCoverSmallAns(UnweightedGraph\
    \ g, int k) {\n    int n = (int) g.size();\n    // **Buss's reduction**\n    //\
    \ Every vertex with a degree > k should be in the vertex cover\n    vector<int>\
    \ ans;\n    vector<char> used(n);\n    for (int i = 0; i < n; i++) {\n       \
    \ if ((int) g[i].size() > k) {\n            used[i] = 1;\n            ans.push_back(i);\n\
    \        }\n    }\n    // g2 = g \\ ans \\ { v \\in V | deg v = 0 }\n    vector<int>\
    \ vs2;\n    for (int i = 0; i < n; i++) {\n        if (!used[i] && any_of(all(g[i]),\
    \ [&](int v) { return !used[v]; }))\n            vs2.push_back(i);\n    }\n  \
    \  UnweightedGraph g2 = subgraph(g, vs2);\n    for (auto &el : g2) {\n       \
    \ unq(el);\n    }\n    // Now g2 should contain at most k+k^2 vertices and at\
    \ most k^2 edges\n    {\n        int cntEdges = 0;\n        for (int i = 0; i\
    \ < sz(g2); i++)\n            cntEdges += g2[i].size();\n        cntEdges >>=\
    \ 1;\n        if (sz(g2) > k + k * k || cntEdges > k * k) {\n            return\
    \ {-1};\n        }\n    }\n    // Construct a solution to LP problem using vertex\
    \ cover on bipartite graph \n    BipartiteGraph g3(sz(g2), sz(g2));\n    for (int\
    \ i = 0; i < sz(g2); i++) {\n        for (int j : g2[i]) {\n            g3.add_edge(i,\
    \ j);\n        }\n    }\n    auto vc_ = g3.minimumVertexCover();\n    if (sz(vc_.first)\
    \ + sz(vc_.second) > 2 * (k - sz(ans))) {\n        return {-1};\n    }\n    vector<int>\
    \ cnt(sz(g2));\n    for (int v : vc_.first) {\n        cnt[v]++;\n    }\n    for\
    \ (int v : vc_.second) {\n        cnt[v]++;\n    }\n    vector<int> v12;\n   \
    \ for (int i = 0; i < sz(g2); i++) {\n        if (cnt[i] == 2) {\n           \
    \ ans.push_back(vs2[i]);\n            used[i] = 1;\n        } else if (cnt[i]\
    \ == 1) {\n            v12.push_back(i);\n        }\n    }\n    auto g4 = subgraph(g2,\
    \ v12);\n    for (auto &el : g4) {\n        unq(el);\n    }\n    assert(sz(g4)\
    \ <= 2 * k);\n\n    // Construct vertex cover on small graph\n    auto ans2 =\
    \ vertexCover(g4, k - sz(ans));\n    // auto ans2 = vertexCover2(g4);\n    if\
    \ ((ans2.size() == 1 && ans2[0] == -1) || sz(ans2) > k - sz(ans)) {\n        return\
    \ {-1};\n    }\n    for (int el : ans2) {\n        ans.push_back(vs2[v12[el]]);\n\
    \    }\n\n    // check that ans is vertex cover (not checking if it is minimum)\n\
    \    used.assign(n, 0);\n    for (int el : ans) {\n        used[el] = 1;\n   \
    \ }\n    for (int i = 0; i < n; i++) {\n        for (int j : g[i]) {\n       \
    \     assert(used[i] || used[j]);\n        }\n    }\n    return ans;\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  - graph/graph-utils.hpp
  - graph/bipartite-graph.hpp
  - graph/maxflow.hpp
  - ds/queue.hpp
  - template/util.hpp
  - template/macro.hpp
  - graph/vertex-cover.hpp
  - graph/maximum-independent-set.hpp
  isVerificationFile: false
  path: graph/vertex-cover-small-ans.hpp
  requiredBy: []
  timestamp: '2023-02-25 13:28:05+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/vertex-cover-small-ans.hpp
layout: document
redirect_from:
- /library/graph/vertex-cover-small-ans.hpp
- /library/graph/vertex-cover-small-ans.hpp.html
title: graph/vertex-cover-small-ans.hpp
---
