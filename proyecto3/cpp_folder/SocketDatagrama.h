#include"PaqueteDatagrama.h"
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <sys/time.h>

class SocketDatagrama{
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s;
	public:
		SocketDatagrama(int);
		~SocketDatagrama();
		int envia(PaqueteDatagrama & p);
};