/*"Copyright [2016] <pesic>"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define konverzija_f ((1.8 * celsius) + 32)
#define konverzija_c ((5.0/9.0) * (fahrenheit-32))

struct istorija {
  float celsius;
  float fahrenheit;
};
struct istorija memorija[20];
void unos_history_celsius(float celsius, struct istorija memorija[], int *i) {
  if ( *i > 4){
    for ( (*i) = 1 ; (*i) < 5; (*i)++ ){
      memorija[*i-1].celsius = memorija[*i].celsius; }
      *i = 4;
      memorija[*i].celsius = celsius; }
  else {
    memorija[*i].celsius = celsius;
  }
}
void unos_history_fahrenheit(float fahrenheit, struct istorija memorija[], int *mesto_istorija_f) {
  if ( *mesto_istorija_f > 4){
    for ( (*mesto_istorija_f) = 1 ; (*mesto_istorija_f) < 5; (*mesto_istorija_f)++ ){
        memorija[*mesto_istorija_f-1].fahrenheit = memorija[*mesto_istorija_f].fahrenheit; }
        *mesto_istorija_f = 4;
        memorija[*mesto_istorija_f].fahrenheit = fahrenheit; }
  else {
    memorija[*mesto_istorija_f].fahrenheit = fahrenheit;
  }
}
void konvert_cf(int *mesto_istorija_f) {
  float celsius;
  float fahrenheit;
  printf("\nUnesite temperaturu u Celzijusima: ");
  scanf("%f", &celsius);
  fahrenheit=konverzija_f;
  unos_history_fahrenheit(fahrenheit,memorija,mesto_istorija_f);
  printf("Temperatura u Farenhaitima je: %f\n", fahrenheit);
}
void konvert_fc(int *mesto_istorija_c) {
  float celsius;
  float fahrenheit;
  printf("\nUnesite temperaturu u Farenhaitima: ");
  scanf("%f", &fahrenheit);
  celsius = konverzija_c;
  unos_history_celsius(celsius,memorija,mesto_istorija_c);
  printf("Temperatura u Celsiusima je: %f\n", celsius);
}
void tabela() {
  float celsius;
  float fahrenheit;
  printf("\nCelzijusi Farenhaiti\n");
  printf("--------------------");
  celsius = 0;
  while (celsius <= 100) {
    fahrenheit=konverzija_f;
    printf("\n%6.2f%11.2f", celsius, fahrenheit);
    celsius = celsius + 5; }
    printf("\n--------------------\n");
}
void konvert_again1(int *mesto_istorija_f) {
  char answer;
  printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd') {
  (*mesto_istorija_f)++;
  konvert_cf(mesto_istorija_f);
  printf("\nDa li zelite da konvertujete ponovo? [D/N]\n");
  }
}
void konvert_again2(int *mesto_istorija_c) {
  char answer;
  printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd') {
  (*mesto_istorija_c)++;
  konvert_fc(mesto_istorija_c);
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
void history_ispis (struct istorija memorija[], int *izbor2) {
  int j,mesto_istorija_f,mesto_istorija_c;
    switch(*izbor2) {
    case 1:
      for(j = 0; j < 5; j++) {
        printf("%d: %.2f\n",(j+1), memorija[j].fahrenheit);}
    break;
    case 2:
      for(j = 0; j < 5; j++) {
        printf("%.2f\n", memorija[j].celsius);}
    break;
    default:
      printf("\nPogresan unos\n");
    break;
  }
 }
int main() {
  int pogresni_unos = 0;
  int izbor, izbor2;
  int mesto_istorija_c = 0, mesto_istorija_f = 0;
  do {
    prikazi_menu(&izbor);
  switch (izbor) {
  case 1:
    konvert_cf(&mesto_istorija_f);
    konvert_again1(&mesto_istorija_f);
    pogresni_unos = 0;
  break;
  case 2:
    konvert_fc(&mesto_istorija_c);
    konvert_again2(&mesto_istorija_c);
    pogresni_unos = 0;
  break;
  case 3:
    tabela();
    pogresni_unos = 0;
  break;
  case 4:
    printf("\nIstorijat konvertovanja\n");
    printf("\n1.Iz Celzijusa u Farenhajte");
    printf("\n2.Iz Farenhajta u Celzijuse\n");
    scanf("%d",&izbor2);
    history_ispis (memorija,&izbor2);
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
      return 0;
   }	
  }
 }
  while (izbor != 5);
}
