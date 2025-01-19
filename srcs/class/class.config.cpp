#include "ft_irc.hpp"

/* ------------------------ constructors/destructors ------------------------ */


Config::Config() {
	sock = socket(IP_TYPE, SOCKET_TYPE, 0);
	int opt = 1;
	port = DEFAULT_PORT;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	addr.sin_addr.s_addr = inet_addr(HOST);
	addr.sin_family = IP_TYPE;
	addr.sin_port = htons(port);
}

Config::Config(int serverPort, Error &error) {
	sock = socket(IP_TYPE, SOCKET_TYPE, 0);
	int opt = 1;
	if(!isValidPort(serverPort))
		error.type = INVALID_PORT;
	error.displayError();
	port = serverPort;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	addr.sin_addr.s_addr = inet_addr(HOST);
	addr.sin_family = IP_TYPE;
	addr.sin_port = htons(port);
};

Config::~Config() {};

/* ------------------------------ config check ------------------------------ */

/*
** The value space of unsigned short is between 0 and 65535 which is the same as
** the number of port available in common devices. Here we check if the we
** can cast the port in an unsigned short, this way we can define if the port is valid or not.
*/
bool Config::isValidPort(int port) {
  return static_cast<unsigned short>(port) == port && port >= 0;
}
