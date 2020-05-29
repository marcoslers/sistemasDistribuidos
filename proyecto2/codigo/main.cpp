//main.cpp
#include"PoligonoIrreg.h"
#include"gfx.h"
#include<unistd.h>
#include<iostream>
#include<vector>

int main(){
    srand (time(NULL));

    vector<PoligonoIrreg>asteroides;

    int n;
    char c;
    cout<<"Ingresa numero de asteroides ";
    cin>>n;

    for(int i=0;i<n;i++){
    	int r = rand() % 13 + 4;
    	if((r%2)!=0)r+1;
        PoligonoIrreg p(r);
        asteroides.push_back(p);
    }

    gfx_open(800, 600, "GUIAsteroides");
    gfx_color(0,200,100);

    int i=0;    
                
    for(int i=0;i<1000;i++){
        
        gfx_clear();
        
        for(int k=0;k<asteroides.size();k++){
            
            vector<Coordenada> v;
            v=asteroides[k].obtenerVertices();
            int vel = i*asteroides[k].getVelocidad();
            for(int j=0;j<v.size();j++){
                int c1=j,c2=j+1;
                if(c2==v.size())c2=0;
                gfx_line(v[c1].obtenerX()+vel,v[c1].obtenerY()+vel,v[c2].obtenerX()+vel,v[c2].obtenerY()+vel);
                gfx_flush();    
            }

        }

        usleep(41666); 
    }
}