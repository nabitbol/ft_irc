#! /bin/bash
#
# A script to manage launching the IRC server with or without a bot concurrently

ac=$#

err() {
  echo "[$(date +'%Y-%m-%dT%H:%M:%S%z')]: $*" >&2
}

start_irc_services() {
	server_tab_name=${1}
	bot_tab_name=${2}

	x-terminal-emulator -T ${server_tab_name} -e bash -c "./bin/ircserv ${3} ${4} | cat - e" &
	sleep 2
	x-terminal-emulator -T ${bot_tab_name} -e bash -c "cd ./bot; ./bin/bot_client ${4}"
}

cat << END

Hi $(whoami)!
if you got some problem with the bot start command please check your default x-termainal-emulator.
You can change it by using the command: [sudo update-alternatives --config x-terminal-emulator].

END

if [ ${ac} -eq 2 ]; then
	
	make
	./bin/ircserv ${1} ${2}

elif [ ${ac} -eq 3 ]; then
	
	if [ ${3} = -b ]; then
		
		make ; \
		cd ./bot && make; \
		cd ../

		start_irc_services "Server IRC" "Bot IRC" ${1} ${2}

	else
		err "Wrong arguments... Try with ./script.sh [server port] [password] [bot]"
	fi

else
	err "Wrong number of arguments... Try with ./script.sh [server port] [password] optional: [bot]"
fi
