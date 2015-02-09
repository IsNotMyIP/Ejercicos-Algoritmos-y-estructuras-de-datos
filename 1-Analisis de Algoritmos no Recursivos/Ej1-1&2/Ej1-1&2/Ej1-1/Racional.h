//Clase Racional mediante denominador y numerador
class Racional{
private:
	int numerador; 
	int denominador; //Distinto de 0

	//Calcula MCD de 2 numeros enteros.
	/* Parametros:
		- p1, primer numero para calcular MCD
		- p2, segundo numero para calcular MCD
	Retorna:
		- Numero resultado del MCD p1 y p2
	Restricciones:
		- p1 > 0 & p2 > 0 */
	int calcularMCD(int p1, int p2);

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
	
	/* Simplifica el Racional desde el que es llamado.*/
	void simplificar();

};