CC=g++

%.o: %.cpp Tacka.h Pravougaonik.h
	$(CC) -c -o $@ $<

program: primer21.o Tacka.o Pravougaonik.o
	$(CC) -o primer primer21.o Tacka.o Pravougaonik.o

clean:
	rm primer primer21.o Tacka.o Pravougaonik.o
