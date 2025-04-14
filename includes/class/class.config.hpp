#ifndef CLASS_CONFIG_HPP
# define CLASS_CONFIG_HPP

class Error;
class Config {

    public:

/* ---------------------------------- data ---------------------------------- */

	int						sock;
	int						port;
	struct sockaddr_in 		addr;

/* ------------------------ constructors/destructors ------------------------ */

	Config();
	Config(int, Error &);
	~Config();

/* ------------------------------ config check ------------------------------ */

	bool isValidPort(int);

};


#endif
