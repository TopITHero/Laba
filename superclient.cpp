#include "superclient.h"

SuperClient::SuperClient(){
	port = 5000;
	sockfd = socket(AF_INET, SOCK_STREAM,0);
	server = gethostbyname("127.0.0.1");
	bzero((char* ) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char * )server->h_addr, (char * )&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port);
	connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
}
SuperClient::~SuperClient(){
	close(sockfd);
}

void SuperClient::talking(char* msg){
	bzero(buffer,256);
	strcpy(buffer,msg);
	write(sockfd, buffer, strlen(buffer));
}