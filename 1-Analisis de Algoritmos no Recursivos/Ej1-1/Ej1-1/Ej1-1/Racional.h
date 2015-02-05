//Clase Racional mediante denominador y numerador
class Racional{
private:
	int numerador; 
	int denominador; //Distinto de 0

public:
	//Constructor por defecto,
	//No realiza ninguna accion.
	Racional();

	//Constructor mediante el numerador y denominador
	/* Parametros
		Numerador de la fraccion, INT
		Denominador de la fraccion, INT !=0 */
	Racional(int num, int denom);

	/*Devuelve el numerador del obj actual */
	int getNumerador();

	/* Devuelve el denominador del obj actual */
	int getDenominador();

	/* Suma el parametro y el objeto en uso
	Parametro: clase racional a sumar.
	Retorno: Racional, resultado */
	Racional sumar(Racional operador);

	/* Multiplica operador por el objeto actual
	Retorno: Racional, resultado */
	Racional multiplicar(Racional operador);

	/* Imprime el Racional*/
	void escribir();

};