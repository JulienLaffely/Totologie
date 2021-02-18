#include "examen.h"

#define _mo_ -1
#define _jv_ -2
#define _vv_ -3
#define _vp_ -4
#define _fa_ -5
#define _do_ -6


#define NB_SYMBOLES 6
#define NB_FORMULES 7

// Exercice 17 (7.Sem.Cons/p17)
// {(mo IMP 7), (8 IMP mo), (vv IMP fa), jv, (fa IMP do), (vp IMP fa) } |= do

static int ensemble_de_formules[][3] = {{FAIT, _do_, VIDE}, {IMP, _mo_, 7}, {IMP, 8, _mo_}, {IMP, _vv_, _fa_}, {FAIT, _jv_, VIDE}, {IMP, _fa_, _do_}, {IMP, _vp_, _fa_}, {IMP, _jv_, _vv_}, {NEGATION, _vp_, VIDE}};

void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _mo_ : printf("mo"); break;
  case _jv_ : printf("jv"); break;
  case _vv_ : printf("vv"); break;
  case _vp_ : printf("vp"); break;
  case _fa_ : printf("fa"); break;
  case _do_ : printf("do"); break;
  }
}
