// Compilation g++ -std=c++11 examen.cpp -o exe
// Execution ./exe

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <math.h>
#include "wumpus_1.h"

int est_un_symbole(int _x) {
  return _x < 0;
}

void affiche_formule(int _formule, int (*_ensemble_de_formules)[3] ) {
  if (est_un_symbole(_formule)) {
    affiche_symbole(_formule);
    return;
  }
  switch(_ensemble_de_formules[_formule][0]) {
  case FAIT :
    affiche_symbole(_ensemble_de_formules[_formule][1]);
    break;
  case NEGATION :
    printf("~");
    affiche_formule(_ensemble_de_formules[_formule][1], _ensemble_de_formules);
    break;
  case ET :
    printf("(");
    affiche_formule(_ensemble_de_formules[_formule][1], _ensemble_de_formules);
    printf("&");
    affiche_formule(_ensemble_de_formules[_formule][2], _ensemble_de_formules);
    printf(")");
    break;
  case OU :
    printf("(");
    affiche_formule(_ensemble_de_formules[_formule][1], _ensemble_de_formules);
    printf("|");
    affiche_formule(_ensemble_de_formules[_formule][2], _ensemble_de_formules);
    printf(")");
    break;
  case IMP :
    printf("(");
    affiche_formule(_ensemble_de_formules[_formule][1], _ensemble_de_formules);
    printf("->");
    affiche_formule(_ensemble_de_formules[_formule][2], _ensemble_de_formules);
    printf(")");
    break;
  case EQU :
    printf("(");
    affiche_formule(_ensemble_de_formules[_formule][1], _ensemble_de_formules);
    printf("<->");
    affiche_formule(_ensemble_de_formules[_formule][2], _ensemble_de_formules);
    printf(")");
    break;
  }
}

void affiche_consequence()
{
  printf("{");
  for (int k=1; k < NB_FORMULES; k++) {
    affiche_formule(k, ensemble_de_formules);
    if (k+1 < NB_FORMULES) printf(",");
  }
  printf("} |= ");
  affiche_formule(0, ensemble_de_formules);
}

bool valuationFormule(int _formule, int (*_ensemble_de_formules)[3], int ligne ){
	if (est_un_symbole(_formule)) {
    	if(std::bitset<NB_SYMBOLES>(ligne)[NB_SYMBOLES+_formule]==0){
    		return false;
    	}
    	else return true;
 	}
 	switch(_ensemble_de_formules[_formule][0]) {
  	case FAIT :
   		return valuationFormule(_ensemble_de_formules[_formule][1],_ensemble_de_formules,ligne);
    	break;
  	case NEGATION :
    	if(valuationFormule(_ensemble_de_formules[_formule][1], _ensemble_de_formules,ligne))return false;
    	else return true;
    	break;
  	case ET :
    	if(valuationFormule(_ensemble_de_formules[_formule][1], _ensemble_de_formules,ligne)==true & valuationFormule(_ensemble_de_formules[_formule][2], _ensemble_de_formules,ligne)==true)return true;
    	else return false ;
    	break;
  	case OU :
    	if(valuationFormule(_ensemble_de_formules[_formule][1], _ensemble_de_formules,ligne)==false & valuationFormule(_ensemble_de_formules[_formule][2], _ensemble_de_formules,ligne)==false)return false;
    	else return true ;
    	break;
  	case IMP :
    	if(valuationFormule(_ensemble_de_formules[_formule][1], _ensemble_de_formules,ligne)==true & valuationFormule(_ensemble_de_formules[_formule][2], _ensemble_de_formules,ligne)==false)return false;
    	else return true ;
    	break;
  	case EQU :
    	if(valuationFormule(_ensemble_de_formules[_formule][1], _ensemble_de_formules,ligne)==valuationFormule(_ensemble_de_formules[_formule][2], _ensemble_de_formules,ligne))return true;
    	else return false ;
    	break;
  }
}

bool analyseConsequence(int ligne){
	int nbfalse=0;
	for(int k=1; k < NB_FORMULES; ++k){
		if(!valuationFormule(k,ensemble_de_formules,ligne))++nbfalse;
	}
	if(nbfalse==0)return true;
	return false;
}



int main(int argc, char **argv) 
{
  affiche_consequence();
  std::cout << std::endl;
  std::cout << std::endl;
  int compt = 0 ;
  bool verifAll=true;
  const int max = pow(2, NB_SYMBOLES); //maximum
  for (int i = 0; i < max;++i){
      if(!analyseConsequence(i)){
      	++compt;
      }
      else {
      	if(!valuationFormule(0,ensemble_de_formules,i)){
      		std::cout <<"Ce n'est pas une conséquence sémantique. -> 0"<<std::endl;
      		i=max;
      		verifAll=false;
     	}
     }
  }
  if(compt==max||verifAll)std::cout<< "C'est une conséquence sémantique. -> 1"<<std::endl;
  return 0;
}

