CC=g++
DEPS = Josiphklasa.h Vojnik.h VojnikGS.h

vojnik: Josiph.o Josiphklasa.o Vojnik.o VojnikGS.o
	$(CC) -o $@ $<

%.o: Josiph.cpp $(DEPS)
	$(CC) -c Josiph.cpp Josiphklasa.h Vojnik.h VojnikGS.h

clean:
	rm vojnik Josiph.o
