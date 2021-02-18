#include "examen.h"

#define _p_ -1
#define _q_ -2
#define _s_ -3
#define _t_ -4

#define NB_SYMBOLES 4
#define NB_FORMULES 5

// Exemple 27 (7.Sem.Cons/p2)
// {(p IMP s),((q IMP t), NEGATION p, NEGATION q} |/= (NEGATION s OU NEGATION t)

static int ensemble_de_formules[][3] = {{OU, 5, 6}, {IMP, _p_, _s_}, {IMP, _q_, _t_}, {NEGATION, _p_, VIDE}, {NEGATION, _q_, VIDE}, {NEGATION, _s_, VIDE}, {NEGATION, _t_, VIDE}};

void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _p_ : printf("p"); break;
  case _q_ : printf("q"); break;
  case _s_ : printf("s"); break;
  case _t_ : printf("t"); break;
  }
}
