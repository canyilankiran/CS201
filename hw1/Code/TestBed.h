#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"

using namespace std;

class TestBed {

public:
	
	TestBed();
	~TestBed();
	void execute();
	void setAlgorithm(int, int);
private:

	SelectionAlgorithm* algorithm;
};




















