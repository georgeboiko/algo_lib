#include "graph.h"
#include "../edge/edge.h"
#include <algorithm>

void graph::addEdge(edge edge){
    this->edges.push_back(edge);
    auto vertexes = edge.getVertexes();
    if (std::max(vertexes.first, vertexes.second) < this->matrix.size()){
        this->matrix[vertexes.first].push_back({vertexes.second, edge.getWeight()});
        if (!this->isDirected) this->matrix[vertexes.second].push_back({vertexes.first, edge.getWeight()});
    }
    else{
        this->matrix = this->getMatrixFromList(this->edges);
    }
}

void graph::removeEdge(edge edge){
    for (auto& elem: this->edges){
        if (elem == edge){
            auto vertexes = edge.getVertexes();
            this->matrix[vertexes.first].erase(find(this->matrix[vertexes.first].begin(), this->matrix[vertexes.first].end(), std::make_pair(vertexes.second, elem.getWeight())));
            if (!this->isDirected) this->matrix[vertexes.second].erase(find(this->matrix[vertexes.second].begin(), this->matrix[vertexes.second].end(), std::make_pair(vertexes.first, elem.getWeight())));
            this->edges.erase(find(edges.begin(), edges.end(), edge));
            break;
        }
    }
}
    
std::vector<std::vector<std::pair<int,int>>> graph::getMatrixFromList(std::vector<edge> edges){
    int maximalVertexNumber = -1;
    for (auto& elem: this->edges){
        maximalVertexNumber = std::max(elem.getVertexes().first, maximalVertexNumber);
        maximalVertexNumber = std::max(elem.getVertexes().second, maximalVertexNumber);
    }
    std::vector<std::vector<std::pair<int,int>>> result(maximalVertexNumber+1);
    for (auto& elem: this->edges){
        auto vertexes = elem.getVertexes();
        result[vertexes.first].push_back({vertexes.second, elem.getWeight()});
        if (!this->isDirected) result[vertexes.second].push_back({vertexes.first, elem.getWeight()});
    }
    return result;
}