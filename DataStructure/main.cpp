//
//  main.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Cli.h"
#include "Sort.h"

using namespace std;

vector<int> generateRandomNumber(int con) {
    vector<int> result;
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < con; i++) {
        int temp = rand() % con;
        result.push_back(temp);
    }
    return result;
}

void print(const vector<int> &t) {
    vector<int>::const_iterator itr = t.begin();
    for (; itr != t.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    clock_t begin, end;
    int con = 0;
    
    cout << "> 输入需要排序的个数：";
    cin >> con;
    
    vector<int> t = generateRandomNumber(con);
    
    print(t);
    
    begin = clock();
    heapSort(t);
    end = clock();
    
    print(t);
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}