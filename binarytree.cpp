#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

 int randomBroj(){
   int r = (rand()%1000000)+0;
  return r;
}
void srednjeVreme(clock_t start){
  start = start/1000;
}

void popunjavanjeNizaA( int *A) {
  for (int i = 0; i < 10000; i++){
    A[i] = randomBroj();
  }
}

int poredjenjeA(int A[], int r) {
  for (int i = 0; i < 10000; i++) {
    if (A[i] == r){
      cout << "Postoji" << r << endl;
    }}
  clock_t start;
  start = clock();
  start += start;
  return start;
}

/*int poredjenjeB(int *B, int r) {
    if (B[i] == r) {
      cout << "Postoji" << r << endl;
  }
  clock_t start;
  start = clock();
  cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
}*/

void sortiranje( int *A,  int *B){
   int temp;
  for (int i = 0; i < 10000; i++) {
    B[i] = A[i];
  }
  sort(B, B+10000);
}
int main() {
 clock_t start;
 srand (time(NULL));
 int A[10000];
 int B[10000];
 int r = randomBroj();
// poredjenjeB(B, r, i);
popunjavanjeNizaA(A);
sortiranje(A,B);
for (int i = 0; i < 1000; i++) {
poredjenjeA(A, r);
poredjenjeA(B, r);
}
cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
 /*for (int i = 0; i < 10000; i++){
   cout << "A:" << A[i] << " ";
}

for (int i = 0; i < 10000; i++){
  cout << "B:" << B[i] << " ";
}*/


}
