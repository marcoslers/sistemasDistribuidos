#include"PaqueteDatagrama.h"
#include<stdio.h>
#include<string.h>
PaqueteDatagrama::PaqueteDatagrama(char * cad,unsigned int tam,char * dir,int port){
	datos = new char[tam];
	longitud=tam;
	memcpy(datos,cad,tam);
	memcpy(ip,dir,16);
	puerto=port;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam){
	datos = new char[tam];
	longitud=tam;
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete []datos;
}

char* PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

char* PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p){
	puerto=p;
}

void PaqueteDatagrama::inicializaIp(char *dir){
	memcpy(ip,dir,16);
}

void PaqueteDatagrama::inicializaDatos(char*cad){
	memcpy(datos,cad,longitud);
}