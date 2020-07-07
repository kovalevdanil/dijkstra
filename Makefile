CC = gcc -g

all: main

main: main.o graph.o dijkstra.o 
	$(CC) $^ -o main 

main.o: main.c
	$(CC) $^ -c 

dijkstra.o: dijkstra.c dijkstra.h
	$(CC) $^ -c 

graph.o: graph.c graph.h
	$(CC) $^ -c 

