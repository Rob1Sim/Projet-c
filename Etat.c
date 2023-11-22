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
void ajouterEtat (AutomateFini *automate, bool estInitial, bool estFinal) { // OK

    int nombreEtats = 1 + automate -> nombreEtats ; // augmente le nombre d'etat de 1

    Etat nouvelleEtat;

    nouvelleEtat.estFinal = estFinal;   // init le nouvelle etat avec les parametres
    nouvelleEtat.numeroEtat = nombreEtats;

    Etat *nouveauxEtats = malloc(nombreEtats*sizeof(Etat)); // alloue la memoire pour le nouveau tableau
    for (int i = 0; i < nombreEtats - 1; i++){
        nouveauxEtats[i] = automate -> etats[i]; // copie les ancients etats dans le nouveau tableau
    }

    nouveauxEtats[nombreEtats] = nouvelleEtat; // ajoute le nouvelle etat dans le tableau
    free(automate -> etats);    // libere la memoire de l'ancien tableau
    automate -> etats = nouveauxEtats ;

    if (estInitial){
        automate -> etatInitial = nombreEtats -1 ; // change etat initial si demand�
    }

}
/*
    Modifie un etat d'un automate
    @param automate : automate auquel on veut modifier un etat
    @param numeroEtat : numero de l'etat a modifier
    @param estInitial : true si l'etat est initial, false sinon
    @param estFinal : true si l'etat est final, false sinon
*/
void modifierEtat (AutomateFini *automate, int numeroEtat, bool estInitial, bool estFinal) { // OK

    automate -> etats[numeroEtat].estFinal = estFinal ;
    if (estInitial){
        automate -> etatInitial = numeroEtat ; // change etat initial si demande
    }

}
/*
    Supprime un etat d'un automate
    @param automate : automate auquel on veut supprimer un etat
    @param numeroEtat : numero de l'etat a supprimer
*/
void supprimerEtat (AutomateFini *automate, int numeroEtat ){ // Relou
    
}

void afficherEtat (AutomateFini *automate, int numeroEtat){ 
    printf("Etat numero %d\n",numeroEtat);
    printf("Est final : %d\n",automate->etats[numeroEtat].estFinal);
}

void afficherEtats (AutomateFini *automate){ 
    if (automate->nombreEtats == 0)
    {
        printf("Aucun etat dans l'automate\n");
    }
    
    for (int i = 0; i < automate->nombreEtats; i++)
    {
        afficherEtat(automate,i);
    }
    
}
