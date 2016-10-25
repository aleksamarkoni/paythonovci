CC=gcc

%.o: %.c mojefunkcije.h
	$(CC) -c -o $@ $<

program: program.o mojefunkcije.o
	$(CC) -o program program.o mojefunkcije.o

clean:
	rm program program.o mojefunkcije.o
