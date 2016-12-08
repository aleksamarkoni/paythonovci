/* Copyright 2016 <Pythonovci> */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define HISTORY_SIZE 5

int position = 0;

struct memory {
  int side;
  int rolls;
  int statistics[20];
} history[HISTORY_SIZE];

int choosing_dice(int *dice_sides) {
  int dice_choice;
  printf("-------Dice-------\n");
  printf("1) 4-sides\n");
  printf("2) 6-sides \n");
  printf("3) 8-sides\n");
  printf("4) 10-sides\n");
  printf("5) 12-sides\n");
  printf("6) 20-sides\n");
  printf("7) Go to Menu\n");
  scanf("%d", &dice_choice);
  if (dice_choice > 7 || dice_choice < 1) {
    printf("\nInvalid choice!\nChoose again\n\n");
    return choosing_dice(dice_sides);
  }
  if (dice_choice == 7) {
    return main();
  }
  else {
  switch (dice_choice) {
    case 1:
      printf("\nYOU SELECTED 4-SIDED DICE\n\n");
      *dice_sides = 4;
      break;
    case 2:
      printf("\nYOU SELECTED 6-SIDED DICE\n\n");
      *dice_sides = 6;
      break;
    case 3:
      printf("\nYOU SELECTED 8-SIDED DICE\n\n");
      *dice_sides = 8;
      break;
    case 4:
      printf("\nYOU SELECTED 10-SIDED DICE\n\n");
      *dice_sides = 10;
      break;
    case 5:
      printf("\nYOU SELECTED 12-SIDED DICE\n\n");
      *dice_sides = 12;
      break;
    case 6:
      printf("\nYOU SELECTED 20-SIDED DICE\n\n");
      *dice_sides = 20;
      break;
      }
    return *dice_sides;
    }
  }

void printing_table(int dice_sides, int *x) {
  int i;
  for ( i = 0; i < dice_sides; i++ ) {
  printf("%d: %d\n", (i + 1), x[i]);
    }
  printf("\n");
  }

int unos_history_dice(int *x, struct memory history[], int dice_sides,
   int number_of_dice, int dice_roll) {
  int statistics[20];
  int i = 0;
  if (position > 4) {
    for (position = 1; position < HISTORY_SIZE; position++ ) {
      history[position-1].side = history[position].side;
      history[position-1].rolls = history[position].rolls;
    }
    for(i = 0; i < dice_sides; i++) {
      for ((position) = 1; (position) < HISTORY_SIZE; (position)++ ) {
      history[position-1].statistics[i] = history[position].statistics[i];
      }
    }
    i = 0;
    position = 4;
    history[position].side = dice_sides;
    history[position].rolls = (dice_roll * number_of_dice);
    for(i = 0; i < dice_sides; i++) {
      history[position].statistics[i] = x[i];
    }
  }
  else {
  history[position].side = dice_sides;
  history[position].rolls = (dice_roll * number_of_dice);
  for(i = 0; i < dice_sides; i++) {
    history[position].statistics[i] = x[i];
    }
  }
  return position;
}

void rolling_dice(int *x, int dice_sides) {
  int number_of_dice, dice_roll;
  int random_number = 0;
  time_t t;
  int i, j;
  printf("\nHow many dice? ");
  scanf("%d", &number_of_dice);
  if ( number_of_dice > 10 ) {
    printf("\nYou entered invalid number of dice!\n");
    return rolling_dice(x, dice_sides);
  }
  else {
  printf("How many rolls? ");
  scanf("%d", &dice_roll);
  srand((unsigned) time(&t));
  for ( i = 0; i < number_of_dice; i++ ) {
    for ( j = 0; j < dice_roll; j++ ) {
      random_number = rand()%dice_sides+1;
      x[random_number-1]++;
      }
    }
  unos_history_dice(x, history, dice_sides, number_of_dice, dice_roll);
  printing_table(dice_sides, x);
  }
}

void reseting_dice(int *dice_sides, int *x) {
  int i;
  for (i = 0; i < *dice_sides; i++) {
    x[i] = 0;
  }
}

int menu(int *choice, int *dice_sides) {
  printf("\n-----------Menu-----------\n\n");
  printf("You are using %d-sided dice\n\n", *dice_sides);
  printf("1) Choose diffrent dice\n");
  printf("2) Roll dice, update new table \n");
  printf("3) Roll dice, update old table\n");
  printf("4) History\n");
  printf("5) Exit\n");
  scanf("%d", &*choice);
  return *choice;
  }

void rolling_again (int *x, int dice_sides) {
  char answer;
  printf("\nDo you want to roll dice again ? [Y/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
  reseting_dice(&dice_sides, x);
  position++;
  rolling_dice(x, dice_sides);
  reseting_dice(&dice_sides, x);
  printf("\nDo you want to roll dice again? [Y/N]\n");
  }
  position++;
}

void rolling_again2 (int *x, int dice_sides) {
  char answer;
  printf("\nDo you want to roll dice again ? [Y/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
  rolling_dice(x, dice_sides);
  printf("\nDo you want to roll dice again? [Y/N]\n");
  }
}

void error_no_table(int *x, int dice_sides) {
  int i;
  for(i = 0; i < dice_sides; i++) {
    if (x[i] > 20) {
      printf("\nError: No table to update!\n");
      reseting_dice(&dice_sides, x);
    }
    if (x[i] < 0) {
      printf("\nError: Current table is empty!\nUpdating new table!\n");
      reseting_dice(&dice_sides, x);
    }
  }
}

void history_ispis(struct memory history[], int dice_sides,int *x) {
  int i, j;
  printf("\nHistory:\n\n");
  for (j = 0; j < HISTORY_SIZE; j++) {
    if ( history[j].side > 0 ) {
    printf("Dice sides: %d\n", history[j].side);
    printf("Number of rolls: %d\n", history[j].rolls);
    for(i = 0; i < history[j].side; i++) {
    printf("%d: %d\n", (i + 1), history[j].statistics[i]);
   }
  }
  else {
    printf("History is empty");
  }
  printf("\n");
  }
}

int main() {
  FILE *fp;
  int choice;
  int dice_sides = 6;
  int x[20];
  char unwantedCharacters[40];
  unwantedCharacters[0] = 0;
  time_t t;
  while (choice != 5) {
  menu(&choice, &dice_sides);
  fgets(unwantedCharacters, 40, stdin);
  if (isalpha(unwantedCharacters[0]) == 0)  {
  switch (choice) {
  case 1:
    printf("\nYou selected option 1\n\n");
    choosing_dice(&dice_sides);
    if ( position > 0) {
      position++;
    }
    break;
  case 2:
    printf("\nYou selected option 2\n");
    reseting_dice(&dice_sides, x);
    printf("\nYou are rolling %d sided dice\n", dice_sides);
    rolling_dice(x, dice_sides);
    rolling_again(x, dice_sides);
    break;
  case 3:
    printf("\nYou selected option 3\n");
    error_no_table(x, dice_sides);
    printf("\nYou are rolling %d sided dice\n", dice_sides);
    rolling_dice(x, dice_sides);
    rolling_again2(x, dice_sides);
    break;
  case 4:
    printf("\nYou selected option 4\n\n");
    history_ispis(history, dice_sides, x);
    break;
  case 5:
    printf("\nThank you for using our program\n\n");
    return 0;
  default:
    printf("\nError wrong input!\nPlease try again\n");
    return main();
     }
   }
  else {
    printf("\nError wrong input!\nPlease try again\n");
  }
 }
}
