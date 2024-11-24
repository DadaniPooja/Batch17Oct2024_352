#include <stdio.h>
#include <string.h>

typedef struct puttyCofig
{
    int port;
	char host[100];
	char protocol[100];
	char username[50];
	char password[20];
}CONFIG;

int main()
{
    CONFIG p;

	strcpy(p.host,"192.168.21.1");
	p.port=22;
	strcpy(p.protocol,"Telnet");
	strcpy(p.username,"User77");
	strcpy(p.password,"User@123!");

	printf("\n Putty host address : %s",p.host);
	printf("\n Putty port number : %d",p.port);
	printf("\n Putty Protocol : %s",p.protocol);
	printf("\n Putty username : %s",p.username);
	printf("\n Putty password : %s",p.password);
	printf("\n");
	return 0;
}
