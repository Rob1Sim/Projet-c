#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Etat.h"
#include "AutomateFini.h"

int main() {
    /*
    int choix;

    while (true)
    {
        printf("---------------------------------------------\n");
        printf("Voici le menu de notre projet\n");
        printf("Si vous voulez :\n");
        printf("    Creez un automate alors tapez 1 \n");
        printf("    Modifiez un automate alors tapez 2 \n");
        printf("    Importez un automate alors tapez 3 \n");
        printf("    Exportez un automate alors tapez 4 \n");
        printf("    Supprimez un automate alors tapez 5 \n");
        printf("---------------------------------------------\n");

        scanf("%d", &choix);

        switch (choix)
        {
            case 1:

            case 2:

            case 3:

            case 4:

            case 5:

            default:
                printf("Choix non valide. Veuillez reessayer.\n");
        }
    }
    */
    // Exemple automate 1

    char alphabet[2] ;
    alphabet[0] = 'a' ;
    alphabet[1] = 'b' ;
    int nombreEtat = 2 ;

    //Création de l'automate
    AutomateFini *automate = malloc(sizeof(AutomateFini));
    initialiserAutomate(automate, alphabet, nombreEtat);
    
    //Ajout d'un état final et d'un état initial
    modifierEtat(automate,0,true,false);
    modifierEtat(automate,1,false,true);

    //Ajout des transitions
    ajouterTransition(automate,automate -> etats[0],automate -> etats[1],1);
    ajouterTransition(automate,automate -> etats[0],automate -> etats[0],0);
    ajouterTransition(automate,automate -> etats[0],automate -> etats[1],0);
    
    //Affichage de l'automate
    afficherAutomate(automate);


    return 0;
}
