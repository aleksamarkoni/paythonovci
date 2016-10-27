/*"Copyright [2016] <pesic>"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void unos_history_fahrenheit(float fahrenheit, struct istorija memorija[], int *k) {
  if ( *k > 4){
    for ( (*k) = 1 ; (*k) < 5; (*k)++ ){
        memorija[*k-1].fahrenheit = memorija[*k].fahrenheit; }
        *k = 4;
        memorija[*k].fahrenheit = fahrenheit; }
  else {
    memorija[*k].fahrenheit = fahrenheit;
  }
}
float konvert_cf(int *k) {
  float celsius;
  float fahrenheit;
  printf("\nUnesite temperaturu u Celzijusima: ");
  scanf("%f", &celsius);
  fahrenheit = (1.8 * celsius) + 32;
  unos_history_fahrenheit(fahrenheit,memorija,k);
  printf("Temperatura u Farenhaitima je: %f\n", fahrenheit);
  return (fahrenheit);
}
float konvert_fc(int *i) {
  float celsius;
  float fahrenheit;
  printf("\nUnesite temperaturu u Farenhaitima: ");
  scanf("%f", &fahrenheit);
  celsius = (5.0/9.0) * (fahrenheit-32);
  unos_history_celsius(celsius,memorija,i);
  printf("Temperatura u Celsiusima je: %f\n", celsius);
  return(celsius);
}
void tabela() {
  float celsius;
  float fahrenheit;
  printf("\nCelzijusi Farenhaiti\n");
  printf("--------------------");
  celsius = 0;
  while (celsius <= 100) {
    fahrenheit = (1.8 * celsius) + 32;
    printf("\n%6.2f%11.2f", celsius, fahrenheit);
    celsius = celsius + 5; }
    printf("\n--------------------\n");
}
void konvert_again1(int *k) {
  char answer;
  printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd') {
  (*k)++;
  konvert_cf(k);
  printf("\nDa li zelite da konvertujete ponovo? [D/N]\n");
  }
}
void konvert_again2(int *i) {
  char answer;
  printf("\nDa li zelite da konvertujete ponovo ? [D/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'D' || answer == 'd') {
  (*i)++;
  konvert_fc(i);

  printf("\nDa li zelite da konvertujete ponovo? [D/N]\n");
  }
}
int prikazi_menu(int *izbor) {
  printf("\nSta zelite da konvertujete?:");
  printf("\n****************************");
  printf("\n1. Iz Celzijusa u Farenhaite\n");
  printf("2. Iz Farenhaita u Celzijuse\n");
  printf("3. Tablica konvertovanja\n");
  printf("4. Istorijat konvertovanja\n");
  printf("5. Izlaz\n");
  printf("Unesite vas izbor: ");
  scanf("%d", &*izbor);
  return *izbor;
}
void history_ispis (struct istorija memorija[], int *izbor2) {
  int j,k,i;
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

  int izbor, izbor2;
  int i = 0, k = 0;
  while (izbor != 5) {
    prikazi_menu(&izbor);
  switch (izbor) {
  case 1:
    konvert_cf(&k);
    konvert_again1(&k);
  break;
  case 2:
    konvert_fc(&i);
    konvert_again2(&i);
  break;
  case 3:
    tabela();
  break;
  case 4:
    printf("\nIstorijat konvertovanja\n");
    printf("\n1.Iz Celzijusa u Farenhajte");
    printf("\n2.Iz Farenhajta u Celzijuse\n");
    scanf("%d",&izbor2);
    history_ispis (memorija,&izbor2);
  break;
  case 5:
    printf("Hvala na koristenju programa.\n");
  break;
  default:
    printf("Pogresan unos, pokusajte ponovo.\n");
  return 0;
  }
 }
}
