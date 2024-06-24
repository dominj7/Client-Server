#include "TcpConnection.h"
#include <SFML/Network.hpp>
#include <thread>

class Server final
{
public:
	~Server();
	void listenTcp(const unsigned short port);

private:
	TcpConnection                  m_tcpConnection;
	std::unique_ptr< std::thread > m_tcpThread;
};