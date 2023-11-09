all: hash

hash.o: my_hash.c my_hash.h
	gcc -c my_hash.c -o my_hash.o

list.o: list.c my_hash.h
	gcc -c list.c -o list.o 

main.o: main.c my_hash.h
	gcc -c main.c -o main.o 

hash: hash.o main.o list.o
	gcc my_hash.o main.o list.o -o hash -lm

clean:
	rm -v *.o hash
