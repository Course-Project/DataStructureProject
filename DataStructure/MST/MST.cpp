//
//  MST.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "MST.h"

#pragma mark Edge
bool MST::containsNode(const Edge &edge, const size_t &n) {
    return this->nodeMap[edge.l] == n || this->nodeMap[edge.r] == n;
}

void MST::addResultEdge(const size_t &l, const size_t &r) {
    std::vector<Edge>::iterator itr = this->edges.begin();
    for (; itr != this->edges.end(); itr++) {
        if (this->containsNode(*itr, l) && this->containsNode(*itr, r)) {
            this->result.push_back(*itr);
        }
    }
}

#pragma mark -
#pragma mark MST
void MST::addNode(std::string &c) {
    this->nodeMap[c] = this->nodeMap.size();
}

void MST::addEdge(const std::string &l, const std::string &r, const size_t &length) {
    if (!this->cost) {
        size_t n = this->nodeMap.size();
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
    
    this->cost[this->nodeMap[l]][this->nodeMap[r]] = length;
    this->cost[this->nodeMap[r]][this->nodeMap[l]] = length;
}

void MST::setStartNode(std::string &n) {
    this->startNode = this->nodeMap[n];
    
    this->lowcost = (size_t *)malloc(sizeof(size_t) * this->nodeMap.size());
    this->closest = (size_t *)malloc(sizeof(size_t) * this->nodeMap.size());
}

void MST::printResult() {
    std::cout << "Ans: " << this->ans << std::endl;
    std::vector<Edge>::iterator itr = this->result.begin();
    for (; itr != this->result.end(); itr++) {
        std::cout << itr->l << " --(" << itr->length << ")-- " << itr->r << std::endl;
    }
}

void MST::prime() {
    this->ans = 0;
    size_t minLength, minNode = 0;
    size_t n = this->nodeMap.size();
    for (int i = 0; i < n; i++) {
        this->lowcost[i] = this->cost[this->startNode][i];
        this->closest[i] = this->startNode;
    }
    for (int i = 0; i < n - 1; i++) {
        minLength = 0xffffffff;
        for (int j = 0; j < n; j++) {
            if (this->lowcost[j] && minLength > lowcost[j]) {
                minLength = lowcost[j];
                minNode = j;
            }
        }
        
        this->ans += this->lowcost[minNode];
        this->lowcost[minNode] = 0; // (minNode, closest[minNode])
        
        this->addResultEdge(minNode, this->closest[minNode]);
        
        for (int j = 0; j < n; j++) {
            if (this->cost[minNode][j] < this->lowcost[j]) {
                this->lowcost[j] = this->cost[j][minNode];
                this->closest[j] = minNode;
            }
        }
    }
}
