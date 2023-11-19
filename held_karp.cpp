#include "held_karp.h"
#include <iostream>
#include <limits>
#include <vector>

const int HeldKarpTSP::INF = std::numeric_limits<int>::max();

HeldKarpTSP::HeldKarpTSP(Adjacency_Matrix adjacencyMatrix) {
    dist = adjacencyMatrix.getMatrix();
    n = dist.size();

    // Zamiana -1 na INF
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == -1) {
                dist[i][j] = INF;
            }
        }
    }
}

int HeldKarpTSP::FindMinHamiltonianCycle() {
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; ++v) {
                if (!(mask & (1 << v)) || dist[v][u] == INF) continue;

                int newMask = mask ^ (1 << u);
                int newDist = dp[newMask][v] + dist[v][u];

                if (newDist < dp[mask][u]) {
                    dp[mask][u] = newDist;
                    parent[{mask, u}] = v;
                }
            }
        }
    }

    int minCost = INF;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[(1 << n) - 1][i] < minCost) {
            minCost = dp[(1 << n) - 1][i];
            last = i;
        }
    }

    if (last == -1) {
        return -1;
    }

    // Odtwarzanie ścieżki
    path.clear();
    int mask = (1 << n) - 1;
    while (mask != 0 && last != -1) {
        path.push_back(last);
        int newLast = parent[{mask, last}];
        mask ^= (1 << last);
        last = newLast;
    }
    path.push_back(0);
    std::reverse(path.begin(), path.end());

    return minCost;
}
void HeldKarpTSP::PrintPath() {
    std::cout << "Ścieżka: ";
    for (int v : path) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}