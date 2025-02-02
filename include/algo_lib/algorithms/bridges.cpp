#include "bridges.h"
#include <set>
#include <map>
#include <utility>
#include <iostream>

void dfsForBridges(int u, int p, std::vector<int>& colors, std::vector<std::vector<std::pair<int,int>>>& matrix,
 std::vector<int>& d, std::vector<int>& h, std::set<edge>& st, std::map<std::pair<int,int>, std::vector<edge>>& mp) {
    colors[u] = 1;
    d[u] = h[u] = (p == -1 ? 0 : h[p] + 1);
    for (auto& v : matrix[u]) {
        if (v.first != p) {
            if (colors[v.first] == 1) d[u] = std::min(d[u], h[v.first]);
            else {
                dfsForBridges(v.first, u, colors, matrix, d, h, st, mp);
                d[u] = std::min(d[u], d[v.first]);
            }
            if (h[u] < d[v.first] && mp[{ std::min(u,v.first), std::max(u,v.first) }].size() == 1) {
                st.insert(mp[{ std::min(u,v.first), std::max(u,v.first) }][0]);
            }
        }
    }
}

std::vector<edge> bridges(graph g){
    if (g.getDirected()){
        std::cout << "Graph is directed! Error!\n";
        return {};
    }
    std::vector<edge> edges = g.getEdges();
    std::set<edge> st;
    std::map<std::pair<int,int>, std::vector<edge>> mp;
    std::vector<std::vector<std::pair<int, int>>> matrix = g.getMatrix();
    std::vector<int> colors(matrix.size()), h(matrix.size()), d(matrix.size());
    for (auto& elem : edges){
        auto vertexes = elem.getVertexes();
        mp[{std::min(vertexes.first, vertexes.second), std::max(vertexes.first, vertexes.second)}].push_back(elem);
    }
    for (int i = 0; i < matrix.size(); ++i){
        if (colors[i] == 0) dfsForBridges(i, -1, colors, matrix, d, h, st, mp);
    }
    std::vector<edge> res;
    for (auto& i : st) res.push_back(i);
    return res;
}