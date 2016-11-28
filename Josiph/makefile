CC=g++
DEPS = Josiphklasa.h Vojnik.h VojnikGS.h Sreckovic.h Glavonja.h

vojnik: Josiph.o Josiphklasa.o Vojnik.o VojnikGS.o Sreckovic.o Glavonja.o
	$(CC) -o $@ $<

%.o: Josiph.cpp $(DEPS)
	$(CC) -c Josiph.cpp Josiphklasa.h Vojnik.h Vojnik.cpp VojnikGS.h VojnikGS.cpp Sreckovic.h Sreckovic.cpp 
	Glavonja.h Glavonja.cpp

clean:
	rm vojnik Josiph.o
