#include <SFML/Network.hpp>
#include <iostream>

#include "Client.h"
#include <iomanip>

int main()
{
	std::cout << "\tClient" << std::endl;

	Client                          client;
	static constexpr unsigned short tcpPort{ 9069 };
	client.connectTcp(tcpPort);
	std::optional< sf::Uint16 > udpPort = client.recvUdpPort();

	if (!udpPort.has_value())
		return 1;

	std::cout << "Port: " << udpPort.value() << '\n';
	while (true)
	{
		std::string message;
		std::cin >> message;
		client.sendUdp(udpPort.value(), message);
		// client.sendTcp(message);
	}
}