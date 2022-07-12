#pragma once
#include "../ds/queue.hpp"

template<typename T>
struct MaxFlow {
    explicit MaxFlow(int n) : n(n), g(n) {}

    int add_edge(int from, int to, T cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        int m = sz(pos);
        pos.push_back({from, sz(g[from])});
        int sz_from = sz(g[from]);
        int sz_to = sz(g[to]);
        if (from == to) {
            sz_to++;
        }
        g[from].push_back({to, sz_to, cap});
        g[to].push_back({from, sz_from, 0});
        return m;
    }

    struct edge {
        int from, to;
        T cap, flow;
    };

    edge get_edge(int i) {
        assert(0 <= i && i < sz(pos));
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return {_re.to, _e.to, _e.cap + _re.cap, _re.cap};
    }

    vector<edge> edges() {
        int m = sz(pos);
        vector<edge> ans;
        for (int i = 0; i < m; i++) {
            ans.push_back(get_edge(i));
        }
        return ans;
    }

    T flow(int s, int t) {
        return flow(s, t, numeric_limits<T>::max());
    }

    T flow(int s, int t, T flow_limit) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);
        vector<int> level(n), iter(n);
        simple_queue<int> q;

        auto bfs = [&]() {
            fill(all(level), -1);
            level[s] = 0;
            q.clear();
            q.push(s);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    q.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, T up) {
            if (v == s) {
                return up;
            }
            T res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < sz(g[v]); i++) {
                auto &e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                T d =
                    self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up)
                    return res;
            }
            level[v] = n;
            return res;
        };

        T flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1)
                break;
            fill(all(iter), 0);
            T f = dfs(dfs, t, flow_limit - flow);
            if (!f)
                break;
            flow += f;
        }
        return flow;
    }

    private:
    int n;
    vector<pair<int, int>> pos;
    struct _edge {
        int to, rev;
        T cap;
    };
    vector<vector<_edge>> g;
};
