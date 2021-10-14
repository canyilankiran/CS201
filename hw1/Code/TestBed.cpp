#include "TestBed.h"
#include <ctime>

TestBed::TestBed() {
	algorithm = 0;
}


void TestBed::execute() {
	clock_t start = clock();
	int output = 0;
	output =algorithm->select();
	clock_t end = clock();
	double cpu_time = static_cast<double>(end - start) /CLOCKS_PER_SEC;
	
	cout <<"Result: "<< output << endl;
	cout <<"Duration (sec) : "<< cpu_time;
}

void TestBed::setAlgorithm(int algorithmType, int k) {

	if (algorithmType == 1) {
		algorithm = new AlgorithmSortAll(k);
	}
	if (algorithmType == 2) {
		algorithm = new AlgorithmSortK(k);
	}

}

TestBed::~TestBed() {
	delete algorithm;

}

