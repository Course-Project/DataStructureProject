//
//  Cli.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/16/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include <iostream>
#include "Cli.h"

using namespace NO_2;
using namespace std;

void Cli::start() {
    cout << "请输入生死游戏的总人数：";
    size_t n;
    cin >> n;
    
    cout << "请输入游戏开始的位置：";
    size_t p;
    cin >> p;
    
    cout << "请输入死亡数字：";
    size_t evilNumber;
    cin >> evilNumber;
    
    cout << "请输入剩余的生者人数：";
    size_t r;
    cin >> r;
    
    this->circleList = new CircleList(n, p);
    
    cout << endl;
    
    int con = 0;
    while (this->circleList->size() > r) {
        int i = 1;
        while (i < evilNumber) {
            this->circleList->next();
            i++;
        }
        cout << "第" << ++con << "个死者的位置是：" << this->circleList->deleteCurrent() << endl;
    }
    
    cout << endl;
    cout << "剩余的生者位置为：" << endl;
    
    this->circleList->print();
}

Cli::Cli() {
    this->start();
}