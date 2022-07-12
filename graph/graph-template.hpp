#pragma once

using UnweightedGraph = vector<vector<int>>;

UnweightedGraph graph(int N, int M = -1, bool is_directed = false, bool is_1origin = true) {
    UnweightedGraph g((size_t)N);
    if (M == -1)
        M = N - 1;
    for (int _ = 0; _ < M; _++) {
        int x, y;
        cin >> x >> y;
        if (is_1origin) {
            x--;
            y--;
        }
        g[(size_t) x].push_back(y);
        if (!is_directed)
            g[(size_t) y].push_back(x);
    }
    return g;
}
