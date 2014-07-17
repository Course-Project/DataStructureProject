//
//  Sort.cpp
//  DataStructure
//
//  Created by Tom Hu on 7/14/14.
//  Copyright (c) 2014 Tom Hu. All rights reserved.
//

#include "Sort.h"
#include <cstddef>
#include <cstdlib>

#define BASE 10

#pragma mark Utils
inline void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void quick_sort(std::vector<int> &t, size_t l, size_t r, size_t &op) {
    size_t m = (l + r) / 2;
    int key = t[m];
    size_t i = l, j = r;
    while (i < j) {
        while (i < m && t[i] <= key)
            i++;
        if (i < m) {
            op++;
            t[m] = t[i];
            m = i;
        }
        while (j > m && t[j] >= key)
            j--;
        if (j > m) {
            op++;
            t[m] = t[j];
            m = j;
        }
    }
    t[m] = key;
    if (m - l > 1)
        quick_sort(t, l, m - 1,op);
    if (r - m > 1)
        quick_sort(t, m + 1, r,op);
}

void adjustMaxHeap(std::vector<int> &t, int p, size_t size, size_t &op) {
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
        op++;
        swap(t[maxPosition], t[p]);
        adjustMaxHeap(t, maxPosition, size, op);
    }
}

void buildMaxHeap(std::vector<int> &t, size_t &op) {
    for (int i = (t.size() - 2) / 2.0f; i >= 0; i--) {
        adjustMaxHeap(t, i, t.size(), op);
    }
}

void merge(std::vector<int> &t, size_t first, size_t mid, size_t last, size_t &op) {
    int *p = (int *)malloc(sizeof(int) * (last - first + 1));
    size_t i = first, j = mid + 1, k = 0;
    while ((i <= mid) && (j <= last)) {
        op++;
        if (t[i] < t[j]) {
            p[k++] = t[i++];
        } else {
            p[k++] = t[j++];
        }
    }
    while (i <= mid) {
        p[k++] = t[i++];
    }
    while (j <= last) {
        p[k++] = t[j++];
    }
    for (i = first, k = 0; i <= last; i++) {
        t[i] = p[k++];
    }
    
}

void merge_sort(std::vector<int> &t, size_t first, size_t last, size_t &op) {
    if (first < last) {
        size_t mid = (first + last) / 2;
        if (mid - first >= 1) {
            merge_sort(t, first, mid, op);
        }
        if (last - mid > 1) {
            merge_sort(t, mid + 1, last, op);
        }
        merge(t, first, mid, last, op);
    }
}

#pragma mark -
#pragma mark Sort
void bubbleSort(std::vector<int> &t, size_t &op) {
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t.size() - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                op++;
                swap(t[j], t[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int> &t, size_t &op) {
    for (int i = 0; i < t.size(); i++) {
        int min = 0x0fffffff;
        int po = 0;
        for (int j = i; j < t.size(); j++) {
            if (t[j] < min) {
                op++;
                min = t[j];
                po = j;
            }
        }
        swap(t[i], t[po]);
    }
}

void insertionSort(std::vector<int> &t, size_t &op) {
    int temp;
    for (int i = 1; i < t.size(); i++) {
        temp = t[i];
        int j = i - 1;
        while (j >= 0 && t[j] > temp) {
            op++;
            t[j + 1] = t[j];
            j--;
        }
        t[j + 1] = temp;
    }
}

void shellSort(std::vector<int> &t, size_t &op) {
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
                op++;
                t[j + gap] = t[j];
                j -= gap;
            }
            t[j + gap] = temp;
        }
        gap = (gap - 1) / 3;
    }
}

void quickSort(std::vector<int> &t, size_t &op) {
    quick_sort(t, 0, t.size() - 1, op);
}

void heapSort(std::vector<int> &t, size_t &op) {
    buildMaxHeap(t, op);
    for (int i = 1; i <= t.size(); i++) {
        op++;
        swap(t[0], t[t.size() - i]);
        adjustMaxHeap(t, 0, t.size() - i, op);
    }
    
}

void mergeSort(std::vector<int> &t, size_t &op) {
    merge_sort(t, 0, t.size() - 1, op);
}

void radixSort(std::vector<int> &t, size_t &op) {
    int *temp = (int *)malloc(sizeof(int) * t.size());
    
    int max = t[0], i;
    for (i = 1; i < t.size(); i++) {
        max = max < t[i] ? t[i] : max;
    }
    
    int exp = 1;
    
    while (max / exp > 0) {
        int bucket[BASE] = {0};
        
        for (i = 0; i < t.size(); i++) {
            bucket[(t[i] / exp) % BASE]++;
        }
        
        for (i = 1; i < BASE; i++) {
            bucket[i] += bucket[i - 1];
        }
        
        size_t size = t.size() - 1;
        for (i = 0; i <= size; i++) {
            temp[--bucket[(t[size - i] / exp) % BASE]] = t[size - i];
        }
        
        for (i = 0; i < t.size(); i++) {
            t[i] = temp[i];
        }
        
        exp *= BASE;
    }
}
