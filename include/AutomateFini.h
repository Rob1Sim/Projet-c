#ifndef H_AUTOMATEFINI_H
#define H_AUTOMATEFINI_H
typedef struct AutomateFini AutomateFini;
#include "Etat.h"
#include <stdbool.h>

/**
 * @brief Structure d'un automate fini
 * @param alphabet : alphabet de l'automate
 * @param etatInitial : etat initial de l'automate
 * @param nombreEtats : nombre d'etats de l'automate
 * @param etats : tableau des etats de l'automate
 * @param transition : matrice des transitions de l'automate, le premier tableau des transitions correspond au premier etat, le deuxieme au deuxieme etat, et le dernier à l'index de la lettre dans l'alphabet
 */
struct AutomateFini{ 
    char *alphabet;     
    int etatInitial;    
    int nombreEtats;
    Etat *etats;        
    int ***transition;   
};

void initialiserAutomate(AutomateFini *automate, char *alphabet, int nombreEtats);

void ajouterTransition (AutomateFini *automate, Etat depart, Etat fin, int lettre );
void supprimerTransition (AutomateFini *automate, Etat depart, Etat fin, int lettre );

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
