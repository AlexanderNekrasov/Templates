#pragma once

#include "graph-template.hpp"
#include "graph-utils.hpp"
#include "bipartite-graph.hpp"
#include "../template/util.hpp"
#include "vertex-cover.hpp"

// Finds vertex cover on big graphs, where it is known that 
// size of vertex cover is small, works in O((n+m)log(n)+k^3+1.63^k)
// returns {-1} if vertex cover size is greater than k.
vector<int> vertexCoverSmallAns(UnweightedGraph g, int k) {
    int n = (int) g.size();
    // **Buss's reduction**
    // Every vertex with a degree > k should be in the vertex cover
    vector<int> ans;
    vector<char> used(n);
    for (int i = 0; i < n; i++) {
        if ((int) g[i].size() > k) {
            used[i] = 1;
            ans.push_back(i);
        }
    }
    // g2 = g \ ans \ { v \in V | deg v = 0 }
    vector<int> vs2;
    for (int i = 0; i < n; i++) {
        if (!used[i] && any_of(all(g[i]), [&](int v) { return !used[v]; }))
            vs2.push_back(i);
    }
    UnweightedGraph g2 = subgraph(g, vs2);
    for (auto &el : g2) {
        unq(el);
    }
    // Now g2 should contain at most k+k^2 vertices and at most k^2 edges
    {
        int cntEdges = 0;
        for (int i = 0; i < sz(g2); i++)
            cntEdges += g2[i].size();
        cntEdges >>= 1;
        if (sz(g2) > k + k * k || cntEdges > k * k) {
            return {-1};
        }
    }
    // Construct a solution to LP problem using vertex cover on bipartite graph 
    BipartiteGraph g3(sz(g2), sz(g2));
    for (int i = 0; i < sz(g2); i++) {
        for (int j : g2[i]) {
            g3.add_edge(i, j);
        }
    }
    auto vc_ = g3.minimumVertexCover();
    if (sz(vc_.first) + sz(vc_.second) > 2 * (k - sz(ans))) {
        return {-1};
    }
    vector<int> cnt(sz(g2));
    for (int v : vc_.first) {
        cnt[v]++;
    }
    for (int v : vc_.second) {
        cnt[v]++;
    }
    vector<int> v12;
    for (int i = 0; i < sz(g2); i++) {
        if (cnt[i] == 2) {
            ans.push_back(vs2[i]);
            used[i] = 1;
        } else if (cnt[i] == 1) {
            v12.push_back(i);
        }
    }
    auto g4 = subgraph(g2, v12);
    for (auto &el : g4) {
        unq(el);
    }
    assert(sz(g4) <= 2 * k);

    // Construct vertex cover on small graph
    auto ans2 = vertexCover(g4, k - sz(ans));
    // auto ans2 = vertexCover2(g4);
    if ((ans2.size() == 1 && ans2[0] == -1) || sz(ans2) > k - sz(ans)) {
        return {-1};
    }
    for (int el : ans2) {
        ans.push_back(vs2[v12[el]]);
    }

    // check that ans is vertex cover (not checking if it is minimum)
    used.assign(n, 0);
    for (int el : ans) {
        used[el] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            assert(used[i] || used[j]);
        }
    }
    return ans;
}
