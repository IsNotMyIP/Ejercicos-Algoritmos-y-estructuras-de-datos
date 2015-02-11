class VectorInt{
private:
	int *inicio;
	int size;

public:
	VectorInt();
	VectorInt(int size);
	VectorInt(const VectorInt &a);


	void VectorInt::ordenadoChungo();


	int VectorInt::getSize();
	int* VectorInt::getInicio();
	int findMinimum(int start, int finish);
	~VectorInt();


};