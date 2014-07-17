//
//  CircleList.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/16/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "CircleList.h"

CircleList::CircleList(const size_t &size, const size_t &start) {
    this->_size = size;
    this->_head = new Node(0);
    this->_current = this->_head;
    this->_pre = this->_head;
    for (int i = 1; i < size; i++) {
        this->_pre->next = new Node(i);
        this->_pre = this->_pre->next;
    }
    this->_pre->next = this->_head;
    
    for (int i = 0; i < start - 1; i++) {
        this->next();
    }
}

size_t CircleList::size() {
    return this->_size;
}

size_t CircleList::next() {
    this->_pre = this->_pre->next;
    this->_current = this->_current->next;
    return this->_pre->index + 1;
}

size_t CircleList::deleteCurrent() {
    this->_pre->next = this->_current->next;
    size_t result = this->_current->index;
    if (this->_current == this->_head) {
        this->_head = this->_pre->next;
    }
    delete this->_current;
    this->_current = this->_pre->next;
    
    this->_size--;
    return result + 1;
}

void CircleList::print() {
    Node *n = this->_head;
    do {
        std::cout << n->index + 1 << " -> ";
        n = n->next;
    } while (n != this->_head);
    std::cout << std::endl;
}
