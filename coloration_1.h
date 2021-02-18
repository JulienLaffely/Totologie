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
#define NB_FORMULES 30

// Coloration 
// R u B u J u C u K u {r1} |/= b2 

static int ensemble_de_formules[][3] =
  {{FAIT, _b2_, VIDE}, // 0:
   {FAIT, _r1_, VIDE}, // 1:
   {IMP, _r1_, 30}, // 2: R1
   {IMP, _r2_, 31}, // 3: R2
   {IMP, _r3_, 32}, // 4: R3
   {IMP, _r4_, 33}, // 5: R4
   {IMP, _b1_, 34}, // 6: B1
   {IMP, _b2_, 35}, // 7: B2
   {IMP, _b3_, 36}, // 8: B3
   {IMP, _b4_, 37}, // 9: B4
   {IMP, _j1_, 38}, // 10: J1
   {IMP, _j2_, 39}, // 11: J2
   {IMP, _j3_, 40}, // 12: J3
   {IMP, _j4_, 41}, // 13: J4
   {OU, _b1_, 42}, // 14: C1
   {OU, _b2_, 43}, // 15: C2
   {OU, _b3_, 44}, // 16: C3
   {OU, _b4_, 45}, // 17: C4
   {IMP, _r1_, 46}, // 18: Kr1
   {IMP, _r2_, 47}, // 19: Kr2
   {IMP, _r3_, 48}, // 20: Kr3
   {IMP, _r4_, 49}, // 21: Kr4
   {IMP, _b1_, 50}, // 22: Kb1
   {IMP, _b2_, 51}, // 23: Kb2
   {IMP, _b3_, 52}, // 24: Kb3
   {IMP, _b4_, 53}, // 25: Kb4
   {IMP, _j1_, 54}, // 26: Kj1
   {IMP, _j2_, 55}, // 27: Kj2
   {IMP, _j3_, 56}, // 28: Kj3
   {IMP, _j4_, 57}, // 29: Kj4
   {ET,58,59}, // 30: R1
   {ET,60,61}, // 31: R2
   {ET,62,63}, // 32: R3
   {ET,64,65}, // 33: R4
   {ET,66,67}, // 34: B1
   {ET,68,69}, // 35: B2
   {ET,70,71}, // 36: B3
   {ET,72,73}, // 37: B4
   {ET,74,75}, // 38: J1
   {ET,76,77}, // 39: J2
   {ET,78,79}, // 40: J3
   {ET,80,81}, // 41: J4
   {OU,_j1_,_r1_}, // 42: C1
   {OU,_j2_,_r2_}, // 43: C2
   {OU,_j3_,_r3_}, // 44: C3
   {OU,_j4_,_r4_}, // 45: C4
   {ET,82,83}, // 46: Kr1
   {ET,84,85}, // 47: Kr2
   {ET,86,87}, // 48: Kr3
   {ET,88,89}, // 49: Kr4
   {ET,90,91}, // 50: Kb1
   {ET,92,93}, // 51: Kb2
   {ET,94,95}, // 52: Kb3
   {ET,96,97}, // 53: Kb4
   {ET,98,99}, // 54: Kj1
   {ET,100,101}, // 55: Kj2
   {ET,102,103}, // 56: Kj3
   {ET,104,105}, // 57: Kj4
   {NEGATION,_j1_,VIDE}, // 58: R1
   {NEGATION,_b1_,VIDE}, // 59: R1
   {NEGATION,_j2_,VIDE}, // 60: R2
   {NEGATION,_b2_,VIDE}, // 61: R2
   {NEGATION,_j3_,VIDE}, // 62: R3
   {NEGATION,_b3_,VIDE}, // 63: R3
   {NEGATION,_j4_,VIDE}, // 64: R4
   {NEGATION,_b4_,VIDE}, // 65: R4
   {NEGATION,_j1_,VIDE}, // 66: B1
   {NEGATION,_r1_,VIDE}, // 67: B1
   {NEGATION,_j2_,VIDE}, // 68: B2
   {NEGATION,_r2_,VIDE}, // 69: B2
   {NEGATION,_j3_,VIDE}, // 70: B3
   {NEGATION,_r3_,VIDE}, // 71: B3
   {NEGATION,_j4_,VIDE}, // 72: B4
   {NEGATION,_r4_,VIDE}, // 73: B4
   {NEGATION,_r1_,VIDE}, // 74: J1
   {NEGATION,_b1_,VIDE}, // 75: J1
   {NEGATION,_r2_,VIDE}, // 76: J2
   {NEGATION,_b2_,VIDE}, // 77: J2
   {NEGATION,_r3_,VIDE}, // 78: J3
   {NEGATION,_b3_,VIDE}, // 79: J3
   {NEGATION,_r4_,VIDE}, // 80: J4
   {NEGATION,_b4_,VIDE}, // 81: J4
   {NEGATION,_r2_,VIDE}, // 82: Kr1
   {NEGATION,_r3_,VIDE}, // 83: Kr1
   {NEGATION,_r1_,VIDE}, // 84: Kr2
   {NEGATION,_r4_,VIDE}, // 85: Kr2
   {NEGATION,_r1_,VIDE}, // 86: Kr3
   {NEGATION,_r4_,VIDE}, // 87: Kr3
   {NEGATION,_r2_,VIDE}, // 88: Kr4
   {NEGATION,_r3_,VIDE}, // 89: Kr4
   {NEGATION,_b2_,VIDE}, // 90: Kb1
   {NEGATION,_b3_,VIDE}, // 91: Kb1
   {NEGATION,_b1_,VIDE}, // 92: Kb2
   {NEGATION,_b4_,VIDE}, // 93: Kb2
   {NEGATION,_b1_,VIDE}, // 94: Kb3
   {NEGATION,_b4_,VIDE}, // 95: Kb3
   {NEGATION,_b2_,VIDE}, // 96: Kb4
   {NEGATION,_b3_,VIDE}, // 97: Kb4
   {NEGATION,_j2_,VIDE}, // 98: Kj1
   {NEGATION,_j3_,VIDE}, // 99: Kj1
   {NEGATION,_j1_,VIDE}, // 100: Kj2
   {NEGATION,_j4_,VIDE}, // 101: Kj2
   {NEGATION,_j1_,VIDE}, // 102: Kj3
   {NEGATION,_j4_,VIDE}, // 103: Kj3
   {NEGATION,_j2_,VIDE}, // 104: Kj4
   {NEGATION,_j3_,VIDE}  // 105: Kj4
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
