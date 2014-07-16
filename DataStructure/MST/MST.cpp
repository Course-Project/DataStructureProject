//
//  MST.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "MST.h"

#pragma mark Edge
bool MST::containsVertex(const Edge &edge, const size_t &n) {
    return this->vertexMap[edge.l] == n || this->vertexMap[edge.r] == n;
}

void MST::addResultEdge(const size_t &l, const size_t &r) {
    std::vector<Edge>::iterator itr = this->edges.begin();
    for (; itr != this->edges.end(); itr++) {
        if (this->containsVertex(*itr, l) && this->containsVertex(*itr, r)) {
            this->result.push_back(*itr);
        }
    }
}

#pragma mark -
#pragma mark MST
void MST::addVertex(std::string &c) {
    this->vertexMap[c] = this->vertexMap.size();
}

void MST::addEdge(const std::string &l, const std::string &r, const size_t &length) {
    if (!this->cost) {
        size_t n = this->vertexMap.size();
        this->cost = (size_t **)malloc(sizeof(size_t *) * n);
        for (int i = 0; i < n; i++) {
            this->cost[i] = (size_t *)malloc(sizeof(size_t) * n);
        }
    }
    
    Edge edge = {
        l,
        r,
        length
    };
    this->edges.push_back(edge);
    
    this->cost[this->vertexMap[l]][this->vertexMap[r]] = length;
    this->cost[this->vertexMap[r]][this->vertexMap[l]] = length;
}

void MST::setStartVertex(std::string &n) {
    this->startVertex = this->vertexMap[n];
    
    this->lowcost = (size_t *)malloc(sizeof(size_t) * this->vertexMap.size());
    this->closest = (size_t *)malloc(sizeof(size_t) * this->vertexMap.size());
}

void MST::printResult() {
    std::cout << "Ans: " << this->ans << std::endl;
    std::vector<Edge>::iterator itr = this->result.begin();
    for (; itr != this->result.end(); itr++) {
        std::cout << itr->l << " --(" << itr->length << ")-- " << itr->r << std::endl;
    }
}

void MST::prim() {
    this->ans = 0;
    size_t minLength, minVertex = 0;
    size_t n = this->vertexMap.size();
    for (int i = 0; i < n; i++) {
        this->lowcost[i] = this->cost[this->startVertex][i];
        this->closest[i] = this->startVertex;
    }
    for (int i = 0; i < n - 1; i++) {
        minLength = 0xffffffff;
        for (int j = 0; j < n; j++) {
            if (this->lowcost[j] && minLength > lowcost[j]) {
                minLength = lowcost[j];
                minVertex = j;
            }
        }
        
        this->ans += this->lowcost[minVertex];
        this->lowcost[minVertex] = 0; // (minVertex, closest[minVertex])
        
        this->addResultEdge(minVertex, this->closest[minVertex]);
        
        for (int j = 0; j < n; j++) {
            if (this->cost[minVertex][j] < this->lowcost[j]) {
                this->lowcost[j] = this->cost[j][minVertex];
                this->closest[j] = minVertex;
            }
        }
    }
}
