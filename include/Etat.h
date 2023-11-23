
#ifndef H_ETAT_H
#define H_ETAT_H
typedef struct Etat Etat;
#include "FiniteAutomaton.h"
#include <stdbool.h>

struct Etat {        // Type Etat
    int numeroEtat;
    bool estFinal;      // Si Etat Finale
};

void ajouterEtat (FiniteAutomaton *automate, bool estInitial, bool estFinal);
void modifierEtat (FiniteAutomaton *automate, int numeroEtat, bool estInitial, bool estFinal);
void supprimerEtat (FiniteAutomaton *automate, int numeroEtat );
void afficherEtat (FiniteAutomaton *automate, int numeroEtat);
void afficherEtats (FiniteAutomaton *automate);
#endif
