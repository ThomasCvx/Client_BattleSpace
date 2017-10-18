#pragma once
#ifndef CLIENT_NETWORK
# define CLIENT_NETWORK

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <WinSock2.h>

class ClientNetwork {
private:
	SOCKET sock;
	std::string address;
	int port;
	SOCKADDR_IN server;

public:
	ClientNetwork();
	bool connectServer(std::string, int);
	bool sendData(std::string data);
	std::string receive(int);

};

#endif // CLIENT_NETWORK_H