#include<stdio.h>
#include<stdlib.h>
#include "FiniteAutomaton.h"
#include <stdbool.h>

/**
*    Initialization of the Automaton
*    @param automaton automate to initialize
*    @param alphabet alphabet of the automate
*    @param nbOfState  number of states of the automate
     @param alphabetSize size of the alphabet
*    @brief  This function initialize the automate with the alphabet and the number of states 
*/
void initAutomaton(FiniteAutomaton *automaton, char *alphabet, int nbOfState, int alphabetSize) { // OK

    automaton -> alphabet = alphabet ;   //init alphabet
    automaton -> numberOfStates = nbOfState ; //init nombre State
    automaton ->initialState = 0; // par default etat initial est a la position 0
    automaton -> states = malloc(nbOfState*sizeof(State));   // init des State par default
    automaton -> alphabetSize = alphabetSize;
    for (int i = 0; i < nbOfState; i++) {
        automaton->states[i].stateNumber = i;  // numero par default
        automaton->states[i].isFinal = false;    // par default non final
    }

    automaton -> transition = malloc(nbOfState*sizeof(int **)); // init de la matrice des transition

    for (int i = 0; i < nbOfState; i++) {
        automaton -> transition[i] = malloc(nbOfState*sizeof(int *));
        for (int j = 0; j < nbOfState; j++){
            automaton->transition[i][j] = malloc(automaton->alphabetSize*sizeof(int));
            for (int k = 0; k < automaton->alphabetSize; k++){
                automaton->transition[i][j][k] = 0; // par default les transitions sont a 0
            }
        }
    }
}
/**
 * @brief Add a transition to an automaton
 * @param automaton : automaton to which we want to add a transition
 * @param start : start state of the transition
 * @param end : end state of the transition
 * @param letter : letter of the transition
*/
void addTransition (FiniteAutomaton *automaton, State start, State end, int letter ){ // OK
    if (start.stateNumber < 0 || start.stateNumber >= automaton->numberOfStates ||
        end.stateNumber < 0 || end.stateNumber >= automaton->numberOfStates ||
        letter < 0 || letter >= automaton->alphabetSize) {
        printf("Error: Invalid transition parameters.\n");
        return;
    }

    automaton -> transition[start.stateNumber][end.stateNumber][letter] = 1 ;
}
/**
    Delete one transition of an automaton
    @param automaton : automaton to delete a transition
    @param depart : start state of the transition
    @param fin : end state of the transition
*/
void deleteTransition (FiniteAutomaton *automaton, State start, State end,int letter ){ // OK

    automaton -> transition[start.stateNumber][end.stateNumber][letter] = 0 ;
}
/**
    Display the automaton
    @param automaton : automaton to display
*/
void displayAutomaton(FiniteAutomaton *automaton){ 

    int nbrTransitions = automaton->alphabetSize;
    for (int i = 0; i < automaton->numberOfStates; i++)
    {
        for (int j = 0; j < automaton->numberOfStates; j++)
        {
            for (int k = 0; k < nbrTransitions; k++)
            {
                if (automaton->transition[i][j][k] == 1)
                {
                    printf("%d -- %c -- %d\n",automaton->states[i].stateNumber,automaton->alphabet[k],automaton->states[j].stateNumber);
                }
            }
        }
        printf("\n");
    }
}
/**
    Delete an automaton
    @param automate : automaton to delete
*/
void deleteAutomaton(FiniteAutomaton *automaton){ // OK

    free(automaton);
}
/**
    Import an automaton
    @param location : location of the automaton to import

*/
void importAutomaton (char location){ // Plus Tard
    //TODO: Adem
}
/**
    Export an automaton
    @param automaton : automaton to export
*/
void exportAutomaton (FiniteAutomaton *automaton){ // Plus Tard
    //TODO: Adem
}
/**
    check if a word is in an automaton
    @param automaton : automaton to check
    @param word : word to check

*/
bool checkWordInAutomaton(FiniteAutomaton *automaton, char word){ // Plus Tard
    //TODO: Ryad
}
/**
    check if an automaton is complete
    @param automaton : automaton to check
*/
bool isComplete(FiniteAutomaton *automaton){ // Plus Tard
    //TODO: Lina
}
/**
    check if an automaton is deterministic
    @param automaton : automaton to check
*/
bool isDeterministic(FiniteAutomaton *automaton) {
    
    bool hasAlreadyThisLetter = false;
    bool isDet = true;

    for (int i = 0; i < automaton->alphabetSize; i++) {
        for (int y = 0; y < automaton->numberOfStates; y++) {
            for (int j = 0; j < automaton->numberOfStates; j++) {

                if (automaton->transition[y][j][i] == 1) {
                    if (hasAlreadyThisLetter) {
                        isDet = false;
                    }
                    hasAlreadyThisLetter = true;
                }
            }
            hasAlreadyThisLetter = false;
        }
        
    }
    return isDet;
}
/**
    Turn an automaton into a complete automaton
    @param automaton : automaton to turn into a complete automaton
*/
void turnIntoComplete(FiniteAutomaton *automaton){ 
    addState(automaton,false,false); // ajoute un etat puit
    for(int iLetter = 0; iLetter < automaton->alphabetSize; iLetter++){
        for(int iState = 0; iState < automaton->numberOfStates; iState++){
            bool hasTransition = false;
            for(int iState2 = 0; iState2 < automaton->numberOfStates; iState2++){
                if(automaton->transition[iState][iState2][iLetter] == 1){
                    hasTransition = true;
                }
            }
            if(!hasTransition){
                addTransition(automaton,automaton->states[iState],automaton->states[automaton->numberOfStates-1],iLetter);
            }
        }
    }
}   
/**
    Turn an automaton into a deterministic automaton
    @param automaton : automaton to turn into a deterministic automaton

*/
void turnIntoDeterministic(FiniteAutomaton *automaton){ 
    //Pour chaque lettre lettreInitial
    // Pour chaque etat i
    //  tableau dynamique des etats j
    //  Initialisation d'un compteur pour le tableau
    //  Pour chaque etat j
    //      Si il y a une transition de i a j avec la lettre lettreInitial
    //          Ajouter j au tableau
    //          Augmente le compteur
    //  Si le compteur est superieur a 1
    //      Ajouter un etat
    //      Ajouter une transition de i a l'etat nouvellement cree avec la lettre lettreInitial
    //      Pour chaque etat k du tableau dynamique
    //          Pour chaque etat y
    //                  Pour chaque lettre lettreTransition
    //                      Si il y a une transition de de k a y avec la lettre lettreTransition       
    //                          Ajouter une transition de l'etat nouvellement cree a y avec la lettre lettreTransition
    //                          Supprimer la transition de k a y avec la lettre lettreTransition
    //          Si l'etat k est final
    //              Rendre l'etat nouvellement cree final
    //          Supprimer la transition de i a k avec la lettre lettreInitial
    //          
    // A AJOUTER : Supprimer les etats inutiles (non atteignables) il faut vérifier que l'etat n'est pas initial et qu'il n'est pas final et qu'il n'est pas atteignable
}