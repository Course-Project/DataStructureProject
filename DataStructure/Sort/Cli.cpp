//
//  Cli.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Cli.h"
#include "Sort.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace NO_10;
using namespace std;

#pragma mark Util

void printWelcomeInfo() {
    cout << "=============================================" << endl;
    cout << "                 排序算法比较" << endl;
    cout << "=============================================" << endl;
    cout << "                1 --- 冒泡排序" << endl;
    cout << "                2 --- 选择排序" << endl;
    cout << "                3 --- 插入排序" << endl;
    cout << "                4 --- 希尔排序" << endl;
    cout << "                5 --- 快速排序" << endl;
    cout << "                6 --- 堆排序" << endl;
    cout << "                7 --- 归并排序" << endl;
    cout << "                8 --- 基数排序" << endl;
    cout << "                0 --- 退出" << endl;
    cout << "=============================================" << endl;
    cout << endl;
}

vector<int> generateRandomNumber(size_t con) {
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

#pragma mark -
#pragma mark Cli

/**
 *  Command line interface
 */
void Cli::start(const vector<int> &t) {
    clock_t begin, end;
    vector<int> *px;
    size_t op = 0;
    
    size_t in;
    cout << "请选择排序算法：";
    cin >> in;
    
    switch (in) {
        case 0: {
            this->isRunning = false;
            
            break;
        }
            
        case 1: {
            /**
             *  Bubble Sort
             */
            cout << "Bubble Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            bubbleSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
            
        case 2: {
            /**
             *  Selection Sort
             */
            cout << "Selection Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            selectionSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
        
        case 3: {
            /**
             *  Insertion Sort
             */
            cout << "Insertion Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            insertionSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
        
        case 4: {
            /**
             *  Shell Sort
             */
            cout << "Shell Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            shellSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
        
        case 5: {
            /**
             *  Quick Sort
             */
            cout << "Quick Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            quickSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
        
        case 6: {
            /**
             *  Heap Sort
             */
            cout << "Heap Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            heapSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
            
        case 7: {
            /**
             *  Merge Sort
             */
            cout << "Merge Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            mergeSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
            
        case 8: {
            /**
             *  Radix Sort
             */
            cout << "Radix Sort" << endl;
            
            px = new vector<int>(t);
            op = 0;
            
            begin = clock();
            radixSort(*px, op);
            end = clock();
            
            delete px;
            
            cout << "Time: " << fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
            cout << "Operations: " << op << endl << endl;
            
            break;
        }
            
        default: {
            cout << "所选算法不存在" << endl;
            
            break;
        }
    }

}

Cli::Cli() {
    this->isRunning = true;
    
    // 输出欢迎信息
    printWelcomeInfo();
    
    size_t con = 0;
    
    cout << "输入需要排序的个数：";
    cin >> con;
    
    vector<int> t = generateRandomNumber(con);
    
    while (this->isRunning) {
        this->start(t);
    }
}
