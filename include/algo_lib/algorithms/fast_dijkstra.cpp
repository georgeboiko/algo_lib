#include "fast_dijkstra.h"
#include <queue>
#include <iostream>

std::vector<int> fast_dijkstra(graph g, int startVertex){
    if (!g.getDirected()){
        std::cout << "Graph is not directed! Error!\n";
        return {};
    }
    std::vector<std::vector<std::pair<int, int>>> matrix = g.getMatrix();
    std::vector<int>d(matrix.size(), INF), p(matrix.size());
    d[startVertex] = 0;
    std::priority_queue<std::pair<int,int>> q;
    q.push({ 0, startVertex });
    while (!q.empty()) {
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v]) continue;
        for (auto j : matrix[v]) {
            if (d[v] + j.second < d[j.first]) {
                d[j.first] = d[v] + j.second;
                p[j.first] = v;
                q.push({ -d[j.first], j.first });
            }
        }
    }
    return d;
}