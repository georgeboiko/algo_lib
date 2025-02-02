#pragma once

#include <utility>
#include "../constants.h"

class edge
{
    public:
        edge(){
            this->vertex1 = -INF;
            this->vertex2 = -INF;
            this->weight = 0;
        };
        edge(int vertex1, int vertex2){
            this->vertex1 = vertex1;
            this->vertex2 = vertex2;
            this->weight = 0;
        };
        edge(int vertex1, int vertex2, int weight){
            this->vertex1 = vertex1;
            this->vertex2 = vertex2;
            this->weight = weight;
        };

        edge& operator = (const edge& edge){
            this->vertex1 = edge.vertex1;
            this->vertex2 = edge.vertex2;
            this->weight = edge.weight;
            return *this;
        };
        bool operator == (const edge& edge){
            return ((this->vertex1 == edge.vertex1) && (this->vertex2 == edge.vertex2) && (this->weight == edge.weight));
        };
        bool operator != (const edge& edge){
            return !((this->vertex1 == edge.vertex1) && (this->vertex2 == edge.vertex2) && (this->weight == edge.weight));
        };
        bool operator < (const edge& edge) const{
            return (this->weight < edge.weight);
        };
        bool operator > (const edge& edge){
            return (this->weight > edge.weight);
        };

        void setVertexes(int vertex1, int vertex2){
            this->vertex1 = vertex1;
            this->vertex2 = vertex2;
        };
        std::pair<int, int> getVertexes(){
            return {this->vertex1, this->vertex2};
        };

        void setWeight(int weight){
            this->weight = weight;
        };
        int getWeight(){
            return this->weight;
        };

    private:
        int vertex1, vertex2, weight;
};