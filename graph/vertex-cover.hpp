#pragma once

#include "graph-template.hpp"
#include "../template/macro.hpp"
#include "maximum-independent-set.hpp"

vector<int> vertexCover2(const UnweightedGraph &g) {
    int n = sz(g);
    vector<int> used(n, 1);
    auto is = maximumIndependentSet(g);
    for (int el : is) {
        used[el] = 0;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (used[i])
            ans.push_back(i);
    return ans;
}

void vertexCoverErase(vector<vector<bool>> &g, vector<int> &vs, int u) {
    int n = sz(g);
    for (int i = 0; i < n; i++) {
        if (i != u) {
            g[i].erase(g[i].begin() + u);
        }
    }
    vs.erase(vs.begin() + u);
    g.erase(g.begin() + u);
}

void vertexCoverClean(vector<vector<bool>> &g, vector<int> &vs) {
    int n = sz(g);
    for (int i = n - 1; i >= 0; i--) {
        int d = accumulate(all(g[i]), 0);
        if (d == 0)
            vertexCoverErase(g, vs, i);
    }
}

pair<int, vector<int>> vertexCoverAns(vector<vector<bool>> &g, int k, vector<int> &vs, vector<int> &cur_ans) {
    if (k < 0)
        return {1e9, {-1}};
    if (g.empty())
        return {0, cur_ans};
    if (k == 0)
        return {1e9, {-1}};
    int n = sz(g);
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        deg[i] = accumulate(all(g[i]), 0);
    }
    int w = 0;
    for (int i = 1; i < n; i++) {
        if (deg[w] < deg[i])
            w = i;
    }
    pair<int, vector<int>> ans = {1e9, {-1}};
    auto g1 = g;
    auto vs1 = vs;
    auto cur_ans1 = cur_ans;
    cur_ans1.push_back(vs[w]);
    vertexCoverErase(g1, vs1, w);
    vertexCoverClean(g1, vs1);
    auto ans1 = vertexCoverAns(g1, k - 1, vs1, cur_ans1);
    ans1.first++;
    ans = min(ans, ans1);
    auto g2 = g;
    auto vs2 = vs;
    auto cur_ans2 = cur_ans;
    for (int j = n - 1; j >= 0; j--) {
        if (g[w][j]) {
            vertexCoverErase(g2, vs2, j);
            cur_ans2.push_back(vs[j]);
        }
    }
    vertexCoverClean(g2, vs2);
    auto ans2 = vertexCoverAns(g2, k - deg[w], vs2, cur_ans2);
    ans2.first += deg[w];
    ans = min(ans, ans2);
    return ans;
}

vector<int> vertexCover(const UnweightedGraph &g, int k) {
    int n = sz(g);
    vector<vector<bool>> g2(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            g2[i][j] = 1;
        }
    }
    vector<int> allvs(n);
    iota(all(allvs), 0);
    vector<int> cur_ans;
    auto ans = vertexCoverAns(g2, k, allvs, cur_ans);
    if (ans.first == 1000000000) {
        return {-1};
    }
    return ans.second;
}
