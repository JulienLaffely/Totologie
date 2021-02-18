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
#define NB_FORMULES 32

// Coloration 
// R u B u J u C u K u {r1, ~b2, ~j3} |/= r4 

static int ensemble_de_formules[][3] =
  {{FAIT, _r4_, VIDE}, // 0:
   {FAIT, _r1_, VIDE}, // 1:
   {NEGATION, _b2_, VIDE}, // 2:
   {NEGATION, _j3_, VIDE}, // 3:
   {IMP, _r1_, 32}, // 4: R1
   {IMP, _r2_, 33}, // 5: R2
   {IMP, _r3_, 34}, // 6: R3
   {IMP, _r4_, 35}, // 7: R4
   {IMP, _b1_, 36}, // 8: B1
   {IMP, _b2_, 37}, // 9: B2
   {IMP, _b3_, 38}, // 10: B3
   {IMP, _b4_, 39}, // 11: B4
   {IMP, _j1_, 40}, // 12: J1
   {IMP, _j2_, 41}, // 13: J2
   {IMP, _j3_, 42}, // 14: J3
   {IMP, _j4_, 43}, // 15: J4
   {OU, _b1_, 44}, // 16: C1
   {OU, _b2_, 45}, // 17: C2
   {OU, _b3_, 46}, // 18: C3
   {OU, _b4_, 47}, // 19: C4
   {IMP, _r1_, 48}, // 20: Kr1
   {IMP, _r2_, 49}, // 21: Kr2
   {IMP, _r3_, 50}, // 22: Kr3
   {IMP, _r4_, 51}, // 23: Kr4
   {IMP, _b1_, 52}, // 24: Kb1
   {IMP, _b2_, 53}, // 25: Kb2
   {IMP, _b3_, 54}, // 26: Kb3
   {IMP, _b4_, 55}, // 27: Kb4
   {IMP, _j1_, 56}, // 28: Kj1
   {IMP, _j2_, 57}, // 29: Kj2
   {IMP, _j3_, 58}, // 30: Kj3
   {IMP, _j4_, 59}, // 31: Kj4
   {ET,60,61}, // 32: R1
   {ET,62,63}, // 33: R2
   {ET,64,65}, // 34: R3
   {ET,66,67}, // 35: R4
   {ET,68,69}, // 36: B1
   {ET,70,71}, // 37: B2
   {ET,72,73}, // 38: B3
   {ET,74,75}, // 39: B4
   {ET,76,77}, // 40: J1
   {ET,78,79}, // 41: J2
   {ET,80,81}, // 42: J3
   {ET,82,83}, // 43: J4
   {OU,_j1_,_r1_}, // 44: C1
   {OU,_j2_,_r2_}, // 45: C2
   {OU,_j3_,_r3_}, // 46: C3
   {OU,_j4_,_r4_}, // 47: C4
   {ET,84,85}, // 48: Kr1
   {ET,86,87}, // 49: Kr2
   {ET,88,89}, // 50: Kr3
   {ET,90,91}, // 51: Kr4
   {ET,92,93}, // 52: Kb1
   {ET,94,95}, // 53: Kb2
   {ET,96,97}, // 54: Kb3
   {ET,98,99}, // 55: Kb4
   {ET,100,101}, // 56: Kj1
   {ET,102,103}, // 57: Kj2
   {ET,104,105}, // 58: Kj3
   {ET,106,107}, // 59: Kj4
   {NEGATION,_j1_,VIDE}, // 60: R1
   {NEGATION,_b1_,VIDE}, // 61: R1
   {NEGATION,_j2_,VIDE}, // 62: R2
   {NEGATION,_b2_,VIDE}, // 63: R2
   {NEGATION,_j3_,VIDE}, // 64: R3
   {NEGATION,_b3_,VIDE}, // 65: R3
   {NEGATION,_j4_,VIDE}, // 66: R4
   {NEGATION,_b4_,VIDE}, // 67: R4
   {NEGATION,_j1_,VIDE}, // 68: B1
   {NEGATION,_r1_,VIDE}, // 69: B1
   {NEGATION,_j2_,VIDE}, // 70: B2
   {NEGATION,_r2_,VIDE}, // 71: B2
   {NEGATION,_j3_,VIDE}, // 72: B3
   {NEGATION,_r3_,VIDE}, // 73: B3
   {NEGATION,_j4_,VIDE}, // 74: B4
   {NEGATION,_r4_,VIDE}, // 75: B4
   {NEGATION,_r1_,VIDE}, // 76: J1
   {NEGATION,_b1_,VIDE}, // 77: J1
   {NEGATION,_r2_,VIDE}, // 78: J2
   {NEGATION,_b2_,VIDE}, // 79: J2
   {NEGATION,_r3_,VIDE}, // 80: J3
   {NEGATION,_b3_,VIDE}, // 81: J3
   {NEGATION,_r4_,VIDE}, // 82: J4
   {NEGATION,_b4_,VIDE}, // 83: J4
   {NEGATION,_r2_,VIDE}, // 84: Kr1
   {NEGATION,_r3_,VIDE}, // 85: Kr1
   {NEGATION,_r1_,VIDE}, // 86: Kr2
   {NEGATION,_r4_,VIDE}, // 87: Kr2
   {NEGATION,_r1_,VIDE}, // 88: Kr3
   {NEGATION,_r4_,VIDE}, // 89: Kr3
   {NEGATION,_r2_,VIDE}, // 90: Kr4
   {NEGATION,_r3_,VIDE}, // 91: Kr4
   {NEGATION,_b2_,VIDE}, // 92: Kb1
   {NEGATION,_b3_,VIDE}, // 93: Kb1
   {NEGATION,_b1_,VIDE}, // 94: Kb2
   {NEGATION,_b4_,VIDE}, // 95: Kb2
   {NEGATION,_b1_,VIDE}, // 96: Kb3
   {NEGATION,_b4_,VIDE}, // 97: Kb3
   {NEGATION,_b2_,VIDE}, // 98: Kb4
   {NEGATION,_b3_,VIDE}, // 99: Kb4
   {NEGATION,_j2_,VIDE}, // 100: Kj1
   {NEGATION,_j3_,VIDE}, // 101: Kj1
   {NEGATION,_j1_,VIDE}, // 102: Kj2
   {NEGATION,_j4_,VIDE}, // 103: Kj2
   {NEGATION,_j1_,VIDE}, // 104: Kj3
   {NEGATION,_j4_,VIDE}, // 105: Kj3
   {NEGATION,_j2_,VIDE}, // 106: Kj4
   {NEGATION,_j3_,VIDE}  // 107: Kj4
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
