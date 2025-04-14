#include <cstddef>
#include <typeinfo>
#include "ft_irc.hpp"

std::string	getCapResponse(const std::string& command) {
	std::string response("CAP ");
	
	if (command != "LS" && command != "END") {
  	  response += "NAK * :\n";
  	} else {
  	  response += "LS * :\n";
  	}

	return response;
}

void	capCmd(Server &server, int index, parsed *parsedCommand) {
	std::string response("");

	if (parsedCommand->args.empty()) {
		server.sendErrorUser(parsedCommand->rawCommand.c_str(), NULL, NULL, ERR_NEEDMOREPARAMS, index);
		return;
	}
	response = getCapResponse(*parsedCommand->args[0]);
	server.ssend(response, index);
}
