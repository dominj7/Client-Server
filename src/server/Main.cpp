#include "Server.h"
#include <iostream>

int main()
{
	std::cout << "\tServer" << std::endl;

	Server               server;
	static constexpr unsigned short tcpPort{ 2020 };
	server.listenTcp(tcpPort);
}