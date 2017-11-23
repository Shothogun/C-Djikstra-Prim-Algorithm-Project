CC = gcc
CFLAGS = -I~/Documents/Otho/Programas/Projeto_ED_2/Programa -pedantic -W -Wall
DEPS = IO.h Graph.h  Prim_prog.h Dijkstra_prog.h
OBJ = main.o IO.o Graph.o  Prim_prog.o Dijkstra_prog.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

Projeto_ED_2: $(OBJ)
	gcc -g -o $@ $^ $(CFLAGS)

