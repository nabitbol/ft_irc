#include "ft_irc.hpp"

Server::Server(int port): _config(port), _error() {
	addSockToPfds(_config.sock);
};

Server::Server(int port, Error error): _config(port), _error(error) {
	addSockToPfds(_config.sock);
};

Server::~Server() {};

void	Server::sbind()  {
	bind(_config.sock, (const struct sockaddr *)&(_config.addr), sizeof(_config.addr));
	std::cout << "[Bind] : " << _config.sock << "." << std::endl;
}

void	Server::slisten(int num) {
	listen(_config.sock, num);
	std::cout << "[Listening] : You can add until " << num << " users." << std::endl;
}

void	Server::closeUser(int pfds_index) {
	_user[pfds_index - 1]->uclose();
	removeSockFromPfds(pfds_index);
	removeUser(_pfds[pfds_index].fd);
};

void	Server::closeServer() {
	close(_config.sock);
	std::cout << "Server closed." << std::endl;
};

void	Server::ssend(std::string &string, int index) {
	_user[index]->usend(string);
};

int		Server::srecv(std::string *string, int index) {
	return (_user[index]->urecv(string));
};

void    Server::saccept() {
	User *user = new User();

	user->uaccept(_config.sock);
	addUser(user);
	addSockToPfds(user->getSocket());
};

//JOIN
//Check if the channel doesnt exit
void	Server::addChannel(std::string &name, std::string &topic, User *user) {
	Channel *channel = new Channel(name, topic, user);

	//add first user operator status
	_channel.push_back(channel);
};

//PART
void	Server::removeChannel(int &index) {
	delete _channel[index];
	_channel.erase(_channel.begin() + index);
}

std::vector<Channel *>::iterator Server::findChannel(std::string &name) {

	for(std::vector<Channel *>::iterator it = _channel.begin(); it != _channel.end(); it++) {
		if ((*it)->getChannelName() == name)
			return (it);
	}
	return (_channel.end());
}

void	Server::spoll() {
	poll(&_pfds[0], _pfds.size(), -1);
};

bool	Server::spollinCondition(int &index) {
	return (_pfds[index].revents == POLLIN);
};

bool	Server::spolloutCondition(int &index) {
	return (_pfds[index].revents == POLLOUT);
};
void	Server::addUser(User *user) {
	_user.push_back(user);
};

void	Server::removeUser(int &socket) {
	int index = findClientSock(socket);
	if (index > 0) {
		delete _user[index];
		_user.erase(_user.begin() + index);
	}
}

void	Server::addSockToPfds(int socket) {
	_pfds.push_back(pollfd());
	_pfds.back().fd = socket;
	_pfds.back().events = POLLIN;
};

void	Server::removeSockFromPfds(int index) {
	if (index > 0)
		_pfds.erase(_pfds.begin() + index);
};

int		Server::findClientSock(int socket) {
	for (size_t i = 0; i < _user.size(); i++) {
		if (_user[i]->getSocket() == socket)
			return (i);
	}
	return (-1);
};

void	Server::setNick(int index, std::string &string) {
	_user[index]->setNick(string);
}

std::string		&Server::getNick(int index) {
	return (_user[index]->getNick());
};


int		Server::getPfdsSize() {
	return (_pfds.size());
}

std::vector<User *>	Server::getUsers() {
	return (_user);
}

std::vector<Channel *>	Server::getChannels() {
	return (_channel);
}