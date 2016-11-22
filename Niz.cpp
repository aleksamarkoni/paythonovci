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
   
   public Vojnik lastStand() {
	   //1.) ubij sve vojnike u krugu
	   killThemAll();
	   //2.) izbaci sve mrtve
	   //3.) ponovi ovaj postupak sve dok ne ostane samo jedan vojnik
   }
   
   public void killThemAll() {
	   //1.) ubij vojnika do sebe i izbaci ga iz niza
	   //Ako ima paran broj vojnika to je to, a ako je neparan ubi i prvog u nizu
	   for (int i = 0; i < z; i+=2) {
		   if (i+1 == z)
		   krug[i+1].ziv = false; // ubij vojnika do sebe
	   }
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
}