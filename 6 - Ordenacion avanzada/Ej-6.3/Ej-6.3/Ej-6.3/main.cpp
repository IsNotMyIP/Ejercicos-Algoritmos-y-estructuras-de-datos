#include "iostream"
#include "ListaContigua.h"
#include "BibliotecaImpresionListasContiguas.h"

using namespace std;


void main () {

	// Creamos una ListaContigua que nos servirá para las pruebas
	ListaContigua ListaContigua1;
	
	cout << "Nueva ListaContigua creada:\n" << ListaContigua1;

	cout << "Rellenando ListaContigua:\n";
	for (int i=0; i<=11; i++) {
		ListaContigua1.insertar(i, Elemento((float)i)); // Creamos el elemento y a la vez lo copiamos en la ListaContigua
		cout << ListaContigua1 << endl;
	}
	cout << "Elemento0=" << ListaContigua1.getValor(0) << "|Elemento11=" << ListaContigua1.getValor(11) << endl;
	
	cout << "Cambio elemento 4 por 50. Nueva ListaContigua:\n";
	ListaContigua1.setValor(4,50);
	cout << ListaContigua1 << endl;

	cout << "Inserto 100 en la posicion 0. Nueva ListaContigua:\n";
	ListaContigua1.insertar(0, 100);
	cout << ListaContigua1 << endl;

	cout << "Insertamos 200 en la ultima posicion. Nueva ListaContigua:\n";
	ListaContigua1.insertar(ListaContigua1.getN(), 200);
	cout << ListaContigua1 << endl;

	cout << "Insertamos 300 en la posicion 4. Nueva ListaContigua:\n";
	ListaContigua1.insertar(4,300);
	cout << ListaContigua1 << endl;

	cout << "Borramos elemento 4. Nueva ListaContigua:\n";
	ListaContigua1.eliminar(4);
	cout << ListaContigua1 << endl;

	cout << "Borramos elemento 4. Nueva ListaContigua:\n";
	ListaContigua1.eliminar(4);
	cout << ListaContigua1 << endl;

	cout << "Borramos el ultimo elemento. Nueva ListaContigua:\n";
	ListaContigua1.eliminar(ListaContigua1.getN()-1);
	cout << ListaContigua1 << endl;

	cout << "Borramos elemento 4. Nueva ListaContigua:\n";
	ListaContigua1.eliminar(4);
	cout << ListaContigua1 << endl;

	cout << "Borramos elemento 0. Nueva ListaContigua:\n";
	ListaContigua1.eliminar(0);
	cout << ListaContigua1 << endl;

	// Creamos las ListaContiguas que nos servirán para las pruebas
	ListaContigua ListaContigua2, ListaContigua3;

	// Creamos un elemento que nos servirá para ir metiéndolo en las ListaContiguas
	Elemento e(0);

	// Rellenamos la ListaContigua ListaContigua2
	for (int i=0; i<=5; i++) {
		e.set((float)i);
		ListaContigua2.insertar(i, e);		
	}
	cout << "ListaContigua2: " << ListaContigua2 << endl;		

	// Rellenamos la ListaContigua ListaContigua3
	for (int i=6; i<=10; i++) {
		e.set((float)i);
		ListaContigua3.insertar(i-6, e);		
	}
	cout << "ListaContigua3: " << ListaContigua3 << endl;		

	cout << "Imprimimos los elementos 0, 3 y 5 de la ListaContigua ListaContigua2:\n";
	cout << "Elemento0=" << ListaContigua2[0] << "|Elemento3=" << ListaContigua2[3] << "|Elemento5=" << ListaContigua2[5] << endl;

	cout << "Buscamos el 5 en ListaContigua2. Encontrado en la posicion: ";
	e.set(5);
	cout << ListaContigua2.buscar(e) << endl;

	cout << "Buscamos el 10 en ListaContigua2. Encontrado en la posicion: ";
	e.set(10);
	cout << ListaContigua2.buscar(e) << endl;

	cout << "Creamos ListaContigua4 y la inicializamos a ListaContigua3.\nListaContigua4 es: ";
	ListaContigua ListaContigua4 = ListaContigua3;
	cout << ListaContigua4 << endl;

	cout << "Creamos ListaContigua5 y a continuacion la asignamos ListaContigua2+ListaContigua3.\nListaContigua5 es: ";
	ListaContigua ListaContigua5;
	ListaContigua5 = ListaContigua2+ListaContigua3;
	cout << ListaContigua5 << endl;

	cout << "Ordenamos ListaContigua5 de mayor a menor.\nAhora ListaContigua5 es: ";
	ListaContigua5.ordenar();
	cout << ListaContigua5 << endl;
	
	
}


