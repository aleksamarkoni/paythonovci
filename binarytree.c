#include <stdio.h>
#include <stdlib.h>

struct Node {
  int broj;
  struct Node *left;
  struct Node *right;
} *parent = NULL;

void ubaciBroj(struct Node **node, int broj) {
  //printf("Ubacujem broj");
  if ((*node) == NULL) {
    (*node) = (struct Node*) malloc( sizeof( struct Node ) );
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->broj = broj;
  } else if (broj > (*node)->broj) {
    ubaciBroj(&(*node)->right, broj);
  } else if (broj < (*node)->broj) {
    ubaciBroj(&(*node)->left, broj);
  } else {
    //no - op
    return;
  }
}

void pronadjiElement(struct Node **node, int broj) {
  // za domaci
}

void stampaj(struct Node *p) {
  if (p != NULL) {
    //za domaci, nacrtati kojim redosledom se stampaju ovi elementi ako printf stoji ovde
    stampaj(p->left);
    // ako printf stoji ovde
    printf("%d, ", p->broj);
    stampaj(p->right);
    //ako printf stoji ovde
  }
}

int main() {
  ubaciBroj(&parent, 34);
  ubaciBroj(&parent, 37);
  ubaciBroj(&parent, 134);
  ubaciBroj(&parent, 23);
  ubaciBroj(&parent, 11);
  stampaj(parent);
  printf("\n");

}
