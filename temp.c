/*"Copyright [2016] <pesic>"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BROJ_POGRESNIH_UNOSA 3
#define JEDAN_OSAM 1.8
#define TRIDESET_DVA 32
#define PET 5.0
#define DEVET 9.0

struct istorija {
  float celsius;
  float fahrenheit;
  int tip;
};
struct istorija memorija[20];
int brojac;

void unos_history_celsius(float celsius, int tip, float fahrenheit) {
  if ( brojac > 4){
    for ( (brojac) = 1 ; (brojac) < 5; (brojac)++ ){
      memorija[brojac-1].fahrenheit = memorija[brojac].fahrenheit;
      memorija[brojac-1].celsius = memorija[brojac].celsius;
      memorija[brojac-1].tip = memorija[brojac].tip;}
      brojac = 4;
      memorija[brojac].celsius = celsius;
      memorija[brojac].tip = tip;
      memorija[brojac].fahrenheit = fahrenheit;
    }
  else {
    memorija[brojac].celsius = celsius;
    memorija[brojac].tip = tip;
    memorija[brojac].fahrenheit = fahrenheit;
  }
}

float konvert_iz_cels_u_farh(float celsius) {
return ((JEDAN_OSAM * celsius) + TRIDESET_DVA);
}

float konvert_iz_farh_u_cels(float fahrenheit) {
return ((PET/DEVET) * (fahrenheit - TRIDESET_DVA));
}

void konvert_cf() {
  int tip = 0;
  float celsius;
  float fahrenheit;
  printf("\nUnesite temperaturu u Celzijusima: ");
  scanf("%f", &celsius);
  fahrenheit=konvert_iz_cels_u_farh(celsius);
  unos_history_celsius(celsius, tip, fahrenheit);

  printf("Temperatura u Farenhaitima je: %f\n", fahrenheit);
}
void konvert_fc() {
  int tip = 1;
  float celsius;
  float fahrenheit;
  printf("\nUnesite temperaturu u Farenhaitima: ");
  scanf("%f", &fahrenheit);
  celsius = konvert_iz_farh_u_cels(fahrenheit);
  unos_history_celsius(celsius, tip, fahrenheit);
  printf("Temperatura u Celsiusima je: %f\n", celsius);
}
void tabela() {
  float celsius;
  float fahrenheit;
  printf("\nCelzijusi Farenhaiti\n");
  printf("--------------------");
  celsius = 0;
  while (celsius <= 100) {
    fahrenheit=konvert_iz_cels_u_farh(celsius);
    printf("\n%6.2f%11.2f", celsius, fahrenheit);
    celsius = celsius + 5; }
    printf("\n--------------------\n");
}
void konvert_again1() {
  char answer;
  printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd') {
  konvert_cf(brojac);
  printf("\nDa li zelite da konvertujete ponovo? [D/N]\n");
  }
}
void konvert_again2() {
  char answer;
  printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd') {
  konvert_fc(brojac);
  printf("\nDa li zelite da konvertujete ponovo? [D/N]\n");
  }
}
void prikazi_menu(int *izbor) {
  printf("\nSta zelite da konvertujete?:");
  printf("\n****************************");
  printf("\n1. Iz Celzijusa u Farenhaite\n");
  printf("2. Iz Farenhaita u Celzijuse\n");
  printf("3. Tablica konvertovanja\n");
  printf("4. Istorijat konvertovanja\n");
  printf("5. Izlaz\n");
  printf("Unesite vas izbor: ");
  scanf("%d", izbor);
}
void history_ispis () {
  int j;
      for(j = 0; j < 5; j++) {
        printf("%d: tip %d %.2f C %.2f F\n",(j+1), memorija[j].tip,
         memorija[j].celsius, memorija[j].fahrenheit);}
         printf("\ntip 0 - iz Celzijusa u Farenhaita\n");
         printf("tip 1 - iz Farenhaita u Celzijusa\n");
  }

int main() {
  int pogresni_unos = 0;
  char answer;
  int izbor, izbor2;
  do {
    prikazi_menu(&izbor);
  switch (izbor) {
  case 1:
  do {
    konvert_cf();
    brojac++;
    printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  } while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd');
    pogresni_unos = 0;
  break;
  case 2:
  do {
    konvert_fc();
    brojac++;
    printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  } while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd');
    pogresni_unos = 0;
  break;
  case 3:
    tabela();
    pogresni_unos = 0;
  break;
  case 4:
    printf("\nIstorijat konvertovanja\n");
    history_ispis ();
    pogresni_unos = 0;
  break;
  case 5:
    printf("Hvala na koristenju programa.\n");
    pogresni_unos = 0;
  break;
  default:
    printf("Pogresan unos, pokusajte ponovo.\n");
    pogresni_unos++;
      if (pogresni_unos == 3) {
        printf("Jebo mamu al si glup, moze samo tri puta.\n");
      return 0;
   }
  }
 }
  while (izbor != 5);
}
