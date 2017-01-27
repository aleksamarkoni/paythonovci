#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Node {
  int broj;
  struct Node *levo;
  struct Node *desno;
};

class Btree {
private:
  struct Node *root;
  void ubaciBroj(struct Node **node, int broj) {
    if ((*node) == NULL) {
      (*node) = (struct Node*) malloc( sizeof( struct Node ) );
      (*node)->levo = NULL;
      (*node)->desno = NULL;
      (*node)->broj = broj;
    } else if (broj > (*node)->broj) {
      ubaciBroj(&(*node)->desno, broj);
    } else if (broj < (*node)->broj) {
      ubaciBroj(&(*node)->levo, broj);
    } else {
      return;
    }
  }

  double nadjiBroj(struct Node **node, int broj) {
    double vreme = 0;
    clock_t begin = clock();
    if ((*node) == NULL) {
      clock_t end = clock();
      vreme = double(end - begin) / (CLOCKS_PER_SEC / 1000);
      return vreme;
    }
    else {
      if ((*node)->broj == broj) {
        clock_t end = clock();
        vreme = double(end - begin) / (CLOCKS_PER_SEC / 1000);
        return vreme;
      }
      else if (broj > (*node)->broj) {
        nadjiBroj(&(*node)->desno, broj);
      }
      else if (broj < (*node)->broj){
        nadjiBroj(&(*node)->levo, broj);
    }
    else {
      clock_t end = clock();
      vreme = double(end - begin) / (CLOCKS_PER_SEC / 1000);
      return vreme;
    }
  }
}

  void unistiDrvo(struct Node *parent) {
    if(parent!=NULL) {
      unistiDrvo(parent->levo);
      unistiDrvo(parent->desno);
      delete parent;
    }
  }

  void stampaj(struct Node *parent) {
    if (parent != NULL) {
      stampaj(parent->levo);
      cout << parent->broj << endl;
      stampaj(parent->desno);
    }
  }
public:
  Btree() {
    root = NULL;
  }
  ~Btree() {
    unistiDrvo(root);
  }
  void dodajBroj(int broj) {
    ubaciBroj(&root, broj);
  }
  double nadjiBroj(int broj) {
    nadjiBroj(&root, broj);
  }
  void stampaj() {
    stampaj(root);
  }
};

int randomBroj(){
   int r = (rand()%1000000)+0;
  return r;
}

void popunjavanjeNizaA( int *A) {
  for (int i = 0; i < 10000; i++){
    A[i] = randomBroj();
  }
}

double poredjenje(int A[], int r) {
  double vreme;
  clock_t begin = clock();
  for (int i = 0; i < 10000; i++) {
    if (A[i] == r){
      cout << "Postoji" << r << endl;
    }
  }
  clock_t end = clock();
  vreme = double(end - begin) / (CLOCKS_PER_SEC / 1000);
  return vreme;
}

void printObaNiza(double srVreme, int *A, int *B, int r) {
  for (int i = 0; i < 1000; i++) {
    srVreme += poredjenje(A, r);
  }
  cout << fixed << "Linearno srednje vreme za niz A je: " << setprecision(4) << srVreme/1000 << "ms" << endl;
  srVreme = 0;
  for (int i = 0; i < 1000; i++) {
    srVreme += poredjenje(B, r);
  }
  cout << fixed << "Linearno srednje vreme za niz B je: " << setprecision(4) << srVreme/1000 << "ms" << endl;
}

int sortiranje( int *A,  int *B){
   int temp;
  for (int i = 0; i < 10000; i++) {
    B[i] = A[i];
  }
  sort(B, B+10000);
  return *B;
}

double Binary_SearchNizB(int *B) {
  int left = 0, right = 10000, mid;
  int r = randomBroj();
  double vreme;
  clock_t begin = clock();
  while (left <= right) {
	  mid = (int) ((left + right) / 2);
	  if (r == B[mid]) {
      clock_t end = clock();
      vreme = double(end - begin) / (CLOCKS_PER_SEC / 1000);
		  return vreme;
	  }
    else if (r > B[mid])
	    left = mid + 1;
    else
	    right = mid - 1;
    }
  clock_t end = clock();
  vreme = double(end - begin) / (CLOCKS_PER_SEC / 1000);
  return vreme;
}

void binarnoSrednjeVreme(double srVreme, int *B, int *r, Btree& bd){
  srVreme = 0;
  for (int i = 0; i < 1000; i++) {
    srVreme += Binary_SearchNizB(B);
  }
  cout << fixed << "Binarno srednje vreme za niz B je: " << setprecision(4) << srVreme/1000 << "ms" << endl;
  srVreme = 0;
  for (int i = 0; i < 1000; i++) {
    srVreme += bd.nadjiBroj(*r);
  }
  cout << fixed << "Binarno srednje vreme za binarno drvo je: " << setprecision(4) << srVreme/1000 << "ms" << endl;
}

int main() {
 Btree bd;
 double srVreme = 0;
 srand (time(NULL));
 int A[10000];
 int B[10000];
 int r = randomBroj();
 popunjavanjeNizaA(A);
 sortiranje(A, B);
 printObaNiza(srVreme, A, B, r);
 for (int i = 0; i < 10000; i++) {
    bd.dodajBroj(randomBroj());
 }
 binarnoSrednjeVreme(srVreme, B, &r, bd);
}
