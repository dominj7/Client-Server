#include "UdpConnection.h"
#include <iostream>

static constexpr std::string udpPrefix{ "UDP:\t" };

void UdpConnection::listen(const unsigned short port)
{
	sf::UdpSocket socket;
	if (socket.bind(port) != sf::Socket::Status::Done)
		return;

	while (true)
	{
		sf::Packet     packet;
		sf::IpAddress  senderAddress;
		unsigned short senderPort{};
		if (socket.receive(packet, senderAddress, senderPort) != sf::Socket::Status::Done)
			break;

		std::string message;
		packet >> message;
		std::cout << udpPrefix << message << std::endl;
	}
}