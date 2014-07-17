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
    std::cout << "请输入生死游戏的总人数：";
    size_t n;
    std::cin >> n;
    
    std::cout << "请输入游戏开始的位置：";
    size_t p;
    std::cin >> p;
    
    std::cout << "请输入死亡数字：";
    size_t evilNumber;
    std::cin >> evilNumber;
    
    std::cout << "请输入剩余的生者人数：";
    size_t r;
    std::cin >> r;
    
    this->circleList = new CircleList(n, p);
    
    this->circleList->print();
    
    int con = 0;
    while (this->circleList->size() > r) {
        int i = 1;
        while (i < evilNumber) {
            this->circleList->next();
            i++;
        }
        std::cout << "第" << ++con << "个死者的位置是：" << this->circleList->deleteCurrent() << std::endl;
    }
    
    this->circleList->print();
}

Cli::Cli() {
    this->start();
}