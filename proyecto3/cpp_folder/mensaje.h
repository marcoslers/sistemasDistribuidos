#define TAM_MAX_DATA 8

#define dibujar 1
#define borrar 0


struct mensaje{
	int messageType;
	unsigned int requestId;
	int operationId;
	char arguments[TAM_MAX_DATA];
};