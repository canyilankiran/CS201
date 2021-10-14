//
// Created by can yılankıran on 27.11.2019.
//
#include "AlgorithmSortQuick.h"

using namespace std;

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k) {

}

int AlgorithmSortQuick::select() {
    int N = 0;
    cin >> N;
    int *ArrNums = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> ArrNums[i];
    }
    return quickselect(ArrNums, 0, N, k);
}

int AlgorithmSortQuick::quickselect(int *ArrNums, int left, int right, int k) {

    if (right-left<=10) {
        return insertionSort(ArrNums, left, right);
    }else{
        int pivot = median(ArrNums, left, right);
        int i = left;
        int j = right - 1;
        for (;;) {
            while (ArrNums[++i] > pivot) {}
            while (pivot > ArrNums[--j]) {}
            if (i < j)
                swap(ArrNums[i], ArrNums[j]);
            else
                break;
        }
        swap(ArrNums[i], ArrNums[right - 1]);
        if (k <= i - 1) {
            return quickselect(ArrNums, left, i - 1, k);
        } else if(k == i) {
            return pivot;
        } else {
            return quickselect(ArrNums, i + 1, right, k);
        }
    }
}


int AlgorithmSortQuick::median(int *ArrNums, int left, int right) {
    int center = (left + right) / 2;
    if (ArrNums[center] > ArrNums[left])
        swap(ArrNums[left], ArrNums[center]);

    if (ArrNums[right] > ArrNums[left])
        swap(ArrNums[right], ArrNums[left]);

    if (ArrNums[right] > ArrNums[center])
        swap(ArrNums[center], ArrNums[right]);

    swap(ArrNums[center], ArrNums[right - 1]);
    return ArrNums[right - 1];
}

int AlgorithmSortQuick::insertionSort(int *ArrNums, int left, int right) {
    int x, element, y;
    for (x = left; x < right; x++) {
        //cout<<ArrNums[x]<<" ";
        element = ArrNums[x];
        y = x - 1;
        while (y >= 0 && ArrNums[y] < element) {
            ArrNums[y + 1] = ArrNums[y];
            y = y - 1;
        }
        ArrNums[y + 1] = element;
    }

    return ArrNums[k-1];

}


