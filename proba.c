/* Copyright [2016] <Pythonovci> */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct memory {
   char recenica[150];
   char vowels[5];
   int karakteri;
 };
struct memory history[5];
int k = 0;

void memorisi(char recenica[], int choice) {
  if (choice == 1) {
    if (k > 4) {
      k = 1;
      for ( k; k < 5; k++ ) {
        strcpy( history[k - 1].recenica, history[k].recenica );
      }
    k = 4;
    strcpy( history[k].recenica, recenica );
    }
  }
  if (choice == 1) {
  strcpy( history[k].recenica, recenica );
  }
}

void memorisi_samoglasnike(char vowels[], int choice) {
  int j;
  if (choice == 1) {
    if (k > 4) {
      k = 1;
      for ( k; k < 5; k++ ) {
        for ( j = 0; j < 5; j++ ) {
        history[k - 1].vowels[j] = history[k].vowels[j];
        }
      }
    k = 4;
    for ( j = 0; j < 5; j++ ) {
      history[k].vowels[j] = vowels[j];
    }
    }
  }
  if (choice == 1) {
    for ( j = 0; j < 5; j++ ) {
      history[k].vowels[j] = vowels[j];
    }
  }
}

void istorija() {
  int j;
  int k;
  for ( k = 0; k < 5; k++ ) {
    printf("Broj karaktera u recenici %d je: %d\n\n", k + 1, history[k].karakteri);
    printf("Recenica %d glasi: %s\n", k + 1, history[k].recenica);
    printf("Broj samoglasnika u recenici %d je:\n\n", k + 1);
    for ( j = 0; j < 5; j++ ) {
      if ( j == 0 ) {
        printf("a: %d, ", history[k].vowels[j]); }
      if ( j == 1 ) {
        printf("e: %d, ", history[k].vowels[j]); }
      if ( j == 2 ) {
        printf("i: %d, ", history[k].vowels[j]); }
      if ( j == 3 ) {
        printf("o: %d, ", history[k].vowels[j]); }
      if ( j == 4 ) {
        printf("u: %d\n\n\n", history[k].vowels[j]); }
    }
  }
}

void istorija_posebno(int broj2) {
  int j;
  int k;
  k = broj2;
  printf("Broj karaktera u recenici %d je: %d\n\n", k, history[k].karakteri);
  printf("Recenica broj %d glasi: %s\n", k, history[k-1].recenica);
  printf("Broj samoglasnika u recenici %d je:\n\n", k);
  for ( j = 0; j < 5; j++ ) {
    if ( j == 0 ) {
      printf("a: %d, ", history[k-1].vowels[j]); }
    else if ( j == 1 ) {
      printf("e: %d, ", history[k-1].vowels[j]); }
    else if ( j == 2 ) {
      printf("i: %d, ", history[k-1].vowels[j]); }
    else if ( j == 3 ) {
      printf("o: %d, ", history[k-1].vowels[j]); }
    else {
      printf("u: %d\n\n\n", history[k-1].vowels[j]); }
  }
}

void print_recenica() {
 puts(history[k-1].recenica);
}

void print_samoglasnici(char vowels[]) {
 int k;
 for ( k = 0; k < 5; k++ ) {
   if ( k == 0 ) {
   printf("a: %d, ", vowels[k]); }
   if ( k == 1 ) {
   printf("e: %d, ", vowels[k]); }
   if ( k == 2 ) {
   printf("i: %d, ", vowels[k]); }
   if ( k == 3 ) {
   printf("o: %d, ", vowels[k]); }
   if ( k == 4 ) {
   printf("u: %d\n\n\n", vowels[k]); }
 }
}

void print_karakteri(int n) {
  printf("Recenica ima %d karaktera.\n\n", n);
}

void memorisi_karaktere(int karakteri, int choice, int n) {
  if (choice == 1) {
    if (k > 4) {
      k = 1;
      for ( k; k < 5; k++ ) {
        history[k - 1].karakteri = history[k].karakteri;
      }
    k = 4;
    history[k].karakteri = karakteri;
    }
  }
  if (choice == 1) {
    karakteri = n;
    history[k].karakteri = karakteri;
  }
}

void reset_samoglasnika(char vowels[]) {
  vowels[0] = 0;
  vowels[1] = 0;
  vowels[2] = 0;
  vowels[3] = 0;
  vowels[4] = 0;
}

void broj_samoglasnika(char vowels[], int n, char recenica[]) {
int k;
  for (k = 0; k < n; k++) {
    switch(recenica[k]) {
      case 'a':
      case 'A':
          vowels[0]++;
          break;
      case 'e':
      case 'E':
          vowels[1]++;
          break;
      case 'i':
      case 'I':
          vowels[2]++;
          break;
      case 'o':
      case 'O':
          vowels[3]++;
          break;
      case 'u':
      case 'U':
          vowels[4]++;
          break;
    }
  }
}

void unesi(char **recenica, int *n) {
  *recenica = (char*)malloc(150 * sizeof(**recenica));
  size_t bufsize = **recenica;
  getline(recenica, &bufsize, stdin);
  strtok(*recenica, "\n");
  *n = strlen(*recenica);
  *recenica = (void*)realloc(*recenica, (size_t) *n);
  if (recenica == NULL) {
    printf("Error! Memory not allocated.");
    exit(0);
  }
}

int main_menu(int *choice) {
  printf("\nMain menu\n");
  printf("1 - Napisi recenicu.\n");
  printf("2 - Prikazi poslednju unetu recenicu.\n");
  printf("3 - Prikazi broj samoglasnika poslednje unete recenice.\n");
  printf("4 - Prikazi broj karaktera poslednje unete recenice.\n");
  printf("5 - Prikazi istoriju.\n");
  printf("6 - Save.\n");
  printf("7 - Load.\n");
  printf("8 - Exit.\n\n");
  scanf("%d", &*choice);
  return *choice;
}

int izbor(int *broj) {
  scanf("%d", &*broj);
  return *broj;
}

int izbor2(int *broj2) {
  scanf("%d", &*broj2);
  return *broj2;
}

void save(FILE *fp) {
  int i, k;
  fp = fopen ("Samoglasnici.dat", "w");

  if (fp == NULL) {
    printf("Error while creating file.\n");
  }
  for ( i = 0; i < 5; i++ ) {
    fprintf(fp, "%d\n", history[i].karakteri);
    fprintf(fp, "%s\n", history[i].recenica);
    for ( k = 0; k < 5; k++ ) {
        fprintf(fp,"%d", history[i].vowels[k]); }
    }
  fclose(fp);
}

void load(FILE *fp, char vowels[]) {
  int i, k;
  fp = fopen ("Samoglasnici.dat", "r");

  if (fp == NULL) {
    printf("Error while creating file.\n");
  }
  for ( i = 0; i < 5; i++ ) {
    fscanf(fp,"%d\n\n", &history[i].karakteri);
    fgets(history[i].recenica, sizeof(history[i].recenica), fp);
    for ( k = 0; k < 5; k++ ) {
      if ( k == 0 ) {
        fscanf(fp,"a: %d ", history[i].vowels[k]); }
      else if ( k == 1 ) {
        fscanf(fp,"e: %d ", history[i].vowels[k]); }
      else if ( k == 2 ) {
        fscanf(fp,"i: %d ", history[i].vowels[k]); }
      else if ( k == 3 ) {
        fscanf(fp,"o: %d ", history[i].vowels[k]); }
      else {
        fscanf(fp,"u: %d\n\n\n", history[i].vowels[k]); }
    }
  }
  fclose(fp);
}

int main () {
  FILE *fp;
  char *recenica;
  char vowels[5];
  int karakteri;
  char unwantedchar[40];
  unwantedchar[0] = 0;
  int n;
  int choice;
  int broj;
  int broj2;
  char answer;

    while (choice != 8) {
      main_menu(&choice);
      fgets(unwantedchar, 40, stdin);
      if (isalpha(unwantedchar[0]) == 0) {
        switch (choice) {
          do {
            fgets(unwantedchar, 40, stdin);
            if (isalpha(unwantedchar[0]) == 0) {
          case 1:
            reset_samoglasnika(vowels);
            printf("\nNapisi recenicu.\n\n");
            unesi(&recenica, &n);
            memorisi_karaktere(karakteri, choice, n);
            broj_samoglasnika(vowels, n, recenica);
            memorisi(recenica, choice);
            memorisi_samoglasnike(vowels, choice);
            free(recenica);
            k++; }
            printf("Da li zelite da unesete jos jednu recenicu?\n"
                   "[D]\n[N]\n");
          } while (scanf("%c", &answer) == 1 && answer == 'D' || answer == 'd');
          break;

          case 2:
            printf("Vasa recenica je:\n");
            print_recenica();
          break;

          case 3:
            print_samoglasnici(vowels);
          break;

          case 4:
            print_karakteri(n);
          break;

          case 5:
            do {
              printf("1 - Celokupna istorja.\n");
              printf("2 - Recenice posebno.\n");
              printf("3 - Exit.\n\n");
              izbor(&broj);
              fgets(unwantedchar, 40, stdin);
              if (isalpha(unwantedchar[0]) == 0) {
                switch (broj) {
                  case 1:
                    istorija();
                  break;

                  case 2:
                    do {
                      printf("1 - Recenica broj 1.\n");
                      printf("2 - Recenica broj 2.\n");
                      printf("3 - Recenica broj 3.\n");
                      printf("4 - Recenica broj 4.\n");
                      printf("5 - Recenica broj 5.\n");
                      printf("6 - Exit.\n\n");
                      izbor2(&broj2);
                      fgets(unwantedchar, 40, stdin);
                      if (isalpha(unwantedchar[0]) == 0) {
                        switch (broj2) {
                          case 1:
                            istorija_posebno(broj2);
                          break;

                          case 2:
                            istorija_posebno(broj2);
                          break;

                          case 3:
                            istorija_posebno(broj2);
                          break;

                          case 4:
                            istorija_posebno(broj2);
                          break;

                          case 5:
                            istorija_posebno(broj2);
                          break;

                          case 6:
                          break;

                          default:
                            printf("Pogresan unos.\n");
                            printf("Pokusaj ponovo.\n\n");
                        }
                     }
                  } while (broj2 != 6);
                    break;

                 case 3:

                 default:
                   printf("Pogresan unos.\n");
                   printf("Pokusaj ponovo.\n\n");
               }
             }
           } while (broj != 3);
             break;
                 case 6:
                 save(fp);
                 break;

                 case 7:
                 load(fp, vowels);
                 break;

                 case 8:
                 printf("Hvala na koriscenju programa!\n\n");
                 return 0;

                 default:
                   printf("Pogresan unos.\n");
                   printf("Pokusaj ponovo.\n\n");
      }
    }
  }
}
