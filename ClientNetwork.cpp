#include "ClientNetwork.h"

ClientNetwork::ClientNetwork()
{
	port = 0;
	address = "";
}

/**
Connect to a host on a certain port number
*/
bool ClientNetwork::connectServer(std::string address, int port)
{
	WSADATA WSAData;

	WSAStartup(MAKEWORD(2, 2), &WSAData);

	//Create socket
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		std::cout << "Erreur creation socket : " << WSAGetLastError() << std::endl;
		return 0;
	}

	//plain ip address
	server.sin_addr.s_addr = inet_addr(address.c_str());

	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	//Connect to remote server
	if (connect(sock, (SOCKADDR*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		perror("connect failed. Error");
		return 1;
	}

	closesocket(sock);
	WSACleanup();

	std::cout << "Connected\n";
	return true;
}

/**
Send data to the connected host
*/
bool ClientNetwork::sendData(std::string data)
{
	//Send some data
	if (send(sock, data.c_str(), strlen(data.c_str()), 0) < 0)
	{
		perror("Send failed : ");
		return false;
	}
	std::cout << "Data send\n";

	return true;
}

/**
Receive data from the connected host
*/
std::string ClientNetwork::receive(int size = 512)
{
	char buffer[512];
	std::string reply;

	//Receive a reply from the server
	if (recv(sock, buffer, sizeof(buffer), 0) < 0)
	{
		puts("recv failed");
	}

	reply = buffer;
	return reply;
}