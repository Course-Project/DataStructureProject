//
//  MST.h
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#ifndef __DataStructure__MST__
#define __DataStructure__MST__

#include <iostream>
#include <vector>
#include <map>
#include <string>

struct Edge {
    std::string l, r;
    size_t length;
};
typedef struct Edge Edge;

class MST {
private:
    std::vector<Edge> edges;
    std::map<std::string, size_t> vertexMap;
    
    std::vector<Edge> result;
    
    size_t startVertex;
    size_t ans;
    
    size_t *lowcost, *closest;
    size_t **cost;
    
    void addResultEdge(const size_t &l, const size_t &r);
    
    bool containsVertex(const Edge &edge, const size_t &n);
    
public:
    void addVertex(std::string &c);
    void addEdge(const std::string &l, const std::string &r, const size_t &length);
    void setStartVertex(std::string &n);
    void printResult();
    
    void prim();
};

#endif /* defined(__DataStructure__MST__) */
