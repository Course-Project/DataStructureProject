//
//  Cli.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/16/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Cli.h"

using namespace NO_2;

void Cli::start() {
    std::cout << "> ";
    std::cout << "Please enter the number of players: ";
    
    size_t n;
    std::cin >> n;
    
    this->circleList = new CircleList(n);
}