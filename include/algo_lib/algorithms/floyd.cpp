#include "floyd.h"
#include <iostream>

std::vector<std::vector<int>> floyd(graph g){
    if (!g.getDirected()){
        std::cout << "Graph is not directed! Error!\n";
        return {};
    }
    std::vector<std::vector<std::pair<int,int>>> matrix = g.getMatrix();
    std::vector<std::vector<int>> gr(matrix.size(), std::vector<int>(matrix.size(), INF));
    for (int i = 0; i < matrix.size(); ++i) gr[i][i] = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j){
            gr[i][matrix[i][j].first] = std::min(gr[i][matrix[i][j].first], matrix[i][j].second);
        }
    }
    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                gr[i][j] = std::min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }
    return gr;
}