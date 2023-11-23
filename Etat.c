#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "Etat.h"
/*
    Ajoute un etat à un automate
    @param automate : automate auquel on veut ajouter un etat
    @param estInitial : true si l'etat est initial, false sinon
    @param estFinal : true si l'etat est final, false sinon
*/
void ajouterEtat (FiniteAutomaton *automate, bool estInitial, bool estFinal) { // OK

    int numberOfStates = 1 + automate -> numberOfStates ; // augmente le nombre d'etat de 1

    Etat nouvelleEtat;

    nouvelleEtat.estFinal = estFinal;   // init le nouvelle etat avec les parametres
    nouvelleEtat.numeroEtat = numberOfStates;

    Etat *nouveauxEtats = malloc(numberOfStates*sizeof(Etat)); // alloue la memoire pour le nouveau tableau
    for (int i = 0; i < numberOfStates - 1; i++){
        nouveauxEtats[i] = automate -> states[i]; // copie les ancients etats dans le nouveau tableau
    }

    nouveauxEtats[numberOfStates] = nouvelleEtat; // ajoute le nouvelle etat dans le tableau
    free(automate -> states);    // libere la memoire de l'ancien tableau
    automate -> states = nouveauxEtats ;

    if (estInitial){
        automate -> initialState = numberOfStates -1 ; // change etat initial si demand�
    }

}
/*
    Modifie un etat d'un automate
    @param automate : automate auquel on veut modifier un etat
    @param numeroEtat : numero de l'etat a modifier
    @param estInitial : true si l'etat est initial, false sinon
    @param estFinal : true si l'etat est final, false sinon
*/
void modifierEtat (FiniteAutomaton *automate, int numeroEtat, bool estInitial, bool estFinal) { // OK

    automate -> states[numeroEtat].estFinal = estFinal ;
    if (estInitial){
        automate -> initialState = numeroEtat ; // change etat initial si demande
    }

}
/*
    Supprime un etat d'un automate
    @param automate : automate auquel on veut supprimer un etat
    @param numeroEtat : numero de l'etat a supprimer
*/
void supprimerEtat (FiniteAutomaton *automate, int numeroEtat ){ // Relou
    
}

void afficherEtat (FiniteAutomaton *automate, int numeroEtat){ 
    printf("Etat numero %d\n",numeroEtat);
    printf("Est final : %d\n",automate->states[numeroEtat].estFinal);
}

void afficherEtats (FiniteAutomaton *automate){ 
    if (automate->numberOfStates == 0)
    {
        printf("Aucun etat dans l'automate\n");
    }
    
    for (int i = 0; i < automate->numberOfStates; i++)
    {
        afficherEtat(automate,i);
    }
    
}
