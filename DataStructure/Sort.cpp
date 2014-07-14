//
//  Sort.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Sort.h"
#include <cstddef>

#pragma mark Utils
inline void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void quick_sort(std::vector<int> &t, size_t l, size_t r) {
    size_t m = (l + r) / 2;
    int key = t[m];
    size_t i = l, j = r;
    while (i < j) {
        while (i < m && t[i] <= key)
            i++;
        if (i < m) {
            t[m] = t[i];
            m = i;
        }
        while (j > m && t[j] >= key)
            j--;
        if (j > m) {
            t[m] = t[j];
            m = j;
        }
    }
    t[m] = key;
    if (m - l > 1)
        quick_sort(t, l, m - 1);
    if (r - m > 1)
        quick_sort(t, m + 1, r);
}

void adjustMaxHeap(std::vector<int> &t, int p, size_t size) {
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    int maxPosition;
    if (l < size && t[l] > t[p]) {
        maxPosition = l;
    } else {
        maxPosition = p;
    }
    if (r < size && t[r] > t[maxPosition]) {
        maxPosition = r;
    }
    if (maxPosition != p) {
        swap(t[maxPosition], t[p]);
        adjustMaxHeap(t, maxPosition, size);
    }
}

void buildMaxHeap(std::vector<int> &t) {
    for (int i = (t.size() - 2) / 2.0f; i >= 0; i--) {
        adjustMaxHeap(t, i, t.size());
    }
}

#pragma mark -
#pragma mark Sort
void bubbleSort(std::vector<int> &t) {
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t.size() - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                swap(t[j], t[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int> &t) {
    for (int i = 0; i < t.size(); i++) {
        int min = 0x0fffffff;
        int po = 0;
        for (int j = i; j < t.size(); j++) {
            if (t[j] < min) {
                min = t[j];
                po = j;
            }
        }
        swap(t[i], t[po]);
    }
}

void insertionSort(std::vector<int> &t) {
    int temp;
    for (int i = 1; i < t.size(); i++) {
        temp = t[i];
        int j = i - 1;
        while (j >= 0 && t[j] > temp) {
            t[j + 1] = t[j];
            j--;
        }
        t[j + 1] = temp;
    }
}

void shellSort(std::vector<int> &t) {
    int gap = 0;
    while (gap <= t.size()) {
        gap = 3 * gap + 1;
    }
    while (gap > 0) {
        int temp;
        for (int i = gap; i < t.size(); i++) {
            temp = t[i];
            int j = i - gap;
            while (j >= 0 && t[j] > temp) {
                t[j + gap] = t[j];
                j -= gap;
            }
            t[j + gap] = temp;
        }
        gap = (gap - 1) / 3;
    }
}

void quickSort(std::vector<int> &t) {
    quick_sort(t, 0, t.size() - 1);
}

void heapSort(std::vector<int> &t) {
    buildMaxHeap(t);
    for (int i = 1; i <= t.size(); i++) {
        swap(t[0], t[t.size() - i]);
        adjustMaxHeap(t, 0, t.size() - i);
    }
    
}

void mergeSort(std::vector<int> &t) {
    
}

void radixSort(std::vector<int> &t) {
    
}