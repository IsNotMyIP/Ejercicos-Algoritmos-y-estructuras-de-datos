#pragma once
#include "iostream"
#include "ListaEnlazada.h"

using namespace std;

// Sobrecarga del operador << para imprimir un elemento por pantalla
// En el caso que nos ocupa, imprime simplemente el float
// Parámetros:
// - salida: flujo sobre el que queremos imprimir (típicamente cout)
// - elemento: lo que queremos imprimir en el flujo
// Retorno: flujo después de haber escrito en él
// Complejidad temporal y espacial: O(1)
ostream& operator << (ostream& salida, const Elemento &elemento);

// Sobrecarga del operador << para imprimir una lista por pantalla
// Parámetros:
// - salida: flujo sobre el que queremos imprimir (típicamente cout)
// - elemento: lo que queremos imprimir en el flujo
// Retorno: flujo después de haber escrito en él
// Complejidad temporal: O(n)
// Complejidad espacial: O(1)
ostream& operator << (ostream& salida, ListaEnlazada &lista);

