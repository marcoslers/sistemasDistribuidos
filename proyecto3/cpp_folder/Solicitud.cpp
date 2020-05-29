#include"Solicitud.h"
#include<stdio.h>
#include<string.h>

Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(0);
	reqstId=0;
}

char* Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){

	mensaje msg, *ptr1,*ptr2;
	msg.messageType = 0;
	msg.requestId=reqstId;
	msg.operationId=operationId;
	memcpy(msg.arguments,arguments,TAM_MAX_DATA);
	
	ptr1=&msg;

	PaqueteDatagrama pdreqs((char*)ptr1,sizeof(msg),IP,puerto),pdresp(sizeof(msg));
	
	int sal = 0, cont =0;

	if((socketlocal->envia(pdreqs))>=0)
		reqstId++;

	return 0;
}