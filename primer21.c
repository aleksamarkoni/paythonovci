#include<stdio.h>

typedef struct Pravougaonik {
   int x;
   int y;
   int sirina;
   int duzina;
} Prav;

void pravougaonikIspis(Prav a) {
   printf("Pravougaonik info: \n");
   printf("x kor je: %d\n", a.x);
   printf("y kor je: %d\n", a.y);
   printf("sirina je: %d\n", a.sirina);
   printf("duzina je: %d\n", a.duzina);
   printf("-----------------\n");
}

struct PresekPP {
   int povrsina;
   Prav presek;
};

struct PresekPP presekDvaPravougaonika(Prav a, Prav *b) {
    struct PresekPP pp;
    //(*b).x <=> b->x 
    // ovde dolazi deo koji vi morate da uradite i da popunite ovu strukturu
    return pp;
}

int povrsinaPrav(Prav a) {
   return a.sirina * a.duzina;
}

int main() {
   Prav a;
   Prav b;
   pravougaonikIspis(a);
   a.x = 0;
   a.y = 0;
   a.sirina = 10;
   a.duzina = 23;
   b.x = 0;
   b.y = 0;
   b.sirina = 12;
   b.duzina = 10;
   pravougaonikIspis(a);
   pravougaonikIspis(b);
   printf("povrsina %d\n", povrsinaPrav(a) );
   printf("povrsina %d\n", povrsinaPrav(b) );
   return 0;
}
