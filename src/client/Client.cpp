#include "Client.h"
#include <iostream>

static constexpr std::string tcpPrefix{ "TCP:\t" };

Client::Client(sf::IpAddress serverAddress) :
    m_serverAddress{ serverAddress }
{
}

void Client::connectTcp(const unsigned short port)
{
	if (m_tcpSocket.connect(m_serverAddress, port) != sf::Socket::Status::Done)
	{
		return;
	}
	std::cout << tcpPrefix << "connected to server" << std::endl;
}

void Client::sendTcp(sf::Packet packet)
{
	m_tcpSocket.send(packet);
}

void Client::sendTcp(std::string message)
{
	sf::Packet packet;
	packet << message;
	sendTcp(packet);
}

void Client::sendUdp(const unsigned short port, sf::Packet packet)
{
	sf::UdpSocket udpSocket;
	udpSocket.send(packet, m_serverAddress, port);
}

void Client::sendUdp(const unsigned short port, std::string message)
{
	sf::Packet packet;
	packet << message;
	sendUdp(port, packet);
}