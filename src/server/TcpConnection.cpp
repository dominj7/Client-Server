#include "TcpConnection.h"
#include <iostream>

static const std::string tcpPrefix{ "TCP:\t" };

void TcpConnection::listen(const unsigned short                             port,
                           std::vector< std::unique_ptr< sf::UdpSocket > >& udpSockets,
                           std::mutex& udpSocketsMutex, sf::SocketSelector& udpSelector)
{
	while (true)
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

		{
			std::lock_guard< std::mutex > guard(udpSocketsMutex);

			auto udpSocket = std::make_unique< sf::UdpSocket >();
			udpSocket->bind(sf::Socket::AnyPort);

			sf::Uint16 localPort = udpSocket->getLocalPort();
			sf::Packet packet;
			packet << localPort;

			std::cout << tcpPrefix << "send initial data to " << clientSocket.getRemoteAddress()
			          << ": " << clientSocket.getRemotePort() << '\n';
			if (clientSocket.send(packet) != sf::Socket::Status::Done)
				std::cerr << tcpPrefix << "wasn't send...\n";

			udpSelector.add(*udpSocket);
			udpSockets.push_back(std::move(udpSocket));
		}
		clientSocket.disconnect();
	}
}