o: client.o server.o
	gcc client.o server.o -o o
client.o: client.c server.h
	gcc -c client.c
server.o: server.c
	gcc -c server.c