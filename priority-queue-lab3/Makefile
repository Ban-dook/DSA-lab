make: program
	./program

program: que.o ex.o multiq.o
	gcc -o program -pg que.o ex.o multiq.o

multiq.o: multiq.c
	gcc -c multiq.c

que.o: que.c
	gcc -c que.c

ex.o: ex.c
	gcc -c ex.c