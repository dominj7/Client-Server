#include <SFML/Network.hpp>
#include <mutex>

class UdpConnection
{
public:
	void listen(const unsigned short port, std::vector< std::unique_ptr< sf::UdpSocket > >&,
	            std::mutex&, sf::SocketSelector&);

private:
	void checkForReadySockets(std::vector< std::unique_ptr< sf::UdpSocket > >&, std::mutex&,
	                          sf::SocketSelector&);
	void handleReadySocket(std::unique_ptr< sf::UdpSocket >&);
};