#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izracunaj(int *b) {
(*b)++;
return *b;
}

struct memorija {
int unos;
int brojac[100];
int iteracije[1000];
};
struct memorija istorija[10];

void unos(int *m, int *b, int *n, int k, int *i,
   int *niz, int *nizovi, struct memorija istorija[]) {
*m = *n;
int r = 0;
  while (*m !=1) {
  if (*m%2 == 0) {
     *m = *m/2;
     izracunaj(&*b);
  }
  else {
     *m = 3 * (*m) + 1;
     izracunaj(&*b);
  }
  nizovi[*i] = *b;
  istorija[*i].brojac[k] = *b;
  istorija[*i].iteracije[k] = *m;

  printf("\nUneti broj je %d = ", *n);
  printf("| Brojac: %d || Iteracija: %d |\n",  istorija[*i].brojac[k], istorija[*i].iteracije[k]);
    k++;
  }
  (*b) = 0;
  istorija[*i].unos = *n;
  }
int ispis(struct memorija istorija[], int *i, int *max) {
  int j, k = 0;
  int n = *max;

  while (n !=0) {
     for (j = 0; j < (*i); j++) {
      printf("\n Uneti broj je %d ", istorija[j].unos);
  }
    for (j = 0; j < (*i); j++) {
      printf("| Brojac: %2d || Iteracija: %2d |", istorija[j].brojac[k], istorija[j].iteracije[k]);
     }
       k++;
      n--;
     }
  }
  int maksi(int *i, int nizovi[]) {
  printf("Trenutni brojac = %d\n", nizovi[*i]);
  }

int maksimum(int nizovi[], int*i, int *max) {
     int k;
  *max = nizovi[0];
  *max = nizovi[*i];
  for (k = 0; k < (nizovi[*i]); k++) {
  if (nizovi[k] > *max)
  *max = nizovi[k];
}
  printf("Maksimalni brojac = %d\n", *max);
}
int main_menu(int *izbor) {
  printf("\nMain:\n");
  printf("1. Unesi broj:\n");
  printf("2. Ispisi istoriju:\n");
  printf("3. Exit.\n");
  scanf("%d", &*izbor);
}
int unos_br(int *n) {
  scanf("%d", &*n);
  printf("Uneli ste broj: %d\n", *n);
}

int main() {
int m, n, i = 0, b, max, k = 0, izbor, status;
char r[40];
int niz = 0;
int nizovi[1000];
int a[1000];

while (izbor != 3) {
main_menu(&izbor);

  fgets(r, 40, stdin);
  if (isalpha(r[0]) == 0) {
switch (izbor) {
  do {
  case 1:
  unos_br(&n);
  unos(&m, &b, &n, k, &i, &niz, nizovi, istorija);

  printf("Da li zelite da uneste drugi broj:\n [1 - Da]\n [0 - Ne]\n ");
  scanf("%d", &status);
  maksi(&i, nizovi);
  maksimum(nizovi, &i, &max);

  i++;
  } while (status == 1);
  break;
  case 2:

  ispis(istorija, &i, &max);

  break;
  case 3:
  break;
}
}
}
}
