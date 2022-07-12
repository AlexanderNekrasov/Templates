#pragma once

#include "graph-template.hpp"

UnweightedGraph subgraph(UnweightedGraph g, vector<int> vs) {
    sort(all(vs));
    UnweightedGraph g2(sz(vs));
    for (int i = 0; i < (int) vs.size(); i++) {
        for (int j : g[vs[i]]) {
            auto it = lower_bound(all(vs), j);
            if (it != vs.end() && *it == j) {
                g2[i].push_back(lower_bound(all(vs), j) - vs.begin());
            }
        }
    }
    return g2;
}
