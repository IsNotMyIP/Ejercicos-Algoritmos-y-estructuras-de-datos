#pragma once
#include "iostream"
#include "ListaContigua.h"

using namespace std;

// Sobrecarga del operador << para imprimir un elemento por pantalla
// Parámetros:
// - salida: flujo sobre el que queremos imprimir (típicamente cout)
// - elemento: lo que queremos imprimir en el flujo
// Retorno: flujo después de haber escrito en él
// Complejidad temporal y espacial: O(1)
ostream& operator << (ostream& salida, const Elemento &elemento);

// Sobrecarga del operador << para imprimir una ListaContigua por pantalla
// Parámetros:
// - salida: flujo sobre el que queremos imprimir (típicamente cout)
// - elemento: lo que queremos imprimir en el flujo
// Retorno: flujo después de haber escrito en él
// Complejidad temporal: O(n)
// Complejidad espacial: O(1)
ostream& operator << (ostream& salida, ListaContigua &ListaContigua);

