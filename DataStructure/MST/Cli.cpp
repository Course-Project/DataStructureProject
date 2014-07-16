//
//  Cli.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/15/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Cli.h"

using namespace NO_8;

void Cli::start() {
    size_t nodesCount;
    std::cout << "Please enter the number of nodes: ";
    std::cin >> nodesCount;
    std::cout << "Please enter nodes' name: ";
    for (int i = 0; i < nodesCount; i++) {
        std::string in;
        std::cout << "> ";
        std::cin >> in;
        
        this->mst.addVertex(in);
    }
    
    std::cout << "Please enter the edge information: " << std::endl;
    while (true) {
        std::string l, r;
        size_t length;
        std::cout << "> ";
        std::cin >> l >> r >> length;
        
        if (l == "?" || r == "?") {
            break;
        }
        
        this->mst.addEdge(l, r, length);
    }
    
    std::cout << "Please enter the start node: " << std::endl;
    std::string startVertex;
    std::cin >> startVertex;
    
    this->mst.setStartVertex(startVertex);
    
    this->mst.prim();
    
    this->mst.printResult();
}