#include "ford_bellman.h"
#include <iostream>

std::vector<int> ford_bellman(graph g, int startVertex){
    if (!g.getDirected()){
        std::cout << "Graph is not directed! Error!\n";
        return {};
    }
    int maximalVertexNumber = -1;
    for (auto& elem: g.getEdges()){
        maximalVertexNumber = std::max(elem.getVertexes().first, maximalVertexNumber);
        maximalVertexNumber = std::max(elem.getVertexes().second, maximalVertexNumber);
    }
    std::vector<int>d(maximalVertexNumber+1, INF);
    d[startVertex] = 0;
    std::vector<edge> e = g.getEdges();
    for (int i = 0; i < maximalVertexNumber; ++i) {
        for (int j = 0; j < e.size(); ++j) {
            if (d[e[j].getVertexes().first] != INF) d[e[j].getVertexes().second] = std::min(d[e[j].getVertexes().second], d[e[j].getVertexes().first] + e[j].getWeight());
        }
    }
    return d;
}