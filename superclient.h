#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

using namespace std;

class SuperClient {
private:
	int sockfd, port;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
public:
	SuperClient();
	~SuperClient();
	void talking(char*);	
};