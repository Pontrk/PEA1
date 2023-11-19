#ifndef PEA1_HELD_KARP_H
#define PEA1_HELD_KARP_H

#include "adjacency_matrix.h"
#include <vector>
#include <map>
class HeldKarpTSP {
public:
    explicit HeldKarpTSP(Adjacency_Matrix adjacencyMatrix);
    int FindMinHamiltonianCycle();
    void PrintPath();

private:
    std::vector<std::vector<int>> dist;
    std::map<std::pair<int, int>, int> parent;
    int n;
    static const int INF;
    std::vector<int> path;
};

#endif //PEA1_HELD_KARP_H
