#include "celda.h"
#include <cstdlib>
using namespace std;
#include <iostream>
#include <iomanip>
class AreaEmbaldosada{
private:
	int size;
	Celda** area;
	Celda busy;
public:
	AreaEmbaldosada(int size, Celda busy);
	Celda*& operator[](int x);

	friend ostream& operator<< (ostream& o, AreaEmbaldosada a);

	int getSize();
};