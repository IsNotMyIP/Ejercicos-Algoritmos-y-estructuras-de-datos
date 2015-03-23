#include "Elemento.h"

Elemento::Elemento() {
	// No hace nada especial
	// Dejamos el valor con basura
}

Elemento::Elemento(string valor) {
	set(valor);
	// cout << "Constructor!\n";
}

Elemento::Elemento (Elemento &loAsignado) {
	*this = loAsignado; // Se llama al operador sobrecargado =
	// cout << "Constructor de copia!\n";
}

string Elemento::get() const {
	return (valor);
}

void Elemento::set (string nuevoValor) {
	valor = nuevoValor;
}

bool Elemento::operator == (const Elemento &operando2) {
	return (valor == operando2.valor);
}

bool Elemento::operator < (const Elemento &operando2) {
	return (valor < operando2.valor);
}

bool Elemento::operator > (const Elemento &operando2) {
	return (valor > operando2.valor);
}

bool Elemento::operator <= (const Elemento &operando2) {
	return (valor <= operando2.valor);
}

bool Elemento::operator >= (const Elemento &operando2) {
	return (valor >= operando2.valor);
}

Elemento& Elemento::operator= (const Elemento &loAsignado) {
	valor = loAsignado.valor;
	// cout << "Asignación!\n";
	return (*this);
}



