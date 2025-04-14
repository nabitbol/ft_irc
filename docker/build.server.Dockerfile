FROM alpine:3.21@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099

ENV TERM xterm 

RUN apk add build-base ncurses

WORKDIR /usr/irc

COPY / /usr/irc

RUN make re

# If you need to handle SIGTERM in the container
# you should use tini, running as PID 1 it handle
# SIGTERM signal and potential zombie processes
# Check https://github.com/krallin/tini

ENTRYPOINT ["./bin/ircserv"]
CMD ["6667", "password"]
