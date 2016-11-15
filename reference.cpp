#include <iostream>
#include <sys/time.h>
#include "Tacka.h"

#define HOW_MENU_TIMES 100000



using namespace std;

//bool daLiSuIste(Tacka a, Tacka b) {
//	if (a.getX() != b.getX())
//	   return false;
//	if (a.getY() != b.getY())
//	   return false;
//	return true;
//}

bool daLiSuIste(Tacka *a, Tacka *b, Tacka *c, Tacka *d) {
	//cout << "Sa pokazivacem" << endl;
	if ((*a).getX() != (*b).getX()) {
		return false;
	}
	if (a->getY() != b->getY()) {
		return false;
	}
	return true;
}

bool daLiSuIste(Tacka &a, Tacka &b, Tacka &c, Tacka &d) {
	//cout << "Sa referencom" << endl;
	if (a.getX() != b.getX())
	   return false;
	if (a.getY() != b.getY())
	   return false;
	return true;
}

void testSaKopijama() {
	timeval tv;
	gettimeofday(&tv, 0);
	long testStart = tv.tv_usec / 1000;
	Tacka t1(5, 5);
	for (int i = 0; i < HOW_MENU_TIMES; i++) {
		daLiSuIste(t1, t1, t1, t1);
	}
	gettimeofday(&tv, 0);
	long testEnd = tv.tv_usec / 1000;
	cout << "Test kopiranja: " << (testEnd-testStart) << endl;
}

void testSaPokazivacima() {
	timeval tv;
	gettimeofday(&tv, 0);
	long testStart = tv.tv_usec / 1000;
	Tacka t1(5, 5);
	for (int i = 0; i < HOW_MENU_TIMES; i++) {
		daLiSuIste(&t1, &t1, &t1, &t1);
	}
	gettimeofday(&tv, 0);
	long testEnd = tv.tv_usec / 1000;
	cout << "Test kopiranja: " << (testEnd-testStart) << endl;
}

int main() {
	Tacka t1(5, 5);
	Tacka t2(6, 6);
	Tacka t3(6, 6);
	//cout << "Da li su jednake: " << daLiSuIste(t1, t2) << endl;
	//cout << "Da li su jednake: " << daLiSuIste(t3, t2) << endl;
	//cout << "Da li su jednake: " << daLiSuIste(&t1, &t2) << endl;
	//cout << "Da li su jednake: " << daLiSuIste(&t3, &t2) << endl;
	//cout << "Da li su jednake: " << daLiSuIste(t1, t2) << endl;
	//cout << "Da li su jednake: " << daLiSuIste(t3, t2) << endl;
	cout << "Pokazivaci" << endl;
	testSaPokazivacima();
	cout << "Kopiranje" << endl;
	testSaKopijama();
}