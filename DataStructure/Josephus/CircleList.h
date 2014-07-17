//
//  CircleList.h
//  DataStructure
//
//  Created by Tom Hu on 7/16/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#ifndef __DataStructure__CircleList__
#define __DataStructure__CircleList__

#include <iostream>

struct Node {
    size_t index;
    Node *next;
    
    Node(const size_t &index) {
        this->index = index;
    }
};

class CircleList {
private:
    Node *_head;
    Node *_pre;
    Node *_current;
    size_t _size;
    
public:
    CircleList(const size_t &size, const size_t &start);
    size_t size();
    size_t next();
    size_t deleteCurrent();
    void print();
};

#endif /* defined(__DataStructure__CircleList__) */
