//Coordenada.cpp
#include "Coordenada.h"
#include <iostream>

using namespace std;

Coordenada::Coordenada(int xx, int yy) : x(xx), y(yy)
{}

int Coordenada::obtenerX(){
	return x;
}

int Coordenada::obtenerY(){
	return y;
}