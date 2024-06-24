#include "Server.h"

Server::~Server()
{
	m_tcpThread->join();
}

void Server::listenTcp(const unsigned short port)
{
	m_tcpThread = std::make_unique< std::thread >(&TcpConnection::listen, &m_tcpConnection, port);
}