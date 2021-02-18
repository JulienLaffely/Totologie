#include "examen.h"


#define _A_ -1
#define _B_ -2
#define _C_ -3


#define NB_SYMBOLES 3
#define NB_FORMULES 3

// Exercice 14 (7.Sem.Cons/p10)
// {(A IMP B), (A IMP C)} |= (A IMP (B OU C))

static int ensemble_de_formules[][3] = {{IMP, _A_, 3}, {IMP, _A_, _B_}, {IMP, _A_, _C_}, {OU, _B_, _C_}};


void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _A_ : printf("A"); break;
  case _B_ : printf("B"); break;
  case _C_ : printf("C"); break;
  }
}

