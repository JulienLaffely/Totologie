#include "examen.h"

#define _pl_ -1
#define _mo_ -2
#define _na_ -3
#define _ti_ -4

#define NB_SYMBOLES 4
#define NB_FORMULES 5

// Exercice 16 (7.Sem.Cons/p17)
// {(pl IMP mo), (na IMP mo), ((NEGATION pl ET ti)  IMP na), ti} |= mo

static int ensemble_de_formules[][3] = {{FAIT, _mo_, VIDE}, {IMP, _pl_, _mo_}, {IMP, _na_, _mo_}, {IMP, 5, _na_}, {FAIT, _ti_, VIDE}, {ET, 6, _ti_}, {NEGATION, _pl_, VIDE}};

void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _pl_ : printf("pl"); break;
  case _na_ : printf("na"); break;
  case _ti_ : printf("ti"); break;
  case _mo_ : printf("mo"); break;
  }
}
