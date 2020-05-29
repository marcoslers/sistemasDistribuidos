//PoligonoIrreg.h
#include"Coordenada.h"
#include<vector>

class PoligonoIrreg{
	private:
		vector<Coordenada>coors;
		int velocidad;
	public:
		PoligonoIrreg(int n);
		int nVertices();
		vector<Coordenada> obtenerVertices();
		int getVelocidad();
};