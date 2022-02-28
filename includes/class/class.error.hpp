#ifndef CLASS_ERROR_HPP
# define CLASS_ERROR_HPP

class User;

enum errorType {
	ARGUMENT,
    UNAVAILABLE_PORT,

	ERR_NOSUCHNICK,
	ERR_NOSUCHSERVER,
	ERR_NOSUCHCHANNEL,
	ERR_CANNOTSENDTOCHAN,
	ERR_TOOMANYCHANNELS,
	ERR_RESTRICTED,
	ERR_CHANNELISFULL,
	ERR_UNKNOWNMODE,
	ERR_INVITEONLYCHAN,
	ERR_NEEDMOREPARAMS,
	ERR_NICKNAMEINUSE,
	ERR_BANNEDFROMCHAN,
	ERR_BADCHANNELKEY,
	ERR_BADCHANMASK,
	ERR_NOCHANMODES,
	ERR_BANLISTFULL,
	ERR_NOPRIVILEGES,
	ERR_CHANOPRIVSNEEDED,
	ERR_CANTKILLSERVER,
	ERR_UNIQOPPRIVSNEEDED,
	ERR_NOOPERHOST,
	ERR_UMODEUNKNOWNFLAG,
	ERR_USERSDONTMATCH,
	NO_ERROR
};

class Error {

    public:
	errorType	type;
	std::map<errorType, std::string> errorMessages;

	Error();
	Error(Error &);
	~Error();

	void		displayError();
	void		setErrorType(errorType &);
	void		sendError(std::string , errorType());

	std::string	getMessageWithReplaceToken(const char *, const char *, const char *, errorType &);
	void		sendError(const char *, const char *, const char *, errorType &, User *);
};

#endif
