//
// Created by can yılankıran on 27.11.2019.
//
#ifndef _ALGORITHMSORTQUICK_H
#define _ALGORITHMSORTQUICK_H

#include "SelectionAlgorithm.h"
class AlgorithmSortQuick : public SelectionAlgorithm {
public:
    int select();
    int quickselect(int*,int,int,int);
    AlgorithmSortQuick(int);
    int median(int*, int , int );
    int insertionSort(int*,int,int);
};
#endif