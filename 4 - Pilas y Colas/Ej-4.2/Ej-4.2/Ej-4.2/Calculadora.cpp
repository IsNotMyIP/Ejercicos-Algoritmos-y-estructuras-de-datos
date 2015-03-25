#include "Calculadora.h"

void Calculadora::convertirTextoAListaInfija(string cadena){
	int i = cadena.size();
	int n = 0;
	string toList;
	while (cadena[n] != '\0'){
	
		if (cadena[n] == '+' || cadena[n] == 'x' || cadena[n] == ')' || cadena[n] == '(') {
			inFijo.insertar(inFijo.getN(), Elemento(toList));
			toList.clear();
			string operando(&cadena[n], 1);
			inFijo.insertar(inFijo.getN(), Elemento(operando));
		}
		else{
			toList.push_back(cadena[n]);
		}
		n++;
	}
	inFijo.insertar(inFijo.getN(), Elemento(toList));
}

void Calculadora::convertirInfijoAListaPostFija() {
	int sizeinFijo = this->inFijo.getN();
	for (int i = 0; i < sizeinFijo; i++){
		if (this->inFijo.getValor(i).get()[0] == '+' || this->inFijo.getValor(i).get()[0] == 'x' ||
			this->inFijo.getValor(i).get()[0] == '(' || this->inFijo.getValor(i).get()[0] == ')'){
			switch (this->inFijo.getValor(i).get()[0]){
			case '+':
				while (!this->auxOperandos.isVacia() ) {
					if (this->auxOperandos.verCima().get()[0] == '('){
						break;
					}
					this->postFijo.insertar(this->postFijo.getN(), Elemento(this->auxOperandos.pop()));
				}
				this->auxOperandos.push(Elemento("+"));
				break;
			case 'x':
				while (!this->auxOperandos.isVacia()){
					if (this->auxOperandos.verCima().get()[0] == '+' || this->auxOperandos.verCima().get()[0] == '('){
						break;
					}	
				}
				this->auxOperandos.push(Elemento("x"));
				break;
			case '(':
				this->auxOperandos.push(Elemento("("));
				break;
			case ')':
				while (!this->auxOperandos.isVacia() || this->auxOperandos.verCima().get() != "(" ){
					this->postFijo.insertar(this->postFijo.getN(), this->auxOperandos.pop());
				}
				this->auxOperandos.pop();
			default:
				break;
			}
		}
		else{
			this->postFijo.insertar(this->postFijo.getN(), Elemento(this->inFijo.getValor(i).get()));
		}
	}
	while (!this->auxOperandos.isVacia()){
		this->postFijo.insertar(this->postFijo.getN(), Elemento(this->auxOperandos.pop().get()));
	}
	/////////////////
	for (int i = 0; i < this->postFijo.getN(); i++){
		cout << this->postFijo.getValor(i).get();
	}
	cout << endl;
}

int Calculadora::evaluar(string aCalcular){
	this->convertirTextoAListaInfija(aCalcular);
	this->convertirInfijoAListaPostFija();
	return this->evaluarPostFijo();
}

int Calculadora::evaluarPostFijo(){
	int op1;
	int op2;
	int sizePostFijo = this->postFijo.getN();
		for (int i = 0; i < sizePostFijo; i++){
			if (this->postFijo.getValor(i).get() != "+" && this->postFijo.getValor(i).get() != "x"){
				this->auxOperandos.push(Elemento(this->postFijo.getValor(i).get()));
			}
			else{
				switch (this->postFijo.getValor(i).get()[0]){
				case '+':
					op1 = atoi(this->auxOperandos.pop().get().c_str());
					op2 = atoi(this->auxOperandos.pop().get().c_str());
					this->auxOperandos.push(Elemento(to_string(op1 + op2)));
					break;
				case 'x':
					op1 = atoi(this->auxOperandos.pop().get().c_str());
					op2 = atoi(this->auxOperandos.pop().get().c_str());
					this->auxOperandos.push(Elemento(to_string(op1 * op2)));
					break;
				default:
					break;
				}
			}
		}
	return atoi(this->auxOperandos.pop().get().c_str());
}