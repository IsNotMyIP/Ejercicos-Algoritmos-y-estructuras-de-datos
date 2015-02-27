#include "celda.h"
#include <cstdlib>
class AreaEmbaldosada{
private:
	int size;
	Celda** area;
	Celda busy;
public:
	AreaEmbaldosada(int size, Celda busy);
	Celda*& operator[](int x);


};