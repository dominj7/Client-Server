#include <SFML/Network.hpp>
#include <iostream>

#include "Client.h"
#include <iomanip>

int main()
{
	std::cout << "\tClient" << std::endl;

	Client               client;
	static constexpr unsigned short tcpPort{ 9069 }, udpPort{ 2020 };
	client.connectTcp(tcpPort);

	while (true)
	{
		std::string message;
		std::cin >> message;
		client.sendTcp(message);
		client.sendUdp(udpPort, message);
	}
}