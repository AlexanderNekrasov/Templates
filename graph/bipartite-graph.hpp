#pragma once

#include "maxflow.hpp"

struct BipartiteGraph: MaxFlow<ll> {
    int L, R, s, t;
    bool was_flow;

    explicit BipartiteGraph(int N, int M)
        : MaxFlow<ll>(N + M + 2),
          L(N),
          R(M),
          s(N + M),
          t(N + M + 1),
          was_flow(false) {
        for (int i = 0; i < L; i++) {
            MaxFlow<ll>::add_edge(s, i, 1); 
        }
        for (int i = 0; i < R; i++) {
            MaxFlow<ll>::add_edge(i + L, t, 1);
        }
    }

    int add_edge(int a, int b, ll c = 1) {
        assert(0 <= a && a < L);
        assert(0 <= b && b < R);
        return MaxFlow<ll>::add_edge(a, b + L, c);
    }

    ll flow() {
        was_flow = true;
        return MaxFlow<ll>::flow(s, t);
    }

    pair<vector<int>, vector<int>> minimumVertexCover() {
        if (!was_flow)
            flow();
        vector<bool> used = dfsUsed();
        vector<int> lv, rv;
        for (int i = 0; i < L; i++) {
            if (!used[i]) {
                lv.push_back(i);
            }
        }
        for (int i = 0; i < R; i++) {
            if (used[i + L]) {
                rv.push_back(i);
            }
        }
        return {lv, rv};
    }

    private:
    vector<bool> dfsUsed() {
        vector<vector<int>> g(L + R);
        vector<bool> matched(L);
        for (auto &e : MaxFlow<ll>::edges()) {
            if (e.from == s || e.to == t)
                continue;
            if (e.flow > 0) {
                g[e.to].push_back(e.from);
                matched[e.from] = true;
            } else {
                g[e.from].push_back(e.to);
            }
        }
        vector<bool> used(L + R);
        auto dfs = [&](auto dfs, int v) -> void {
            used[v] = 1;
            for (int u : g[v])
                if (!used[u])
                    dfs(dfs, u);
        };
        for (int i = 0; i < L; i++) {
            if (!matched[i] && !used[i]) {
                dfs(dfs, i);
            }
        }
        return used;
    }
};
