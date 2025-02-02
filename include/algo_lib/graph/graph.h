#pragma once

#include <vector>
#include "../edge/edge.h"

class graph
{
    public:
        graph(){}
        graph(std::vector<edge> edges){
            this->edges = edges;
            this->isDirected = false;
            this->matrix = this->getMatrixFromList(edges);
        };
        graph(std::vector<edge> edges, bool isDirected){
            this->edges = edges;
            this->isDirected = isDirected;
            this->matrix = this->getMatrixFromList(edges);
        };

        void addEdge(edge edge);
        void removeEdge(edge edge);

        std::vector<edge> getEdges(){
            return this->edges;
        };
        void setEdges(std::vector<edge> edges){
            this->edges = edges;
            this->matrix = this->getMatrixFromList(edges);
        };

        std::vector<std::vector<std::pair<int,int>>> getMatrix(){
            return this->matrix;
        };

        void setDirected(bool val){
            this->isDirected = val;
        }

        bool getDirected(){
            return this->isDirected;
        }
    
    private:
        bool isDirected;

        std::vector<edge> edges;
        std::vector<std::vector<std::pair<int, int>>> matrix;

        std::vector<std::vector<std::pair<int,int>>> getMatrixFromList(std::vector<edge> edges);
};