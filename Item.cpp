#include <iostream>

class Item {
private:
   int id;
   int tezina;
public:
	Item():id(0), tezina(0) {}
	Item(int id1, int tezina1):id(id1), tezina(tezina1) {}
	int getId() {
		return id;
	}
	int getTezina() {
		return tezina;
	}
};