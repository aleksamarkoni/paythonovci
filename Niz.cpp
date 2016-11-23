#include <iostream>

using namespace std;

class Vojnik {
public:
	int i;
	bool ziv;
	Vojnik() {
		ziv = true;
	}
	friend ostream &operator<<( ostream &output, const Vojnik &a ) {
		output << "(" << a.i << "," << (a.ziv?"Ziv":"Mrtav") << ")";
	return output;
	}
};

class Niz {
public:
   int z;
   int u;
   Vojnik *krug;
   Niz() {
      z = 5;
	  u = 5;
	  krug = new Vojnik[u];
	  for (int i = 0; i < z; i++) {
			krug[i].i = i+1;
		 }
   }
   
   Niz(int koliko) {
	   z = koliko;
	   u = koliko;
	   krug = new Vojnik[u];
	   for (int i = 0; i < z; i++) {
			krug[i].i = i+1;
		 }
   }
   
   // dodati parametar i koji predstavlja kojeg vojnika od sebe ubijas
   // ako je prazno to jest jedan, do znaci ubijas vojnika do sebe
   // ako je dva onda drugog od sebe itd.
   // modifikovati program da radi ispravno i u tom slucaju.
   Vojnik lastStand() {
	   // napraviti nov niz koliko i napraviti da ima 'u' vojnika
	   while(z > 1) {
		killThemAll();
		removeDeadSolders();
	   }
	   return krug[0];
   }
   
   void killThemAll() {
	   for (int i = 0; i < z; i+=2) {
			   krug[(i+1)%z].ziv = false; // ubij vojnika do sebe
	   }
   }
   //napraviti metodu int killThemAll() koja vraca koliko je vojnika preostalo zivih
   // marko i dusan
   
   void removeDeadSolders() {
	   // izracunati koliko je preostalo zivih koristeci for petlju
	   // pesic, nikola i zolak
	   
	   // napraviti niz koji ima onoliko elemenata koliko ima prezivelih vojnika.
	   Vojnik *krugZivih = new Vojnik[u];
	   int br = 0;
	   for (int i = 0; i < z; i++) {
		   if (krug[i].ziv) {
			   krugZivih[br++] = krug[i];
		   }
	   }
	   z = br;
	   delete [] krug;
	   krug = krugZivih;
   }
   
   // napraviti novu metodu koja ne pravi nov krug, vec samo izbacuje mrtve iz postojeceg kruga
   void removeDeadSoldersInPlace() {
	   int br = 0;
	   for (int i = 0; i < z; i++) {
		   if (krug[i].ziv) {
			   krug[br++] = krug[i];
		   }
	   }
	   z = br;
   }
   
   // napraviti novu metodu koja ne pravi nov krug, vec samo izbacuje mrtve iz postojeceg kruga
   void removeDeadSoldersInPlace2() {
	   //int br = 0;
	   //if (br mrtav)
		//   izbaci ga iz niza
	    //   i smanji ukupan broj elemenat za 1
	   //ovo treba da ponavljam dok ne izbacim sve mrtve, to jest dok ne stignem do kraja niza.
   }
   
  
   
   
   friend ostream &operator<<( ostream &output, const Niz &a ) {
		output << "[";
		if (a.z > 0) {
			int i = 0;
			for (; i < a.z - 1; i++) {
				output << a.krug[i] << ",";
			}
			output << a.krug[i];
		}
		output << "]";
		return output;
	}
};

int main() {
   Niz test;
   cout << test << endl;
   test.killThemAll();
   cout << test << endl;
   test.removeDeadSolders();
   cout << test << endl;
   test.killThemAll();
   cout << test << endl;
   test.removeDeadSolders();
   cout << test << endl;
   
   Niz test1(41);
   cout << test1.lastStand() << endl;
   
   cout << test1.lastStand() << endl;
   
   // prebaciti sve u h, napraviti make fajl
   // zatim napisati testove, nadjite video i formulu 
   // i onda uporedite da li lastStand vraca isto sto i formula
   
   
}