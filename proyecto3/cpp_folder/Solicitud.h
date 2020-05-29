#include"mensaje.h"
#include"SocketDatagrama.h"
class Solicitud{
	private:
		SocketDatagrama *socketlocal;
		int reqstId;
	public:
		Solicitud();
		char* doOperation(char *IP, int puerto, int operationId, char *arguments);
};