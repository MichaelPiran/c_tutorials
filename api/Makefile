CC = gcc
CFLAGS = -Wall -Wextra $(shell pkg-config --cflags libmicrohttpd)
LIBS = $(shell pkg-config --libs libmicrohttpd) -lcjson

OBJS = main.o handlers.o

all: rest_server

rest_server: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) rest_server
