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

bool Config::isValidPort(int port) {	
	int minPortValue = 0;
	int maxPortValue = 65535;

	return port >= minPortValue && port <= maxPortValue;
}
