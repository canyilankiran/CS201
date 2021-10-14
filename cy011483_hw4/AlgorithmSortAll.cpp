#include "AlgorithmSortAll.h"

using namespace std;

AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k){

}
int AlgorithmSortAll::select() {
	int N = 0;
	cin >> N;
	int* ArrNums = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> ArrNums[i];

	}
	int x, goal, y;
	for (x = 1; x < N; x++) {
		goal = ArrNums[x];
		y = x - 1;
		while (y >= 0 && ArrNums[y] < goal) {
			ArrNums[y + 1] = ArrNums[y];
			y = y - 1;
		}
		ArrNums[y + 1] = goal;
	}
	int result = ArrNums[k - 1];
	delete[] ArrNums;
	return result;
	
	}


