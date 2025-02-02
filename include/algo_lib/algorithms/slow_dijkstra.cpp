#include "slow_dijkstra.h"
#include <iostream>

std::vector<int> slow_dijkstra(graph g, int startVertex){
    if (!g.getDirected()){
        std::cout << "Graph is not directed! Error!\n";
        return {};
    }
    std::vector<std::vector<std::pair<int, int>>> matrix = g.getMatrix();
    std::vector<int>d(matrix.size(), INF);
    d[startVertex] = 0;
    std::vector<int>used(matrix.size());
    for (int i = 0; i < matrix.size(); ++i) {
        int v = -1;
        for (int j = 0; j < matrix.size(); ++j) {
            if (used[j] == 0 && (v == -1 || d[j] < d[v])) v = j;
        }
        if (d[v] == INF) break;
        used[v] = 1;
        for (auto j : matrix[v]) {
            if (d[v] + j.second < d[j.first]) {
                d[j.first] = d[v] + j.second;
            }
        }
    }
    return d;
}