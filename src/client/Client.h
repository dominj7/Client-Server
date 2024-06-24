#include <SFML/Network.hpp>

class Client
{
public:
	Client(sf::IpAddress serverAddress = "127.0.0.1");
	void connectTcp(const unsigned short port);
	void sendTcp(sf::Packet packet);
	void sendTcp(std::string message);

private:
	const sf::IpAddress m_serverAddress;
	sf::TcpSocket       m_tcpSocket;
};