#include "articulation_points.h"
#include <set>
#include <iostream>

void dfsForArticularPoints(int u, int p, std::vector<int>& colors, std::vector<std::vector<std::pair<int,int>>>& matrix,
std::vector<int>& h, std::vector<int>& d, std::set<int>& st) {
    colors[u] = 1;
    d[u] = h[u] = (p == -1 ? 0 : h[p] + 1);
    int children = 0;
    for (auto& v : matrix[u]) {
        if (v.first != p) {
            if (colors[v.first] == 1) d[u] = std::min(d[u], h[v.first]);
            else {
                dfsForArticularPoints(v.first, u, colors, matrix, h, d, st);
                d[u] = std::min(d[u], d[v.first]);
                if (h[u] <= d[v.first] && p != -1) {
                    st.insert(u);
                }
                ++children;
            }
        }
    }
    if (p == -1 && children >= 2) st.insert(u);
}

std::vector<int> articulation_points(graph g){
    if (g.getDirected()){
        std::cout << "Graph is directed! Error!\n";
        return {};
    }
    std::vector<std::vector<std::pair<int,int>>> matrix = g.getMatrix();
    std::vector<int> colors(matrix.size()), h(matrix.size()), d(matrix.size());
    std::set<int> st;
    
    for (int i = 0; i < matrix.size(); ++i){
        if (colors[i] == 0) dfsForArticularPoints(i, -1, colors, matrix, h, d, st);
    }

    std::vector<int> result;
    for (auto& i : st) result.push_back(i);
    return result;
}