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
			Celda aux = Celda(i, j, -1);
			this->area[i][j] = aux;
		}
	}
}