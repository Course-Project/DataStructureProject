//
//  main.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include <iostream>
#include <vector>
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
    
    /**
     *  Bubble Sort
     */
    cout << "Bubble Sort" << endl;
    
    vector<int> *px = new vector<int>(t);
    
    begin = clock();
    bubbleSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    /**
     *  Selection Sort
     */
    cout << "Selection Sort" << endl;
    
    px = new vector<int>(t);
    
    begin = clock();
    selectionSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    /**
     *  Insertion Sort
     */
    cout << "Insertion Sort" << endl;
    
    px = new vector<int>(t);
    
    begin = clock();
    insertionSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    /**
     *  Shell Sort
     */
    cout << "Shell Sort" << endl;
    
    px = new vector<int>(t);
    
    begin = clock();
    shellSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    /**
     *  Quick Sort
     */
    cout << "Quick Sort" << endl;
    
    px = new vector<int>(t);
    
    begin = clock();
    quickSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    /**
     *  Heap Sort
     */
    cout << "Heap Sort" << endl;
    
    px = new vector<int>(t);
    
    begin = clock();
    heapSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    /**
     *  Merge Sort
     */
    cout << "Merge Sort" << endl;
    
    px = new vector<int>(t);
    
    begin = clock();
    mergeSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    /**
     *  Radix Sort
     */
    cout << "Radix Sort" << endl;
    
    px = new vector<int>(t);
    
    begin = clock();
    radixSort(*px);
    end = clock();
    
    delete px;
    
    cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}
