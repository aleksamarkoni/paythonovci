#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

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
    //printf("Ubacujem broj");
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
      //no - op
      return;
    }
  }
  //Node *nadjiBroj(int unosBr) {
  //  return nadjiBroj(unosBr, root);
  //}
  void unistiDrvo(struct Node *parent) {
    if(parent!=NULL) {
      unistiDrvo(parent->levo);
      unistiDrvo(parent->desno);
      delete parent;
    }
  }

  void stampaj(struct Node *parent) {
    if (parent != NULL) {
      //za domaci, nacrtati kojim redosledom se stampaju ovi elementi ako printf stoji ovde

      stampaj(parent->levo);
      // ako printf stoji ovde
      cout << parent->broj << endl;
      stampaj(parent->desno);

      //ako printf stoji ovde
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

  void stampaj() {
    stampaj(root);
  }
  //Btree &operator=(Btree &BinarnoDrvo);
};

//ostream &operator<<(ostream& out, Btree &BinarnoDrvo) {
//  out << BinarnoDrvo << endl;
//}

//Btree &operator=(Btree &BinarnoDrvo) {
//  BinarnoDrvo = r;
//  return BinarnoDrvo;
//}

int randomBroj(){
   int r = (rand()%1000000)+0;
  return r;
}
void srednjeVreme(double *vreme){
  *vreme = *vreme/(double)1000;
}

void popunjavanjeNizaA( int *A) {
  for (int i = 0; i < 10000; i++){
    A[i] = randomBroj();
  }
}

double poredjenje(int A[], int r) {
  double vreme;
  clock_t start;
  start = clock();
  for (int i = 0; i < 10000; i++) {
    if (A[i] == r){
      cout << "Postoji" << r << endl;
    }}
    vreme = clock() - start / (double)(CLOCKS_PER_SEC / 1000);
    return vreme;
}

void printObaNiza(double srVreme, int *A, int *B, int r) {
  for (int i = 0; i < 1000; i++) {
  srVreme += poredjenje(A, r);
  }
  cout << "Vreme za niz A je: " << srVreme/1000 << "ms" << endl;
  srVreme = 0;
  for (int i = 0; i < 1000; i++) {
  srVreme += poredjenje(B, r);
  }
  cout << "Vreme za niz B je: " << srVreme/1000 << "ms" << endl;
}

int sortiranje( int *A,  int *B){
   int temp;
  for (int i = 0; i < 10000; i++) {
    B[i] = A[i];
  }
  sort(B, B+10000);
  return *B;
}

/*Btree popunjavanjeBtree(Btree &BinarnoDrvo, int r) {
  for (int i = 0; i < 10000; i++) {
    BinarnoDrvo.ubaciBroj(r, &parent);
    return BinarnoDrvo;
  }
}*/

int main() {
 Btree bd;
 //double srVreme = 0;
 srand (time(NULL));
 //int A[10000];
 //int B[10000];
 //int r = randomBroj();
 //popunjavanjeNizaA(A);
 //sortiranje(A, B);
 //printObaNiza(srVreme, A, B, r);
 for (int i = 0; i < 100; i++) {
    bd.dodajBroj(randomBroj());
 }
 //bd.dodajBroj(25);
 //bd.dodajBroj(37);
 bd.stampaj();

}
