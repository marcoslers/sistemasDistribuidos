deploy:
	gcc gfx.c -c
	g++ Coordenada.cpp PoligonoIrreg.cpp main.cpp -c
	g++ gfx.o Coordenada.o PoligonoIrreg.o main.o -o main -lX11 -lpthread
	./main 50
