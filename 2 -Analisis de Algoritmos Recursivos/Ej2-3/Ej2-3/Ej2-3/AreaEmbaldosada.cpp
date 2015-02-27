#include "AreaEmbaldosada.h"


AreaEmbaldosada::AreaEmbaldosada(int size, Celda busy){
	this->size = size;
	this->area = (Celda**) malloc(size * sizeof(Celda*));

	for (int i = 0; i < size; i++){
		this->area[i] = (Celda*)malloc(size * sizeof(Celda));
	}
	
	// Rellenamos las celdas con la clase CELDA.
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			Celda aux;
			if (i == busy.getX() && j == busy.getY()){
				aux = Celda(i, j, 0);
			}
			else{
				aux = Celda(i, j);
			}
			this->area[i][j] = aux;
		}
	}
}

int AreaEmbaldosada::getSize(){
	return this->size;
}
 Celda*& AreaEmbaldosada::operator[](int x){
	return area[x];
}
 

ostream& operator<< (ostream& o, AreaEmbaldosada a){
	for (int i = 0; i < a.getSize(); i++){
		for (int j = 0; j < a.getSize(); j++){
			cout << setw(4) << a[j][i].getContenido();
		}
		cout << endl;
	}
	 return o;
 }
