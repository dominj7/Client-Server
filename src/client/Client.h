#include <SFML/Network.hpp>
#include <optional>

class Client
{
public:
	Client(sf::IpAddress serverAddress = "127.0.0.1");
	void connectTcp(const unsigned short port);
	void sendTcp(sf::Packet packet);
	void sendTcp(std::string message);
	void sendUdp(const unsigned short port, sf::Packet packet);
	void sendUdp(const unsigned short port, std::string message);

	std::optional< sf::Uint16 > recvUdpPort();

private:
	const sf::IpAddress m_serverAddress;
	sf::TcpSocket       m_tcpSocket;
};