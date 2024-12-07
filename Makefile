all: kinopoisk

kinopoisk: main.o kinopoisk.o
	gcc -o kinopoisk main.o kinopoisk.o

main.o: main.c kinopoisk.h
	gcc -Wall -c main.c

kinopoisk.o: kinopoisk.c kinopoisk.h
	gcc -Wall -c kinopoisk.c

clean:
	rm -f *.o kinopoisk films.dat
