#include "examen.h"


#define _A_ -1
#define _B_ -2
#define _C_ -3


#define NB_SYMBOLES 3
#define NB_FORMULES 3

// Exercice 14 (7.Sem.Cons/p10)
// {(A IMP NEGATION C), (B IMP NEGATION C)} |/= (C IMP (A OU B))

static int ensemble_de_formules[][3] = {{IMP, _C_, 3}, {IMP, _A_, 4}, {IMP, _B_, 5}, {OU, _A_, _B_}, {NEGATION, _C_, VIDE}, {NEGATION, _C_, VIDE}};


void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _A_ : printf("A"); break;
  case _B_ : printf("B"); break;
  case _C_ : printf("C"); break;
  }
}
