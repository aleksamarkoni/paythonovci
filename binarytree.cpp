#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct node {
  int broj;
  node *levo;
  node *desno;
};

class Btree {
private:
  void ubaciBroj(int unosBr) {
    if(root != NULL) {
      ubaciBroj(unosBr, root);
    } else {
      root = new node;
      root->broj = unosBr;
      root->levo = NULL;
      root->desno = NULL;
    }
  }
  node *nadjiBroj(int unosBr) {
    return nadjiBroj(unosBr, root);
  }
  void unistiDrvo() {
    unistiDrvo(root);
  }

public:
  Btree() {
    root = NULL;
  }
  ~Btree() {
    unistiDrvo();
  }
  void ubaciBroj(int unosBr, node *parent) {
    if(unosBr < parent->broj) {
      if(parent->levo != NULL) {
        ubaciBroj(unosBr, parent->levo);
      } else {
        parent->levo = new node;
        parent->levo->broj = unosBr;
        parent->levo->levo = NULL;
        parent->levo->desno = NULL;
      }
    }
      else if(unosBr >= parent->broj) {
        if(parent->desno != NULL) {
          ubaciBroj(unosBr, parent->desno);
        } else {
          parent->desno = new node;
          parent->desno->broj = unosBr;
          parent->desno->levo = NULL;
          parent->desno->desno = NULL;
        }
      }
  }


  node *nadjiBroj(int unosBr, node *parent) {
    if(parent != NULL) {
      if(unosBr == parent->broj) {
        return parent;
      }
      if(unosBr < parent->broj) {
        return nadjiBroj(unosBr, parent->levo);
      } else {
        return nadjiBroj(unosBr, parent->desno);
      }
    }
    else return NULL;
  }


  void unistiDrvo(node *parent) {
    if(parent!=NULL) {
      unistiDrvo(parent->levo);
      unistiDrvo(parent->desno);
      delete parent;
    }
  }

  node *root;
  Btree &operator=(Btree &BinarnoDrvo);
};

ostream &operator<<(ostream& out, Btree &BinarnoDrvo) {
  out << BinarnoDrvo << endl;
}

Btree &operator=(Btree &BinarnoDrvo) {
  BinarnoDrvo = r;
  return BinarnoDrvo;
}

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

Btree popunjavanjeBtree(Btree &BinarnoDrvo, int r) {
  for (int i = 0; i < 10000; i++) {
    ubaciBroj(r, &parent);
    return BinarnoDrvo;
  }
}

void stampaj(Btree &BinarnoDrvo) {
  if (p != NULL) {
    //za domaci, nacrtati kojim redosledom se stampaju ovi elementi ako printf stoji ovde

    stampaj(p->left);
    // ako printf stoji ovde

    stampaj(p->right);
    printf("%d, ", p->broj);
    //ako printf stoji ovde
  }
}

int main() {
 Btree BinarnoDrvo;
 int unosBr = 0;
 double srVreme = 0;
 srand (time(NULL));
 int A[10000];
 int B[10000];
 int r = randomBroj();
 popunjavanjeNizaA(A);

sortiranje(A, B);
printObaNiza(srVreme, A, B, r);


}
