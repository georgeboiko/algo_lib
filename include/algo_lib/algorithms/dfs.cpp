#include "dfs.h"
 
void dfsForDfs(graph g, int startVertex, std::vector<std::vector<std::pair<int,int>>>& matrix, std::vector<int>& colors, std::vector<int>& topSort){
    colors[startVertex] = 1;
    for (auto vertex : matrix[startVertex]) {
        if (colors[vertex.first] == 0) dfsForDfs(g, vertex.first, matrix, colors, topSort);
    }
    colors[startVertex] = 2;
    topSort.push_back(startVertex);
}

std::vector<int> dfs(graph g, int startVertex){
    std::vector<std::vector<std::pair<int, int>>> matrix = g.getMatrix();
    std::vector<int> colors(matrix.size()), topSort;
    dfsForDfs(g, startVertex, matrix, colors, topSort);
    return topSort;
}