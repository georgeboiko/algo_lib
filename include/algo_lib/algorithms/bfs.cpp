#include "bfs.h"
#include <queue>

std::vector<int> bfs(graph g, int startVertexNumber){
    std::vector<std::vector<std::pair<int,int>>> matrix = g.getMatrix();
    std::vector<int>distances(matrix.size(), INF);
    distances[startVertexNumber] = 0;
    std::queue<int> q;
    q.push(startVertexNumber);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : matrix[u]) {
            if (distances[v.first] > distances[u] + 1) {
                distances[v.first] = distances[u] + 1;
                q.push(v.first);
            }
        }
    }
    return distances;
}