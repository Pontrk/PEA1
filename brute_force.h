#ifndef PEA1_BRUTE_FORCE_H
#define PEA1_BRUTE_FORCE_H
#include "adjacency_matrix.h"
#include <chrono>
#include <iostream>
#include <vector>

class Brute_Force {
public:
    Brute_Force();
    void getFromMatrix(Adjacency_Matrix& adjacencyMatrix);
    vector<int> findBestPath(int startNode);
    vector<int> findBestPathAll();
    int calculatePathCost(const std::vector<int>& path);
private:
    vector<vector<int>> data;
};


#endif //PEA1_BRUTE_FORCE_H
