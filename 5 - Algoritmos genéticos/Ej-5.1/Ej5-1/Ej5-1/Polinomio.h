

class Polinomio {
private:
	int grado;
	float* coeficientes;
public:
	//Constructor por defecto, sin implementar.
	Polinomio ();

	Polinomio(int grado, float* coeficiente);
	float evaluar(float x);
	float obtenerMaximo();
	~Polinomio ();

};