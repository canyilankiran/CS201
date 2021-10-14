#include "AlgorithmSortK.h"

using namespace std;

AlgorithmSortK::AlgorithmSortK(int k) :SelectionAlgorithm(k) {

}
int AlgorithmSortK::select() {
	int N = 0;
	cin >> N;
	int* ArrNums = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> ArrNums[i];
	}

	int x, goal, y;
	for (x = 1; x < k; x++) {
		goal = ArrNums[x];
		y = x - 1;
		while (y >= 0 && ArrNums[y] < goal) {
			ArrNums[y + 1] = ArrNums[y];
			y = y - 1;
		}
		ArrNums[y + 1] = goal;
	}
	// sorted array
	//int count = 0;
	//for (int r = 0; r < k; r++) {
	//	cout << ArrNums[r] << " ";
	//	count++;

	//}
	//cout << count;
	
	int TempNum = 0;
	int t = 0;
	for (int b = k; b < N ; b++) {
		cin >> TempNum;
		t = k - 1;
		if (TempNum > ArrNums[k - 1]) {
			while (TempNum > ArrNums[t] && t >= 0) {
				if (t == k - 1) {
					ArrNums[t] = TempNum;
					t--;
				}
				else {
					int temp = ArrNums[t];
					ArrNums[t] = TempNum;
					ArrNums[t + 1] = temp;
					t--;
				}

			}

		}


	}
	int result = ArrNums[k - 1];
	delete[] ArrNums;
	return result;
}




