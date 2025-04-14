# Ft_irc

## Table of contents
- [ft_irc](#ft_irc)
	- [Table of contents](#table-of-contents)
	- [Project description](#project-description)
	- [Quick start](#quick-start)
	- [Our approach](#our-approach)
		- [Github project](#github-project)
		- [Gitmoji](#gitmoji)
		- [Review](#review)
	- [Conception](#conception)
	- [Contributors](#contributors)


## Project description

Simple implementation of a IRC server in C++98. Following the [RFC 1459](https://datatracker.ietf.org/doc/html/rfc1459) and [RFC 2813](https://datatracker.ietf.org/doc/html/rfc2813) guidelines.

We used HexChat as an IRC client reference to be sure all the functionality enumerated here works.

## Quick start

Clone the repository and move in it with the **cd** command. You can then run this command:

```bash
$> bash runServ.sh <port> <password> optional:-b
```

## Run with docker

Name the Docker image as you want; for instance, it could be `irc_server`. A Docker Compose file should be rolled out later.

```bash
$> docker build --file ./docker/build.<application_to_run>.Dockerfile . -t <docker image>
$> docker run -p <port>:<port> <docker image> <password> 
```

## Commands available

> - PASS
> - JOIN
> - PART
> - PRIVMSG
> - Away
> - LIST
> - QUIT
> - USER
> - TOPIC
> - NICK
> - TIME
> - MODE
> - NOTICE
> - WHO

## Modes available

> ### User modes
> - away
> - operator
> - restricted
>
> ### Channel modes
> - i: Set/remove invite-only status for a channel
> - t: Set/remove restrictions on the TOPIC command for channel operators
> - k: Set/remove a channel key (password)
> - o: Give/take channel operator privileges
> - l: Set/remove a user limit for the channel

## Our approach

### Github project

The use of github kanban board allowed us to create task and be more efficient with the repartition of the work.

### Gitmoji

Use emoji to type our commit message https://gitmoji.dev/. It is a way to make programming funnier. 👍

### Review
Our main branch is protected and we implemented mandatory review to keep clean code at all time.

## Conception
Find details about the project data structure [in the notes](/note/data_structure.md)


## Contributors

<a href="https://github.com/nabitbol/ft_irc/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=nabitbol/ft_irc" />
</a>
