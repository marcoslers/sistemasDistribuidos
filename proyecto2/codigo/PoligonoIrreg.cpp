//PoligonoIrreg.cpp
#include"PoligonoIrreg.h"
#include<iostream>
#include<vector>

using namespace std;

PoligonoIrreg::PoligonoIrreg(int n){
	
	int si=rand() % 2 + 0;
	velocidad=(si>0)?(rand() % 7 + 1):((-1)*(rand() % 7 + 1));

	int r1=rand() % 1000 + 0, r2=rand() % 1000 + 0, f=rand() % 50 + 20;
	int l1=r1-f,l2=r1+f,s1=r2-f,s2=r2+f;
	int div=(f*2)/(n/2);
	
	for(int i=0;i<n;i++){
		int aux1=rand() % div + 0;
		int aux2=rand() % 40 + 0;
		if(i<(n/2)){
			coors.push_back(Coordenada(l1+aux1,s1+aux2));
			l1+=div;
		}else{
			coors.push_back(Coordenada(l2-aux1,s2-aux2));
			l2-=div;
		}
	}
}

int PoligonoIrreg::getVelocidad(){
	return velocidad;
}

int PoligonoIrreg::nVertices(){
	return coors.size();
}

vector<Coordenada> PoligonoIrreg::obtenerVertices(){
	return coors;
}