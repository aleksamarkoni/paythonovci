#include <iostream>

using namespace std;

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
	//saberi(a, b)
	//a + b
	
	//<<(cout, id)
	//(cout << id) << b
	
	friend ostream &operator<<( ostream &output, 
         const Item &item ) { 
         output << "Id: : " << item.id << " Tezina : " << item.tezina;
         return output;            
      }

    friend istream &operator>>( istream  &input, Item &item ) { 
		 input >> item.id >> item.tezina;
         return input;            
      }
};