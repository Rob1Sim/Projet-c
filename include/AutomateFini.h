#ifndef H_AUTOMATEFINI_H
#define H_AUTOMATEFINI_H
typedef struct AutomateFini AutomateFini;
#include "Etat.h"
#include <stdbool.h>

struct AutomateFini{        // Type Automate
    char *alphabet;     // Alphabet
    int etatInitial;    // Etat Initial
    int nombreEtats;
    Etat *etats;        // Tableau des Etats
    int **transition;   // Matrice des transitions
};

void initialiserAutomate(AutomateFini *automate, char *alphabet, int nombreEtats);

void ajouterTransition (AutomateFini *automate, Etat depart, Etat fin, int lettre );
void supprimerTransition (AutomateFini *automate, Etat depart, Etat fin );

void afficherAutomate(AutomateFini *automate);
void supprimerAutomate(AutomateFini *automate);
void importerAutomate (char emplacement);
void exporterAutomate (AutomateFini *automate);

bool verifierMotDansAutomate(AutomateFini *automate, char mot);

bool estComplet(AutomateFini *automate);
bool estDeterministe(AutomateFini *automate);
void rendreComplet(AutomateFini *automate);
void rendreDeterministe(AutomateFini *automate);
#endif
