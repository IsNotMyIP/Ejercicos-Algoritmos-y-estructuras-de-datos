class Celda{
private:
	int x;				//coordenada X
	int y;				//coordenada Y
	int contenido;		//contenido de la celda.
public:

	//Constructor por defecto, vacio.
	Celda();
	//Constructor, al no incluir contenido, se fijará -1 como default.
	//Parametros:
	// - posX, int coordenada X.
	// - posY, int coordenada Y.
	//Asserts: posX => 0 && posY => 0
	Celda(int posX, int posY);

	//Constructor, al no incluir contenido, se fijará -1 como default.
	//Parametros:
	// - posX, int coordenada X.
	// - posY, int coordenada Y.
	// - contenido, int, contenido de la celda.
	//Asserts: posX => 0 && posY => 0
	Celda(int posX, int posY, int contenido);

	int getX();
	int getY();
	int getContenido();
};