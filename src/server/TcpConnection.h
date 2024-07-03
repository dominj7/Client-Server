#include <SFML/Network.hpp>
#include <mutex>

class TcpConnection
{
public:
	void listen(const unsigned short port, std::vector< std::unique_ptr< sf::UdpSocket > >&,
	            std::mutex&, sf::SocketSelector&);
};