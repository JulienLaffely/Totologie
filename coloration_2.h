#include "examen.h"

#define _r1_ -1
#define _r2_ -2
#define _r3_ -3
#define _r4_ -4

#define _b1_ -5
#define _b2_ -6
#define _b3_ -7
#define _b4_ -8

#define _j1_ -9
#define _j2_ -10
#define _j3_ -11
#define _j4_ -12

#define NB_SYMBOLES 12
#define NB_FORMULES 31

// Coloration 
// R u B u J u C u K u {r1, ~b2} |/= b4 

static int ensemble_de_formules[][3] =
  {{FAIT, _b4_, VIDE}, // 0:
   {FAIT, _r1_, VIDE}, // 1:
   {NEGATION, _b2_, VIDE}, // 2:
   {IMP, _r1_, 31}, // 3: R1
   {IMP, _r2_, 32}, // 4: R2
   {IMP, _r3_, 33}, // 5: R3
   {IMP, _r4_, 34}, // 6: R4
   {IMP, _b1_, 35}, // 7: B1
   {IMP, _b2_, 36}, // 8: B2
   {IMP, _b3_, 37}, // 9: B3
   {IMP, _b4_, 38}, // 10: B4
   {IMP, _j1_, 39}, // 11: J1
   {IMP, _j2_, 40}, // 12: J2
   {IMP, _j3_, 41}, // 13: J3
   {IMP, _j4_, 42}, // 14: J4
   {OU, _b1_, 43}, // 15: C1
   {OU, _b2_, 44}, // 16: C2
   {OU, _b3_, 45}, // 17: C3
   {OU, _b4_, 46}, // 18: C4
   {IMP, _r1_, 47}, // 19: Kr1
   {IMP, _r2_, 48}, // 20: Kr2
   {IMP, _r3_, 49}, // 21: Kr3
   {IMP, _r4_, 50}, // 22: Kr4
   {IMP, _b1_, 51}, // 23: Kb1
   {IMP, _b2_, 52}, // 24: Kb2
   {IMP, _b3_, 53}, // 25: Kb3
   {IMP, _b4_, 54}, // 26: Kb4
   {IMP, _j1_, 55}, // 27: Kj1
   {IMP, _j2_, 56}, // 28: Kj2
   {IMP, _j3_, 57}, // 29: Kj3
   {IMP, _j4_, 58}, // 30: Kj4
   {ET,59,60}, // 31: R1
   {ET,61,62}, // 32: R2
   {ET,63,64}, // 33: R3
   {ET,65,66}, // 34: R4
   {ET,67,68}, // 35: B1
   {ET,69,70}, // 36: B2
   {ET,71,72}, // 37: B3
   {ET,73,74}, // 38: B4
   {ET,75,76}, // 39: J1
   {ET,77,78}, // 40: J2
   {ET,79,80}, // 41: J3
   {ET,81,82}, // 42: J4
   {OU,_j1_,_r1_}, // 43: C1
   {OU,_j2_,_r2_}, // 44: C2
   {OU,_j3_,_r3_}, // 45: C3
   {OU,_j4_,_r4_}, // 46: C4
   {ET,83,84}, // 47: Kr1
   {ET,85,86}, // 48: Kr2
   {ET,87,88}, // 49: Kr3
   {ET,89,90}, // 50: Kr4
   {ET,91,92}, // 51: Kb1
   {ET,93,94}, // 52: Kb2
   {ET,95,96}, // 53: Kb3
   {ET,97,98}, // 54: Kb4
   {ET,99,100}, // 55: Kj1
   {ET,101,102}, // 56: Kj2
   {ET,103,104}, // 57: Kj3
   {ET,105,106}, // 58: Kj4
   {NEGATION,_j1_,VIDE}, // 59: R1
   {NEGATION,_b1_,VIDE}, // 60: R1
   {NEGATION,_j2_,VIDE}, // 61: R2
   {NEGATION,_b2_,VIDE}, // 62: R2
   {NEGATION,_j3_,VIDE}, // 63: R3
   {NEGATION,_b3_,VIDE}, // 64: R3
   {NEGATION,_j4_,VIDE}, // 65: R4
   {NEGATION,_b4_,VIDE}, // 66: R4
   {NEGATION,_j1_,VIDE}, // 67: B1
   {NEGATION,_r1_,VIDE}, // 68: B1
   {NEGATION,_j2_,VIDE}, // 69: B2
   {NEGATION,_r2_,VIDE}, // 70: B2
   {NEGATION,_j3_,VIDE}, // 71: B3
   {NEGATION,_r3_,VIDE}, // 72: B3
   {NEGATION,_j4_,VIDE}, // 73: B4
   {NEGATION,_r4_,VIDE}, // 74: B4
   {NEGATION,_r1_,VIDE}, // 75: J1
   {NEGATION,_b1_,VIDE}, // 76: J1
   {NEGATION,_r2_,VIDE}, // 77: J2
   {NEGATION,_b2_,VIDE}, // 78: J2
   {NEGATION,_r3_,VIDE}, // 79: J3
   {NEGATION,_b3_,VIDE}, // 80: J3
   {NEGATION,_r4_,VIDE}, // 81: J4
   {NEGATION,_b4_,VIDE}, // 82: J4
   {NEGATION,_r2_,VIDE}, // 83: Kr1
   {NEGATION,_r3_,VIDE}, // 84: Kr1
   {NEGATION,_r1_,VIDE}, // 85: Kr2
   {NEGATION,_r4_,VIDE}, // 86: Kr2
   {NEGATION,_r1_,VIDE}, // 87: Kr3
   {NEGATION,_r4_,VIDE}, // 88: Kr3
   {NEGATION,_r2_,VIDE}, // 89: Kr4
   {NEGATION,_r3_,VIDE}, // 90: Kr4
   {NEGATION,_b2_,VIDE}, // 91: Kb1
   {NEGATION,_b3_,VIDE}, // 92: Kb1
   {NEGATION,_b1_,VIDE}, // 93: Kb2
   {NEGATION,_b4_,VIDE}, // 94: Kb2
   {NEGATION,_b1_,VIDE}, // 95: Kb3
   {NEGATION,_b4_,VIDE}, // 96: Kb3
   {NEGATION,_b2_,VIDE}, // 97: Kb4
   {NEGATION,_b3_,VIDE}, // 98: Kb4
   {NEGATION,_j2_,VIDE}, // 99: Kj1
   {NEGATION,_j3_,VIDE}, // 100: Kj1
   {NEGATION,_j1_,VIDE}, // 101: Kj2
   {NEGATION,_j4_,VIDE}, // 102: Kj2
   {NEGATION,_j1_,VIDE}, // 103: Kj3
   {NEGATION,_j4_,VIDE}, // 104: Kj3
   {NEGATION,_j2_,VIDE}, // 105: Kj4
   {NEGATION,_j3_,VIDE}  // 106: Kj4
  };


void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _r1_ : printf("r1"); break;
  case _r2_ : printf("r2"); break;
  case _r3_ : printf("r3"); break;
  case _r4_ : printf("r4"); break;
  case _b1_ : printf("b1"); break;
  case _b2_ : printf("b2"); break;
  case _b3_ : printf("b3"); break;
  case _b4_ : printf("b4"); break;
  case _j1_ : printf("j1"); break;
  case _j2_ : printf("j2"); break;
  case _j3_ : printf("j3"); break;
  case _j4_ : printf("j4"); break;
  }
}
