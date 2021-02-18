#include "examen.h"

#define _s11_ -1
#define _s12_ -2
#define _s13_ -3
#define _s14_ -4
#define _s21_ -5
#define _s22_ -6
#define _s23_ -7
#define _s24_ -8
#define _s31_ -9
#define _s32_ -10
#define _s33_ -11
#define _s34_ -12
#define _s41_ -13
#define _s42_ -14
#define _s43_ -15
#define _s44_ -16


#define _a11_ -17
#define _a12_ -18
#define _a13_ -19
#define _a14_ -20
#define _a21_ -21
#define _a22_ -22
#define _a23_ -23
#define _a24_ -24
#define _a31_ -25
#define _a32_ -26 
#define _a33_ -27
#define _a34_ -28
#define _a41_ -29
#define _a42_ -30
#define _a43_ -31
#define _a44_ -32


#define _o11_ -33
#define _o12_ -34
#define _o13_ -35
#define _o14_ -36
#define _o21_ -37
#define _o22_ -38
#define _o23_ -39
#define _o24_ -40
#define _o31_ -41
#define _o32_ -42
#define _o33_ -43
#define _o34_ -44
#define _o41_ -45
#define _o42_ -46
#define _o43_ -47
#define _o44_ -48


#define _b11_ -49
#define _b12_ -50
#define _b13_ -51
#define _b14_ -52
#define _b21_ -53
#define _b22_ -54
#define _b23_ -55
#define _b24_ -56
#define _b31_ -57
#define _b32_ -58
#define _b33_ -59
#define _b34_ -60
#define _b41_ -61
#define _b42_ -62
#define _b43_ -63
#define _b44_ -64


#define _w11_ -65
#define _w12_ -66
#define _w13_ -67
#define _w14_ -68
#define _w21_ -69
#define _w22_ -70
#define _w23_ -71
#define _w24_ -72
#define _w31_ -73
#define _w32_ -74
#define _w33_ -75
#define _w34_ -76
#define _w41_ -77
#define _w42_ -78
#define _w43_ -79
#define _w44_ -80






#define NB_SYMBOLES 80
#define NB_FORMULES 86

// Wumpus
// O+ u O- u B- u B+ u S |/= ~s22 

static int ensemble_de_formules[][3] =
  {{NEGATION, _s22_, VIDE}, // 0:
   {IMP, 110, 111}, // 1: O-11
   {IMP, 112, 113}, // 2: O-12
   {IMP, 114, 115}, // 3: O-13
   {IMP, 116, 117}, // 4: O-14
   {IMP, 118, 119}, // 5: O-21
   {IMP, 120, 121}, // 6: O-22
   {IMP, 122, 123}, // 7: O-23
   {IMP, 124, 125}, // 8: O-24
   {IMP, 126, 127}, // 9: O-31
   {IMP, 128, 129}, // 10: O-32
   {IMP, 130, 131}, // 11: O-33
   {IMP, 132, 133}, // 12: O-34
   {IMP, 134, 135}, // 13: O-41
   {IMP, 136, 137}, // 14: O-42
   {IMP, 138, 139}, // 15: O-43
   {IMP, 140, 141}, // 16: O-44
   {IMP, _o11_, 142}, // 17: O+11
   {IMP, _o12_, 143}, // 18: O+12
   {IMP, _o13_, 144}, // 19: O+13
   {IMP, _o14_, 145}, // 20: O+14
   {IMP, _o21_, 146}, // 21: O+21
   {IMP, _o22_, 147}, // 22: O+22
   {IMP, _o23_, 148}, // 23: O+23
   {IMP, _o24_, 149}, // 24: O+24
   {IMP, _o31_, 150}, // 25: O+31
   {IMP, _o32_, 151}, // 26: O+32
   {IMP, _o33_, 152}, // 27: O+33
   {IMP, _o34_, 153}, // 28: O+34
   {IMP, _o41_, 154}, // 29: O+41
   {IMP, _o42_, 155}, // 30: O+42
   {IMP, _o43_, 156}, // 31: O+43
   {IMP, _o44_, 157}, // 32: O+44
   {IMP, 158, 159}, // 33: B-11
   {IMP, 160, 161}, // 34: B-12
   {IMP, 162, 163}, // 35: B-13
   {IMP, 164, 165}, // 36: B-14
   {IMP, 166, 167}, // 37: B-21
   {IMP, 168, 169}, // 38: B-22
   {IMP, 170, 171}, // 39: B-23
   {IMP, 172, 173}, // 40: B-24
   {IMP, 174, 175}, // 41: B-31
   {IMP, 176, 177}, // 42: B-32
   {IMP, 178, 179}, // 43: B-33
   {IMP, 180, 181}, // 44: B-34
   {IMP, 182, 183}, // 45: B-41
   {IMP, 184, 185}, // 46: B-42
   {IMP, 186, 187}, // 47: B-43
   {IMP, 188, 189}, // 48: B-44
   {IMP, _b11_, 190}, // 49: B+11
   {IMP, _b12_, 191}, // 50: B+12
   {IMP, _b13_, 192}, // 51: B+13
   {IMP, _b14_, 193}, // 52: B+14
   {IMP, _b21_, 194}, // 53: B+21
   {IMP, _b22_, 195}, // 54: B+22
   {IMP, _b23_, 196}, // 55: B+23
   {IMP, _b24_, 197}, // 56: B+24
   {IMP, _b31_, 198}, // 57: B+31
   {IMP, _b32_, 199}, // 58: B+32
   {IMP, _b33_, 200}, // 59: B+33
   {IMP, _b34_, 201}, // 60: B+34
   {IMP, _b41_, 202}, // 61: B+41
   {IMP, _b42_, 203}, // 62: B+42
   {IMP, _b43_, 204}, // 63: B+43
   {IMP, _b44_, 205}, // 64: B+44
   {EQU, 206, _s11_}, // 65: S11
   {EQU, 207, _s12_}, // 66: S12
   {EQU, 208, _s13_}, // 67: S13
   {EQU, 209, _s14_}, // 68: S14
   {EQU, 210, _s21_}, // 69: S21
   {EQU, 211, _s22_}, // 70: S22
   {EQU, 212, _s23_}, // 71: S23
   {EQU, 213, _s24_}, // 72: S24
   {EQU, 214, _s31_}, // 73: S31
   {EQU, 215, _s32_}, // 74: S32
   {EQU, 216, _s33_}, // 75: S33
   {EQU, 217, _s34_}, // 76: S34
   {EQU, 218, _s41_}, // 77: S41
   {EQU, 219, _s42_}, // 78: S42
   {EQU, 220, _s43_}, // 79: S43
   {EQU, 221, _s44_}, // 80: S44
   {FAIT, _s11_, VIDE}, // 81: s11
   {NEGATION, _o11_, VIDE}, // 82: ~o11
   {NEGATION, _b11_, VIDE}, // 83: ~b11
   {NEGATION, _a11_, VIDE}, // 84: ~a11
   {NEGATION, _w11_, VIDE}, // 85: ~w11
   {VIDE, VIDE, VIDE}, // 86
   {VIDE, VIDE, VIDE}, // 87
   {VIDE, VIDE, VIDE}, // 88
   {VIDE, VIDE, VIDE}, // 89
   {VIDE, VIDE, VIDE}, // 90
   {VIDE, VIDE, VIDE}, // 91
   {VIDE, VIDE, VIDE}, // 92
   {VIDE, VIDE, VIDE}, // 93
   {VIDE, VIDE, VIDE}, // 94
   {VIDE, VIDE, VIDE}, // 95
   {VIDE, VIDE, VIDE}, // 96
   {VIDE, VIDE, VIDE}, // 97
   {VIDE, VIDE, VIDE}, // 98
   {VIDE, VIDE, VIDE}, // 99
   {VIDE, VIDE, VIDE}, // 100
   {VIDE, VIDE, VIDE}, // 101
   {VIDE, VIDE, VIDE}, // 102
   {VIDE, VIDE, VIDE}, // 103
   {VIDE, VIDE, VIDE}, // 104
   {VIDE, VIDE, VIDE}, // 105
   {VIDE, VIDE, VIDE}, // 106 
   {VIDE, VIDE, VIDE}, // 107
   {VIDE, VIDE, VIDE}, // 108
   {VIDE, VIDE, VIDE}, // 109
   {NEGATION, _o11_, VIDE}, // 110 : O-11
   {ET, 222, 223}, // 111: O-11
   {NEGATION, _o12_, VIDE}, // 112: O-12
   {ET, 224, 225}, // 113: O-12
   {NEGATION, _o13_, VIDE}, // 114: O-13
   {ET, 226, 227}, // 115: O-13
   {NEGATION, _o14_, VIDE}, // 116: O-14
   {ET, 228, 229}, // 117: O-14
   {NEGATION, _o21_, VIDE}, // 118: O-21
   {ET, 230, 231}, // 119: O-21
   {NEGATION, _o22_, VIDE}, // 120: O-22
   {ET, 232, 233}, // 121: O-22
   {NEGATION, _o23_, VIDE}, // 122: O-23
   {ET, 234, 235}, // 123: O-23
   {NEGATION, _o24_, VIDE}, // 124: O-24
   {ET, 236, 237}, // 125: O-24
   {NEGATION, _o31_, VIDE}, // 126: O-31
   {ET, 238, 239}, // 127: O-31
   {NEGATION, _o32_, VIDE}, // 128: O-32
   {ET, 240, 241}, // 129: O-32
   {NEGATION, _o33_, VIDE}, // 130: O-33
   {ET, 242, 243}, // 131: O-33
   {NEGATION, _o34_, VIDE}, // 132: O-34
   {ET, 244, 245}, // 133: O-34
   {NEGATION, _o41_, VIDE}, // 134: O-41
   {ET, 246, 247}, // 135: O-41
   {NEGATION, _o42_, VIDE}, // 136: O-42
   {ET, 248, 249}, // 137: O-42
   {NEGATION, _o43_, VIDE}, // 138: O-43
   {ET, 250, 251}, // 139: O-43
   {NEGATION, _o44_, VIDE}, // 140: O-44
   {ET, 252, 253}, // 141: O-44
   {OU, _w12_, _w21_}, // 142: O+11
   {OU, 254, _w13_}, // 143: O+12
   {OU, 255, _w14_}, // 144: O+13
   {OU, _w13_, _w24_}, // 145: O+14
   {OU, 256, _w31_}, // 146: O+21
   {OU, 257, 258}, // 147: O+22
   {OU, 259, 260}, // 148: O+23
   {OU, 261, _w34_}, // 149: O+24
   {OU, 262, _w41_}, // 150: O+31
   {OU, 263, 264}, // 151: O+32
   {OU, 265, 266}, // 152: O+33
   {OU, 267, _w44_}, // 153: O+34
   {OU, _w31_, _w42_}, // 154: O+41
   {OU, 268, _w43_}, // 155: O+42
   {OU, 269, _w44_}, // 156: O+43
   {OU, _w43_, _w34_}, // 157: O+44
   {NEGATION, _b11_, VIDE}, // 158: B-11
   {ET, 270, 271}, // 159: B-11
   {NEGATION, _b12_, VIDE}, // 160: B-12
   {ET, 272, 273}, // 161: B-12
   {NEGATION, _b13_, VIDE}, // 162: B-13
   {ET, 274, 275}, // 163: B-13
   {NEGATION, _b14_, VIDE}, // 164: B-14
   {ET, 276, 277}, // 165: B-14
   {NEGATION, _b21_, VIDE}, // 166: B-21
   {ET, 278, 279}, // 167: B-21
   {NEGATION, _b22_, VIDE}, // 168: B-22
   {ET, 280, 281}, // 169: B-22
   {NEGATION, _b23_, VIDE}, // 170: B-23
   {ET, 282, 283}, // 171: B-23
   {NEGATION, _b24_, VIDE}, // 172: B-24
   {ET, 284, 285}, // 173: B-24
   {NEGATION, _b31_, VIDE}, // 174: B-31
   {ET, 286, 287}, // 175: B-31
   {NEGATION, _b32_, VIDE}, // 176: B-32
   {ET, 288, 289}, // 177: B-32
   {NEGATION, _b33_, VIDE}, // 178: B-33
   {ET, 290, 291}, // 179: B-33
   {NEGATION, _b34_, VIDE}, // 180: B-34
   {ET, 292, 293}, // 181: B-34
   {NEGATION, _b41_, VIDE}, // 182: B-41
   {ET, 294, 295}, // 183: B-41
   {NEGATION, _b42_, VIDE}, // 184: B-42
   {ET, 296, 297}, // 185: B-42
   {NEGATION, _b43_, VIDE}, // 186: B-43
   {ET, 298, 299}, // 187: B-43
   {NEGATION, _b44_, VIDE}, // 188: B-44
   {ET, 300, 301}, // 189: B-44
   {OU, _a12_, _a21_}, // 190: B+11
   {OU, 302, _a13_}, // 191: B+12
   {OU, 303, _a14_}, // 192: B+13
   {OU, _a13_, _a24_}, // 193: B+14
   {OU, 304, _a31_}, // 194: B+21
   {OU, 305, 306}, // 195: B+22
   {OU, 307, 308}, // 196: B+23
   {OU, 309, _a34_}, // 197: B+24
   {OU, 310, _a41_}, // 198: B+31
   {OU, 311, 312}, // 199: B+32
   {OU, 313, 314}, // 200: B+33
   {OU, 315, _b34_}, // 201: B+34
   {OU, _a31_, _a42_}, // 202: B+41
   {OU, 316, _a43_}, // 203: B+42
   {OU, 317, _a44_}, // 204: B+43
   {OU, _a43_, _a34_}, // 205: B+44
   {ET, 318, 319}, // 206: S11
   {ET, 320, 321}, // 207: S12
   {ET, 322, 323}, // 208: S13
   {ET, 324, 325}, // 209: S14
   {ET, 326, 327}, // 210: S21
   {ET, 328, 329}, // 211: S22
   {ET, 330, 331}, // 212: S23
   {ET, 332, 333}, // 213: S24
   {ET, 334, 335}, // 214: S31
   {ET, 336, 337}, // 215: S32
   {ET, 339, 339}, // 216: S33
   {ET, 340, 341}, // 217: S34
   {ET, 342, 343}, // 218: S41
   {ET, 344, 345}, // 219: S42
   {ET, 346, 347}, // 220: S43
   {ET, 348, 349}, // 221: S44
   {NEGATION, _w12_, VIDE}, // 222: O-11
   {NEGATION, _w21_, VIDE}, // 223: O-11
   {ET, 350, 351}, // 224: O-12
   {NEGATION, _w13_, VIDE}, // 225: O-12
   {ET, 352, 353}, // 226: O-13
   {NEGATION, _w14_, VIDE}, // 227: O-13
   {NEGATION, _w13_, VIDE}, // 228: O-14
   {NEGATION, _w24_, VIDE}, // 229: O-14
   {ET, 354, 355}, // 230: O-21
   {NEGATION, _w31_, VIDE}, // 231: O-21
   {ET, 356, 357}, // 232: O-22
   {ET, 358, 359}, // 233: O-22
   {ET, 360, 361}, // 234: O-23
   {ET, 362, 363}, // 235: O-23
   {ET, 364, 365}, // 236: O-24
   {NEGATION, _w34_, VIDE}, // 237: O-24
   {ET, 366, 367}, // 238: O-31
   {NEGATION, _w41_, VIDE}, // 239: O-31
   {ET, 368, 369}, // 240: O-32
   {ET, 370, 371}, // 241: O-32
   {ET, 372, 373}, // 242: O-33
   {ET, 374, 375}, // 243: O-33
   {ET, 376, 377}, // 244: O-34
   {NEGATION, _w44_, VIDE}, // 245: O-34
   {NEGATION, _w31_, VIDE}, // 246: O-41
   {NEGATION, _w42_, VIDE}, // 247: O-41
   {ET, 378, 379}, // 248: O-42
   {NEGATION, _w43_, VIDE}, // 249: O-42
   {ET, 380, 381}, // 250: O-43
   {NEGATION, _w44_, VIDE}, // 251: O-43
   {NEGATION, _w43_, VIDE}, // 252: O-44
   {NEGATION, _w34_, VIDE}, // 253: O-44
   {OU, _w11_, _w22_}, // 254: O+12
   {OU, _w12_, _w23_}, // 255: O+13
   {OU, _w11_, _w22_}, // 256: O+21
   {OU, _w21_, _w12_}, // 257: O+22
   {OU, _w32_, _w23_}, // 258: O+22
   {OU, _w22_, _w13_}, // 259: O+23
   {OU, _w33_, _w24_}, // 260: O+23
   {OU, _w23_, _w14_}, // 261: O+24
   {OU, _w21_, _w32_}, // 262: O+31
   {OU, _w31_, _w22_}, // 263: O+32
   {OU, _w42_, _w33_}, // 264: O+32
   {OU, _w32_, _w23_}, // 265: O+33
   {OU, _w43_, _w34_}, // 266: O+33
   {OU, _w24_, _w33_}, // 267: O+34
   {OU, _w41_, _w32_}, // 268: O+42
   {OU, _w42_, _w33_}, // 269: O+43
   {NEGATION, _a12_, VIDE}, // 270: B-11
   {NEGATION, _a21_, VIDE}, // 271: B-11
   {ET, 382, 383}, // 272: B-12
   {NEGATION, _a13_, VIDE}, // 273: B-12
   {ET, 384, 385}, // 274: B-13
   {NEGATION, _a14_, VIDE}, // 275: B-13
   {NEGATION, _a13_, VIDE}, // 276: B-14
   {NEGATION, _a24_, VIDE}, // 277: B-14
   {ET, 386, 387}, // 278: B-21
   {NEGATION, _a31_, VIDE}, // 279: B-21
   {ET, 388, 389}, // 280: B-22
   {ET, 390, 391}, // 281: B-22
   {ET, 392, 393}, // 282: B-23
   {ET, 394, 395}, // 283: B-23
   {ET, 396, 397}, // 284: B-24
   {NEGATION, _a34_, VIDE}, // 285: B-24
   {ET, 398, 399}, // 286: B-31
   {NEGATION, _a41_, VIDE}, // 287: B-31
   {ET, 400, 401}, // 288: B-32
   {ET, 402, 403}, // 289: B-32
   {ET, 404, 405}, // 290: B-33
   {ET, 406, 407}, // 291: B-33
   {ET, 408, 409}, // 292: B-34
   {NEGATION, _a44_, VIDE}, // 293: B-34
   {NEGATION, _a31_, VIDE}, // 294: B-41
   {NEGATION, _a42_, VIDE}, // 295: B-41
   {ET, 410, 411}, // 296: B-42
   {NEGATION, _a43_, VIDE}, // 297: B-42
   {ET, 412, 413}, // 298: B-43
   {NEGATION, _a44_, VIDE}, // 299: B-43
   {NEGATION, _a43_, VIDE}, // 300: B-44
   {NEGATION, _a34_, VIDE}, // 301: B-44
   {OU, _a11_, _a22_}, // 302: B+12
   {OU, _a12_, _a23_}, // 303: B+13
   {OU, _a11_, _a22_}, // 304: B+21
   {OU, _a21_, _a12_}, // 305: B+22
   {OU, _a32_, _a23_}, // 306: B+22
   {OU, _a22_, _a13_}, // 307: B+23
   {OU, _a33_, _a24_}, // 308: B+23
   {OU, _a23_, _a14_}, // 309: B+24
   {OU, _a21_, _a32_}, // 310: B+31
   {OU, _a31_, _a22_}, // 311: B+32
   {OU, _a42_, _a33_}, // 312: B+32
   {OU, _a32_, _a23_}, // 313: B+33
   {OU, _a43_, _a34_}, // 314: B+33
   {OU, _a24_, _a33_}, // 315: B+34
   {OU, _a41_, _a32_}, // 316: B+34
   {OU, _a42_, _a33_}, // 317: B+43
   {NEGATION, _w11_, VIDE}, // 318: S11
   {NEGATION, _a11_, VIDE}, // 319: S11
   {NEGATION, _w12_, VIDE}, // 320: S12
   {NEGATION, _a12_, VIDE}, // 321: S12
   {NEGATION, _w13_, VIDE}, // 322: S13
   {NEGATION, _a13_, VIDE}, // 323: S13
   {NEGATION, _w14_, VIDE}, // 324: S14
   {NEGATION, _a14_, VIDE}, // 325: S14
   {NEGATION, _w21_, VIDE}, // 326: S21
   {NEGATION, _a21_, VIDE}, // 327: S21
   {NEGATION, _w22_, VIDE}, // 328: S22
   {NEGATION, _a22_, VIDE}, // 329: S22
   {NEGATION, _w23_, VIDE}, // 330: S23
   {NEGATION, _a23_, VIDE}, // 331: S23
   {NEGATION, _w24_, VIDE}, // 332: S24
   {NEGATION, _a24_, VIDE}, // 333: S24
   {NEGATION, _w31_, VIDE}, // 334: S31
   {NEGATION, _a31_, VIDE}, // 335: S31
   {NEGATION, _w32_, VIDE}, // 336: S32
   {NEGATION, _a32_, VIDE}, // 337: S32
   {NEGATION, _w33_, VIDE}, // 338: S33
   {NEGATION, _a33_, VIDE}, // 339: S33
   {NEGATION, _w34_, VIDE}, // 340: S34
   {NEGATION, _a34_, VIDE}, // 341: S34
   {NEGATION, _w41_, VIDE}, // 342: S41
   {NEGATION, _a41_, VIDE}, // 343: S41
   {NEGATION, _w42_, VIDE}, // 344: S42
   {NEGATION, _a42_, VIDE}, // 345: S42
   {NEGATION, _w43_, VIDE}, // 346: S43
   {NEGATION, _a43_, VIDE}, // 347: S43
   {NEGATION, _w44_, VIDE}, // 348: S44
   {NEGATION, _a44_, VIDE}, // 349: S44
   {NEGATION, _w11_, VIDE}, //350: O-12
   {NEGATION, _w22_, VIDE}, //351: O-12
   {NEGATION, _w12_, VIDE}, //352: O-13
   {NEGATION, _w23_, VIDE}, //353: O-13
   {NEGATION, _w11_, VIDE}, //354: O-21
   {NEGATION, _w22_, VIDE}, //355: O-21
   {NEGATION, _w21_, VIDE}, //356: O-22
   {NEGATION, _w12_, VIDE}, //357: O-22
   {NEGATION, _w32_, VIDE}, //358: O-22
   {NEGATION, _w23_, VIDE}, //359: O-22
   {NEGATION, _w22_, VIDE}, //360: O-23
   {NEGATION, _w13_, VIDE}, //361: O-23
   {NEGATION, _w33_, VIDE}, //362: O-23
   {NEGATION, _w24_, VIDE}, //363: O-23
   {NEGATION, _w23_, VIDE}, //364: O-24
   {NEGATION, _w14_, VIDE}, //365: O-24
   {NEGATION, _w21_, VIDE}, //366: O-31
   {NEGATION, _w32_, VIDE}, //367: O-31
   {NEGATION, _w31_, VIDE}, //368: O-32
   {NEGATION, _w22_, VIDE}, //369: O-32
   {NEGATION, _w42_, VIDE}, //370: O-32
   {NEGATION, _w33_, VIDE}, //371: O-32
   {NEGATION, _w32_, VIDE}, //372: O-33
   {NEGATION, _w23_, VIDE}, //373: O-33
   {NEGATION, _w43_, VIDE}, //374: O-33
   {NEGATION, _w34_, VIDE}, //375: O-33
   {NEGATION, _w33_, VIDE}, //376: O-34
   {NEGATION, _w24_, VIDE}, //377: O-34
   {NEGATION, _w41_, VIDE}, //378: O-42
   {NEGATION, _w32_, VIDE}, //379: O-42
   {NEGATION, _w42_, VIDE}, //380: O-43
   {NEGATION, _w33_, VIDE}, //381: O-43
   {NEGATION, _a11_, VIDE}, //382: B-12
   {NEGATION, _a22_, VIDE}, //383: B-12
   {NEGATION, _a12_, VIDE}, //384: B-13
   {NEGATION, _a23_, VIDE}, //385: B-13
   {NEGATION, _a11_, VIDE}, //386: B-21
   {NEGATION, _a22_, VIDE}, //387: B-21
   {NEGATION, _a21_, VIDE}, //388: B-22
   {NEGATION, _a12_, VIDE}, //389: B-22
   {NEGATION, _a32_, VIDE}, //390: B-22
   {NEGATION, _a23_, VIDE}, //391: B-22
   {NEGATION, _a22_, VIDE}, //392: B-23
   {NEGATION, _a13_, VIDE}, //393: B-23
   {NEGATION, _a33_, VIDE}, //394: B-23
   {NEGATION, _a24_, VIDE}, //395: B-23
   {NEGATION, _a23_, VIDE}, //396: B-24
   {NEGATION, _a14_, VIDE}, //397: B-24
   {NEGATION, _a21_, VIDE}, //398: B-31
   {NEGATION, _a32_, VIDE}, //399: B-31
   {NEGATION, _a31_, VIDE}, //400: B-32
   {NEGATION, _a22_, VIDE}, //401: B-32
   {NEGATION, _a42_, VIDE}, //402: B-32
   {NEGATION, _a33_, VIDE}, //403: B-32
   {NEGATION, _a32_, VIDE}, //404: B-33
   {NEGATION, _a23_, VIDE}, //405: B-33
   {NEGATION, _a43_, VIDE}, //406: B-33
   {NEGATION, _a34_, VIDE}, //407: B-33
   {NEGATION, _a33_, VIDE}, //408: B-34
   {NEGATION, _a24_, VIDE}, //409: B-34
   {NEGATION, _a41_, VIDE}, //410: B-42
   {NEGATION, _a32_, VIDE}, //411: B-42
   {NEGATION, _a42_, VIDE}, //412: B-43
   {NEGATION, _a33_, VIDE} //413: B-43
  };

void affiche_symbole(int _symbole) {
  switch(_symbole) {
  case _a11_ : printf("a11"); break;
  case _a12_ : printf("a12"); break;
  case _a13_ : printf("a13"); break;
  case _a14_ : printf("a14"); break;
  case _a21_ : printf("a21"); break;
  case _a22_ : printf("a22"); break;
  case _a23_ : printf("a23"); break;
  case _a24_ : printf("a24"); break;
  case _a31_ : printf("a31"); break;
  case _a32_ : printf("a32"); break;
  case _a33_ : printf("a33"); break;
  case _a34_ : printf("a34"); break;
  case _a41_ : printf("a41"); break;
  case _a42_ : printf("a42"); break;
  case _a43_ : printf("a43"); break;
  case _a44_ : printf("a44"); break;
  case _b11_ : printf("b11"); break;
  case _b12_ : printf("b12"); break;
  case _b13_ : printf("b13"); break;
  case _b14_ : printf("b14"); break;
  case _b21_ : printf("b21"); break;
  case _b22_ : printf("b22"); break;
  case _b23_ : printf("b23"); break;
  case _b24_ : printf("b24"); break;
  case _b31_ : printf("b31"); break;
  case _b32_ : printf("b32"); break;
  case _b33_ : printf("b33"); break;
  case _b34_ : printf("b34"); break;
  case _b41_ : printf("b41"); break;
  case _b42_ : printf("b42"); break;
  case _b43_ : printf("b43"); break;
  case _b44_ : printf("b44"); break;
  case _o11_ : printf("o11"); break;
  case _o12_ : printf("o12"); break;
  case _o13_ : printf("o13"); break;
  case _o14_ : printf("o14"); break;
  case _o21_ : printf("o21"); break;
  case _o22_ : printf("o22"); break;
  case _o23_ : printf("o23"); break;
  case _o24_ : printf("o24"); break;
  case _o31_ : printf("o31"); break;
  case _o32_ : printf("o32"); break;
  case _o33_ : printf("o33"); break;
  case _o34_ : printf("o34"); break;
  case _o41_ : printf("o41"); break;
  case _o42_ : printf("o42"); break;
  case _o43_ : printf("o43"); break;
  case _o44_ : printf("o44"); break;
  case _s11_ : printf("s11"); break;
  case _s12_ : printf("s12"); break;
  case _s13_ : printf("s13"); break;
  case _s14_ : printf("s14"); break;
  case _s21_ : printf("s21"); break;
  case _s22_ : printf("s22"); break;
  case _s23_ : printf("s23"); break;
  case _s24_ : printf("s24"); break;
  case _s31_ : printf("s31"); break;
  case _s32_ : printf("s32"); break;
  case _s33_ : printf("s33"); break;
  case _s34_ : printf("s34"); break;
  case _s41_ : printf("s41"); break;
  case _s42_ : printf("s42"); break;
  case _s43_ : printf("s43"); break;
  case _s44_ : printf("s44"); break;
  case _w11_ : printf("w11"); break;
  case _w12_ : printf("w12"); break;
  case _w13_ : printf("w13"); break;
  case _w14_ : printf("w14"); break;
  case _w21_ : printf("w21"); break;
  case _w22_ : printf("w22"); break;
  case _w23_ : printf("w23"); break;
  case _w24_ : printf("w24"); break;
  case _w31_ : printf("w31"); break;
  case _w32_ : printf("w32"); break;
  case _w33_ : printf("w33"); break;
  case _w34_ : printf("w34"); break;
  case _w41_ : printf("w41"); break;
  case _w42_ : printf("w42"); break;
  case _w43_ : printf("w43"); break;
  case _w44_ : printf("w44"); break;
  }
}
