#include <iostream>
#include <stdexcept>	

using namespace std;

int deli(int a, int b) {
    if (b == 0) {
		throw overflow_error("Divide by zero exception");
	}
	return a/b;
  
}

int main() {
	try  {
	   int d = deli(5, 0);
	   cout << d << endl;
	} catch(overflow_error e) {
		cout << e.what() << endl;
	}
	cout << "Program se nastavlja" << endl;
}