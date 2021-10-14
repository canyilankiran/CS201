#include <iostream>
#include <string>
#include <fstream>
#include "TestBed.h"

using namespace std;
int main(int argc, char* argv[]) {
	
	string testfile;
	if (argc < 2) {
		cout << "Enter a test file name:" << endl;
		cin >> testfile;
	}
	else {
		testfile = argv[1];
	}

	// int i = 0;	
	ifstream file(testfile.c_str());
	if (file.is_open()) {
		cin.rdbuf(file.rdbuf());
		/*for (int i = 0; i < 3; i++) {
			
			getline(file, numbers);
			if (i == 0) {
				algorithmType = atoi(numbers.c_str());
			}
			if (i == 1) {
				k= atoi(numbers.c_str()); 
			}
			if (i == 2) {
				N= atoi(numbers.c_str()); 
			}
		}
		int* ArrNums = new int[N];
		while (getline(file, numbers)){
			ArrNums[i] = atoi(numbers.c_str());
			
			//cout << ArrNums[i] << endl;
			i++;

		}*/
	}
	else {
		cout << "Error: cannot read the test file!" << endl;
		return -1;
	}
	int algorithmType = 0;
	cin >> algorithmType;

	int k = 0;
	cin >> k;
	// Numbers are obtained from the file line by line with cin
    // The set of N input numbers must be read
	TestBed *tst1 = new TestBed();
	tst1->setAlgorithm(algorithmType, k);
	tst1->execute();

	delete tst1;

	return 0;
}