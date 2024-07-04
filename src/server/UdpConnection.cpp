#include "UdpConnection.h"
#include <iostream>

static const std::string udpPrefix{ "UDP:\t" };

void UdpConnection::listen(const unsigned short                             port,
                           std::vector< std::unique_ptr< sf::UdpSocket > >& udpSockets,
                           std::mutex& udpSocketsMutex, sf::SocketSelector& udpSelector)
{
	while (true)
	{
		checkForReadySockets(udpSockets, udpSocketsMutex, udpSelector);
	}
}

void UdpConnection::checkForReadySockets(
    std::vector< std::unique_ptr< sf::UdpSocket > >& udpSockets, std::mutex& udpSocketsMutex,
    sf::SocketSelector& udpSelector)
{
	std::lock_guard< std::mutex > guard(udpSocketsMutex);
	if (udpSelector.wait(sf::Time(sf::milliseconds(10))))
	{
		for (auto& client : udpSockets)
		{
			if (udpSelector.isReady(*client))
				handleReadySocket(client);
		}
	}
}

void UdpConnection::handleReadySocket(std::unique_ptr< sf::UdpSocket >& client)
{
	sf::Packet     packet;
	sf::IpAddress  senderAddress;
	unsigned short senderPort;

	if (client->receive(packet, senderAddress, senderPort) != sf::Socket::Done)
		return;

	std::string data{};
	packet >> data;
	std::cout << udpPrefix << data << '\n';
}
