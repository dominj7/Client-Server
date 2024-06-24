#include "TcpConnection.h"
#include <iostream>

static constexpr std::string tcpPrefix{ "TCP:\t" };

void TcpConnection::listen(const unsigned short port)
{
	sf::TcpListener listener;
	if (listener.listen(port) != sf::Socket::Status::Done)
	{
		return;
	}

	sf::TcpSocket clientSocket;
	if (listener.accept(clientSocket) != sf::Socket::Status::Done)
		return;

	std::cout << tcpPrefix << clientSocket.getRemoteAddress() << " connected" << std::endl;
	while (true)
	{
		sf::Packet packet;
		if (clientSocket.receive(packet) != sf::Socket::Status::Done)
			break;
		std::string message;
		packet >> message;
		std::cout << tcpPrefix << message << std::endl;
	}
}