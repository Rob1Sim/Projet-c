#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "State.h"
/**
    Add a state to an automaton
    @param automaton : automaton to which we want to add a state
    @param isInitial : true if the state is initial, false otherwise
    @param isFinal : true if the state is final, false otherwise
*/
void addState (FiniteAutomaton *automaton, bool isInitial, bool isFinal) { 

    int numberOfStates = 1 + automaton -> numberOfStates ; // augmente le nombre d'etat de 1
    automaton -> numberOfStates = numberOfStates ; // change le nombre d'etat dans l'automate
    State newState;

    newState.isFinal = isFinal;   // init le nouvelle etat avec les parametres
    newState.stateNumber = numberOfStates -1;

    State *newStates = malloc(numberOfStates*sizeof(State)); // alloue la memoire pour le nouveau tableau
    for (int i = 0; i < numberOfStates - 1; i++){
        newStates[i] = automaton -> states[i]; // copie les ancients etats dans le nouveau tableau
    }

    newStates[numberOfStates-1] = newState; // ajoute le nouvelle etat dans le tableau
    free(automaton -> states);    // libere la memoire de l'ancien tableau
    automaton -> states = newStates ;

    if (isInitial){
        automaton -> initialState = numberOfStates -1 ; // change etat initial si demand�
    }

    automaton->transition = realloc(automaton->transition,numberOfStates*sizeof(int**)); // augmente la taille de la matrice
    automaton->transition[numberOfStates-1] = malloc(numberOfStates * sizeof(int*)); // initialize memory for the new state's transitions

    for (int i = 0; i < numberOfStates; i++) {
        automaton->transition[i] = realloc(automaton->transition[i], numberOfStates * sizeof(int*)); // augmente la taille de la matrice
        if (i == numberOfStates - 1) {
            for (int j = 0; j < numberOfStates; j++) {
                automaton->transition[i][j] = malloc(automaton->alphabetSize * sizeof(int)); // allocate memory for the new state's transitions
            }
        } else {
            automaton->transition[i][numberOfStates-1] = malloc(automaton->alphabetSize * sizeof(int)); // allocate memory for the new state's transitions
        }
    }

    for (int i = 0; i < numberOfStates; i++)
    {
        for (int j = 0; j < automaton->alphabetSize; j++)
        {
            automaton->transition[numberOfStates-1][i][j] = 0; // par default les transitions sont a 0
            automaton->transition[i][numberOfStates-1][j] = 0; // par default les transitions sont a 0
        }
    }


}
/**
    Edit a state of an automaton
    @param automaton : automaton to which we want to edit a state
    @param stateNumber : number of the state to edit
    @param isInitial : true if the state is initial, false otherwise
    @param isFinal : true if the state is final, false otherwise
*/
void editState (FiniteAutomaton *automaton, int stateNumber, bool isInitial, bool isFinal) { // OK

    automaton -> states[stateNumber].isFinal = isFinal ;
    if (isInitial){
        automaton -> initialState = stateNumber ; // change etat initial si demande
    }

}
/**
    Delete a state of an automaton
    @param automaton : automaton to which we want to delete a state
    @param stateNumber : number of the state to delete
*/
void deleteState (FiniteAutomaton *automaton, int stateToRemove ){ 
        int numStates = automaton->numberOfStates;
    int alphaSize = automaton->alphabetSize;
 
    if (stateToRemove < 0 || stateToRemove >= numStates) {
        printf("Invalid State.\n");
        return;
    }
 
    for (int i = 0; i < numStates; ++i) {
        for (int j = 0; j < alphaSize; ++j) {
            // Si la transition implique l'état à supprimer, la mettre à -1 ou à un état invalide
            if (automaton->transition[i][j][stateToRemove] != -1) {
                automaton->transition[i][j][stateToRemove] = -1; // Transition vers un état invalide
            }
        }
    }
 
    for (int i = 0; i < numStates; ++i) {
        free(automaton->transition[stateToRemove][i]);
    }
    free(automaton->transition[stateToRemove]);
 
    for (int i = stateToRemove + 1; i < numStates; ++i) {
        automaton->transition[i - 1] = automaton->transition[i];
    }
 
    for (int i = 0; i < numStates; ++i) {
        if (i >= stateToRemove) {
            automaton->states[i] = automaton->states[i + 1];
        }
        if (automaton->states[i].stateNumber > stateToRemove) {
            automaton->states[i].stateNumber -= 1;
        }
    }
 
    automaton->numberOfStates -= 1;
 
    if (automaton->initialState == stateToRemove) {
        automaton->initialState = -1; 
    } else if (automaton->initialState > stateToRemove) {
        automaton->initialState -= 1;
    }
}
/**
    Display a state of an automaton
    @param automaton : automaton to which we want to display a state
    @param stateNumber : number of the state to display
*/
void displayState (FiniteAutomaton *automaton, int stateNumber){ 
    printf("State number %d\n",stateNumber);
    printf("is Final : %d\n",automaton->states[stateNumber].isFinal);
}

/**
    Display all states of an automaton
    @param automaton : automaton to which we want to display all states
*/
void displayStates (FiniteAutomaton *automaton){ 
    if (automaton->numberOfStates == 0)
    {
        printf("No states in this automaton\n");
    }
    
    for (int i = 0; i < automaton->numberOfStates; i++)
    {
        displayState(automaton,i);
    }
    
}
