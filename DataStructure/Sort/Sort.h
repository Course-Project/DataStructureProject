//
//  Sort.h
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#ifndef __DataStructure__Sort__
#define __DataStructure__Sort__

#include <iostream>
#include <vector>

/**
 *  All results are in ascending order
 */

void bubbleSort(std::vector<int> &t, size_t &op);
void selectionSort(std::vector<int> &t, size_t &op);
void insertionSort(std::vector<int> &t, size_t &op);
void shellSort(std::vector<int> &t, size_t &op);
void quickSort(std::vector<int> &t, size_t &op);
void heapSort(std::vector<int> &t, size_t &op);
void mergeSort(std::vector<int> &t, size_t &op);
void radixSort(std::vector<int> &t, size_t &op);

#endif /* defined(__DataStructure__Sort__) */
