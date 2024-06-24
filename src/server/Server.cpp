#include "Server.h"

Server::~Server()
{
	m_tcpThread->join();
	m_udpThread->join();
}

void Server::listenTcp(const unsigned short port)
{
	m_tcpThread = std::make_unique< std::thread >(&TcpConnection::listen, &m_tcpConnection, port);
}

void Server::listenUdp(const unsigned short port)
{
	m_udpThread = std::make_unique< std::thread >(&UdpConnection::listen, &m_udpConnection, port);
}