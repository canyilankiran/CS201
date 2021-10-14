#ifndef _selecalg_
#define _selecalg_

#include <iostream>

using namespace std;
class SelectionAlgorithm{
public:
	SelectionAlgorithm(int);
	virtual int select();
	
protected:
	int k;

};
#endif 

