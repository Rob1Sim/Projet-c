
#ifndef H_ETAT_H
#define H_ETAT_H
typedef struct Etat Etat;
#include "AutomateFini.h"
#include <stdbool.h>

struct Etat {        // Type Etat
    int numeroEtat;
    bool estFinal;      // Si Etat Finale
};

void ajouterEtat (AutomateFini *automate, bool estInitial, bool estFinal);
void modifierEtat (AutomateFini *automate, int numeroEtat, bool estInitial, bool estFinal);
void supprimerEtat (AutomateFini *automate, int numeroEtat );
void afficherEtat (AutomateFini *automate, int numeroEtat);
void afficherEtats (AutomateFini *automate);
#endif
