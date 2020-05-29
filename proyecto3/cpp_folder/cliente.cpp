#include"Solicitud.h"

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<thread>
#include<chrono>
#include<string.h>

#define PI 3.14159265

using namespace std;

int nterminos;
int flag=0;

char ip[16];
int puerto=7200;

void draw(){

	Solicitud sock1;

	int coordenada[2];
	float terminos[800]={};
	for(int n=1;n<nterminos;n++){
      	int t=0;
      	float p = 1.0/200.0;
      	//gfx_clear();
      	for(int i=50;i<850;i++){

      		float num=pow((-1),n+1);
      		float den=n*PI;
      		float fac = 2.0*(num/den);
      		float seno=float(sin(PI*p*n*t));
      			
         	terminos[t]=terminos[t]+(fac*seno); 

         	int y=(int)(terminos[t]*100.0);
         	
         	coordenada[0]=i;
         	coordenada[1]=350-y;
         	t++;
         	sock1.doOperation(ip,puerto,dibujar,(char*)coordenada);
         	usleep(1000); 
      	}
      	flag=1;
   	}
}
void erase(){
	Solicitud sock2;

	int coordenada[2];
	float terminos[800]={};
	while(flag!=1);
	for(int n=1;n<nterminos;n++){
      	int t=0;
      	float p = 1.0/200.0;
      	for(int i=50;i<850;i++){

      		float num=pow((-1),n+1);
      		float den=n*PI;
      		float fac = 2.0*(num/den);
      		float seno=float(sin(PI*p*n*t));
      			
         	terminos[t]=terminos[t]+(fac*seno); 

         	int y=(int)(terminos[t]*100.0);
         	
         	coordenada[0]=i;
         	coordenada[1]=350-y;
         	t++;
         	sock2.doOperation(ip,puerto,borrar,(char*)coordenada);
         	usleep(1000); 
      	}
   	}
}

int main(int argc, char *argv[]){	
	 
   memcpy(ip,argv[1],16);
	nterminos=atoi(argv[2]);
   
   thread tdraw(draw),terase(erase);
	tdraw.join();
	terase.join();	
	return 0;
}