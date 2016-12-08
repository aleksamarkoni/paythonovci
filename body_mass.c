#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct istorija {
  double tezina;
  double visina;
  double Body_mass;
};
struct istorija memorija[20];

void history_unos (int choice, struct istorija memorija[], double *user_weight, double *user_height,
   double *BMI, int *k) {
     int i;
     if (choice == 1) {
       FILE *fp;

      fp = fopen("results.dat", "w");
      if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }
       memorija[*k].tezina = *user_weight;
       memorija[*k].visina = *user_height;
       memorija[*k].Body_mass = *BMI;
      for ( i = 0; i < *k; i++) {
       fprintf(fp, "%lf", memorija[i].tezina);
       fprintf(fp, "%lf", memorija[i].visina);
       fprintf(fp, "%lf", memorija[i].Body_mass);
      }
       fclose(fp);
 }
}
void history_ispis (int choice, struct istorija memorija[], int *k) {
  int i, j, x;
  if (choice == 3) {
    FILE *fp;

     /* open the file */
     fp = fopen("results.dat", "r");
     if (fp == NULL) {
        printf("I couldn't open results.dat for reading.\n");
        exit(0);
     }

       fscanf(fp, "%lf",&memorija[*k].tezina);
       fscanf(fp, "%lf",&memorija[*k].visina);
       fscanf(fp, "%lf",&memorija[*k].Body_mass);
       for (i = 0; i < *k; i++) {
       printf("%d:  tezina = %.2lf\n",(i+1), memorija[i].tezina);
       printf("   visina = %.2lf\n", memorija[i].visina);
       printf("   BMI = %.2lf\n\n", memorija[i].Body_mass);
     }
     /* close the file */
     fclose(fp);
   }
 }

int meni(int *choice) {
   printf("\n\t 1. BMI za jednu osobu");
   printf("\n\t 2. BMI od 40kg do 200kg");
   printf("\n\t 3. Istorija");
   printf("\n\t 4. Exit");
   printf("\n\n\t Izaberite sta zelite:\n ");
   scanf("%d", &*choice);
   return *choice;
}
kilogrami() {
  double user_weight = 0;
  double user_height = 0;
  double BMI = 0;
  for (user_weight = 40; user_weight <= 200; (user_weight = user_weight + 10)) {
    for (user_height = 1.50; user_height <= 2.20; (user_height = user_height + 0.10)) {
      BMI = user_weight / ((user_height)*(user_height));
      printf("%.2lf\t%.2lf\tBMI = %.2lf\t\n", user_weight, user_height, BMI);
    }
  }
}
void prvi_srbin(double *user_weight, double *user_height,
  double *BMI) {
  printf("\tunesi tezinu tela i visinu tela\n");
  scanf("%lf %lf", &*user_weight, &*user_height);
  *BMI = *user_weight / ((*user_height)*(*user_height));
  if (*BMI < 18.5) {
  printf("under  ");
  printf("%.2lf", *BMI); }
   else if (*BMI > 18.5 && *BMI <= 25.0) {
  printf("normal  ");
  printf("BMI = %.2lf", *BMI); }
   else if (*BMI > 25.0 && *BMI <= 30.0) {
  printf("over  ");
  printf("BMI = %.2lf", *BMI); }
   else if (*BMI > 30.0) {
  printf("obese  ");
  printf("BMI = %.2lf", *BMI); }
}

int main() {
  double user_weight;
  double user_height;
  double BMI;
  int choice;
  int k = 0;
  char answer;
  while(choice!=4) {
    meni(&choice);
    switch(choice)
    {
    do {
    case 1:
      prvi_srbin (&user_weight, &user_height, &BMI);
      history_unos(choice, memorija, &user_weight, &user_height,
         &BMI, &k);
         k++;
      printf("\nDa li zelite da unesete informacije opet? [Y/N]\n");
    } while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y');
      break;
    case 2:
      kilogrami ();
      break;
    case 3:
      history_ispis (choice, memorija, &k);
      break;
    case 4:
      printf("\n\nExit\n");
      return 0;
    default:
      printf("\n\nINVALID SELECTION...Please try again\n");
    }
  }
}
