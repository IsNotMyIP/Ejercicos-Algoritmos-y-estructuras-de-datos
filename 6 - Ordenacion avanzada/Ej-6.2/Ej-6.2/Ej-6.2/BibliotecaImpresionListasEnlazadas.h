#pragma once
#include "iostream"
#include "ListaEnlazada.h"

using namespace std;

// Sobrecarga del operador << para imprimir un elemento por pantalla
// En el caso que nos ocupa, imprime simplemente el float
// Par�metros:
// - salida: flujo sobre el que queremos imprimir (t�picamente cout)
// - elemento: lo que queremos imprimir en el flujo
// Retorno: flujo despu�s de haber escrito en �l
// Complejidad temporal y espacial: O(1)
ostream& operator << (ostream& salida, const Elemento &elemento);

// Sobrecarga del operador << para imprimir una lista por pantalla
// Par�metros:
// - salida: flujo sobre el que queremos imprimir (t�picamente cout)
// - elemento: lo que queremos imprimir en el flujo
// Retorno: flujo despu�s de haber escrito en �l
// Complejidad temporal: O(n)
// Complejidad espacial: O(1)
ostream& operator << (ostream& salida, ListaEnlazada &lista);

