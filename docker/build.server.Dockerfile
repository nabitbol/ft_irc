FROM alpine:3.21@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099

ENV TERM xterm 

RUN apk add build-base ncurses

WORKDIR /usr/irc

COPY / /usr/irc

RUN make

EXPOSE 6667/tcp

ENTRYPOINT ["./bin/ircserv"]
CMD ["6667", "password"]
