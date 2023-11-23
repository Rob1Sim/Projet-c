#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "State.h"
/*
    Add a state to an automaton
    @param automaton : automaton to which we want to add a state
    @param isInitial : true if the state is initial, false otherwise
    @param isFinal : true if the state is final, false otherwise
*/
void addState (FiniteAutomaton *automaton, bool isInitial, bool isFinal) { 

    int numberOfStates = 1 + automaton -> numberOfStates ; // augmente le nombre d'etat de 1

    State newState;

    newState.isFinal = isFinal;   // init le nouvelle etat avec les parametres
    newState.stateNumber = numberOfStates;

    State *newStates = malloc(numberOfStates*sizeof(State)); // alloue la memoire pour le nouveau tableau
    for (int i = 0; i < numberOfStates - 1; i++){
        newStates[i] = automaton -> states[i]; // copie les ancients etats dans le nouveau tableau
    }

    newStates[numberOfStates] = newState; // ajoute le nouvelle etat dans le tableau
    free(automaton -> states);    // libere la memoire de l'ancien tableau
    automaton -> states = newStates ;

    if (isInitial){
        automaton -> initialState = numberOfStates -1 ; // change etat initial si demand�
    }

}
/*
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
/*
    Delete a state of an automaton
    @param automaton : automaton to which we want to delete a state
    @param stateNumber : number of the state to delete
*/
void deleteState (FiniteAutomaton *automaton, int stateNumber ){ // Relou
    
}
/*
    Display a state of an automaton
    @param automaton : automaton to which we want to display a state
    @param stateNumber : number of the state to display
*/
void dislpayState (FiniteAutomaton *automaton, int stateNumber){ 
    printf("State number %d\n",stateNumber);
    printf("is Final : %d\n",automaton->states[stateNumber].isFinal);
}

/*
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
        dislpayState(automaton,i);
    }
    
}
