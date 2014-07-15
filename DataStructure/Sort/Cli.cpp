//
//  Cli.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Cli.h"
#include "Sort.h"
#include <vector>

using namespace NO_10;

#pragma mark Util

void printWelcomeInfo() {
    std::cout << "Welcome Info" << std::endl;
}

void printHelpInfo() {
    std::cout << "Help Info" << std::endl;
}

std::vector<int> generateRandomNumber(int con) {
    std::vector<int> result;
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < con; i++) {
        int temp = rand() % con;
        result.push_back(temp);
    }
    return result;
}

void print(const std::vector<int> &t) {
    std::vector<int>::const_iterator itr = t.begin();
    for (; itr != t.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

#pragma mark -
#pragma mark Cli

/**
 * Process the command line input
 */
void Cli::process(std::string command) {
    
}

/**
 *  Command line interface
 */
void Cli::start() {
//    // Print welcome information
//    printWelcomeInfo();
//    
//    // Print help information
//    printHelpInfo();
//    
//    // Infinite loop
//    while (true) {
//        std::string command;
//        std::cout << "> ";
//        std::cin >> command;
//        
//        this->process(command);
//    }
    clock_t begin, end;
    int con = 0;
    
    std::cout << "> 输入需要排序的个数：";
    std::cin >> con;
    
    std::vector<int> t = generateRandomNumber(con);
    
    /**
     *  Bubble Sort
     */
    std::cout << "Bubble Sort" << std::endl;
    
    std::vector<int> *px = new std::vector<int>(t);
    
    begin = clock();
    bubbleSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
    
    /**
     *  Selection Sort
     */
    std::cout << "Selection Sort" << std::endl;
    
    px = new std::vector<int>(t);
    
    begin = clock();
    selectionSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
    
    /**
     *  Insertion Sort
     */
    std::cout << "Insertion Sort" << std::endl;
    
    px = new std::vector<int>(t);
    
    begin = clock();
    insertionSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
    
    /**
     *  Shell Sort
     */
    std::cout << "Shell Sort" << std::endl;
    
    px = new std::vector<int>(t);
    
    begin = clock();
    shellSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
    
    /**
     *  Quick Sort
     */
    std::cout << "Quick Sort" << std::endl;
    
    px = new std::vector<int>(t);
    
    begin = clock();
    quickSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
    
    /**
     *  Heap Sort
     */
    std::cout << "Heap Sort" << std::endl;
    
    px = new std::vector<int>(t);
    
    begin = clock();
    heapSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
    
    /**
     *  Merge Sort
     */
    std::cout << "Merge Sort" << std::endl;
    
    px = new std::vector<int>(t);
    
    begin = clock();
    mergeSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
    
    /**
     *  Radix Sort
     */
    std::cout << "Radix Sort" << std::endl;
    
    px = new std::vector<int>(t);
    
    begin = clock();
    radixSort(*px);
    end = clock();
    
    delete px;
    
    std::cout << "Time: " << std::fixed << (double)(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
}