#include "examen.h"

#define _A_ -1
#define _B_ -2
#define _C_ -3

#define NB_SYMBOLES 3
#define NB_FORMULES 4

// {((A OU B) IMP C), NEGATION C, A} |= (NEGATION A ET NEGATION C))

static int ensemble_de_formules[][3] = {{ET, 4, 5}, {IMP, 6, _C_}, {NEGATION, _C_, VIDE}, {FAIT, _A_, VIDE}, {NEGATION, _A_, VIDE}, {NEGATION, _C_, VIDE}, {OU, _A_, _B_}};

void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _A_ : printf("A"); break;
  case _B_ : printf("B"); break;
  case _C_ : printf("C"); break;
  }
}
