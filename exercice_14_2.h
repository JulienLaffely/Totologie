#include "examen.h"

#define _A_ -1
#define _B_ -2
#define _C_ -3
#define _D_ -4
#define _E_ -5
#define _F_ -6
#define _G_ -7

#define NB_SYMBOLES 7
#define NB_FORMULES 5

// Exercice 14 (7.Sem.Cons/p10)
// {(A IMP (B ET C)), ((NEGATION A) IMP G),  (B IMP D), (C IMP E)} |= ((D ET E) OU G)

static int ensemble_de_formules[][3] = {{OU, 6, _G_}, {IMP, _A_, 7}, {IMP, 5, _G_}, {IMP, _B_, _D_}, {IMP, _C_, _E_}, {NEGATION, _A_, VIDE}, {ET, _D_, _E_}, {ET, _B_, _C_}};


void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _A_ : printf("A"); break;
  case _B_ : printf("B"); break;
  case _C_ : printf("C"); break;
  case _D_ : printf("D"); break;
  case _E_ : printf("E"); break;
  case _F_ : printf("F"); break;
  case _G_ : printf("G"); break;
  }
}
