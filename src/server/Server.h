#include "TcpConnection.h"
#include "UdpConnection.h"
#include <SFML/Network.hpp>
#include <mutex>
#include <thread>
#include <vector>

class Server final
{
public:
	~Server();
	void listenTcp(const unsigned short port);
	void listenUdp(const unsigned short port);

private:
	TcpConnection                  m_tcpConnection;
	UdpConnection                  m_udpConnection;
	std::unique_ptr< std::thread > m_tcpThread, m_udpThread;

	std::vector< std::unique_ptr< sf::UdpSocket > > m_udpSockets;
	std::mutex                                      m_udpSocketsMutex{};
	sf::SocketSelector                              m_udpSelector;
};