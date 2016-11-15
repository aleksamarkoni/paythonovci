#include <iostream>
#include <climits>
#include <math.h>
#include <stdlib.h>
#include "Pravougaonik.h"
#include "Tacka.h"
using namespace std;

void test(Pravougaonik a, Pravougaonik b, Pravougaonik c);

int main() {
   Tacka t(4,4);
   Tacka t1(6, 6);
   Pravougaonik a(6,6,8,4);
   Pravougaonik b(3,3,10,8);
   Pravougaonik c(6,6,7,4);
   test(a, b, c); // Sredina desno presek
   Pravougaonik a1(1,1,1,1);
   Pravougaonik b1(10,10,1,1);
   Pravougaonik c1(0,0,0,0);
   test(a1,b1,c1); // Gore levo, dole desno (VAN)
   Pravougaonik a2(8,8,7,4);
   Pravougaonik b2(3,3,10,8);
   Pravougaonik c2(8,8,5,3);
   test(a2,b2,c2); //Dole desno presek
   Pravougaonik a3(6,8,3,5);
   Pravougaonik b3(3,3,10,8);
   Pravougaonik c3(6,8,3,3);
   test(a3,b3,c3); //Dole sredina presek
   Pravougaonik a4(1,6,3,3);
   Pravougaonik b4(3,3,10,8);
   Pravougaonik c4(3,6,1,3);
   test(a4,b4,c4); //Levo srednji presek
   Pravougaonik a5(1,9,3,3);
   Pravougaonik b5(3,3,10,8);
   Pravougaonik c5(3,9,1,2);
   test(a5,b5,c5); //Donji levi presek
   Pravougaonik a6(1,1,3,3);
   Pravougaonik b6(0,0,2,2);
   Pravougaonik c6(1,1,1,1);
   test(a6,b6,c6); //Gornji levi presek
   Pravougaonik a7(1,1,3,3);
   Pravougaonik b7(2,0,1,2);
   Pravougaonik c7(2,1,1,1);
   test(a7,b7,c7); //Gornji srednji presek
   Pravougaonik a8(2,2,5,5);
   Pravougaonik b8(4,1,5,4);
   Pravougaonik c8(4,2,3,3);
   test(a8,b8,c8); //Gornji desni presek
   Pravougaonik a9(2,2,5,5);
   Pravougaonik b9(4,4,2,2);
   Pravougaonik c9(4,4,2,2);
   test(a9,b9,c9); //Sredina nema preseka
   Pravougaonik a10(10,1,5,5);
   Pravougaonik b10(1,10,2,2);
   Pravougaonik c10(0,0,0,0);
   test(a10,b10,c10); //Dole levo i gore desno (VAN)
   Pravougaonik a11(2,2,3,3);
   Pravougaonik b11(3,1,1,5);
   Pravougaonik c11(3,2,1,3);
   test(a11,b11,c11); //Sredina vertikalno preseca i gore i dole
   Pravougaonik a12(2,2,3,3);
   Pravougaonik b12(1,3,5,1);
   Pravougaonik c12(2,3,3,1);
   test(a12,b12,c12); //Sredina horizontalno preseca i gore i dole
   Pravougaonik a13(2,2,4,3);
   Pravougaonik b13(1,1,2,5);
   Pravougaonik c13(2,2,1,3);
   test(a13,b13,c13); //Levo vertikalno preseca i gore i dole
   Pravougaonik a14(2,2,4,3);
   Pravougaonik b14(5,1,2,5);
   Pravougaonik c14(5,2,1,3);
   test(a14,b14,c14); //Desno vertikalno preseca i gore i dole
   Pravougaonik a15(2,2,4,3);
   Pravougaonik b15(1,1,6,2);
   Pravougaonik c15(2,2,4,1);
   test(a15,b15,c15); //Gore horizontalno preseca
   Pravougaonik a16(2,2,4,3);
   Pravougaonik b16(1,4,6,2);
   Pravougaonik c16(2,4,4,1);
   test(a16,b16,c16); //Dole horizontalno preseca
   Pravougaonik a17(2,2,4,3);
   Pravougaonik b17(3,10,3,2);
   Pravougaonik c17(0,0,0,0);
   test(a17,b17,c17); //Gore i dole (VAN)
   Pravougaonik a18(2,2,4,3);
   Pravougaonik b18(7,2,2,3);
   Pravougaonik c18(0,0,0,0);
   test(a18,b18,c18); //Levo i desno (VAN)

   return 0;
}
void test(Pravougaonik a, Pravougaonik b, Pravougaonik c) {
	Pravougaonik pp = a.presekDvaPravougaonika(b);
	if (pp == c) {
		cout << "Test je prosao." << endl;
    cout << pp.getX() << " " << pp.getY() << " " << pp.getDuzina() << " " << pp.getSirina() << endl;
	} else {
		cout << "Test je pao." << endl;
    cout << pp.getX() << " " << pp.getY() << " " << pp.getDuzina() << " " << pp.getSirina() << endl;
	}
}
