#include <SFML/Network.hpp>
#include <iostream>

#include "Client.h"
#include <iomanip>

int main()
{
	std::cout << "\tClient" << std::endl;

	Client               client;
	static constexpr unsigned short port{ 2020 };
	client.connectTcp(port);

	while (true)
	{
		std::string message;
		std::cin >> message;
		client.sendTcp(message);
	}
}