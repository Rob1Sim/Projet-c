#ifndef H_FINITEAUTOMATON_H
#define H_FINITEAUTOMATON_H
typedef struct FiniteAutomaton FiniteAutomaton;
#include "State.h"
#include <stdbool.h>

/**
 * @brief Struct of a finite automaton
 * @param alphabet : alphabet of the automaton
 * @param initialState : initial state of the automaton
 * @param numberOfStates : number of states of the automaton
 * @param states : array of states of the automaton
 * @param transition : Transition matrix of the automaton, the first transition table corresponds to the first state, the second to the second state, and the last to the index of the letter in the alphabet.
 */
struct FiniteAutomaton{ 
    char *alphabet;     
    int initialState;    
    int numberOfStates;
    State *states;        
    int ***transition;   
};

void initAutomaton(FiniteAutomaton *automate, char *alphabet, int numberOfStates);

void addTransition (FiniteAutomaton *automate, State depart, State fin, int lettre );
void deleteTransition (FiniteAutomaton *automate, State depart, State fin, int lettre );

void displayAutomaton(FiniteAutomaton *automate);
void deleteAutomaton(FiniteAutomaton *automate);
void importAutomaton (char emplacement);
void exportAutomaton (FiniteAutomaton *automate);

bool checkWordInAutomaton(FiniteAutomaton *automate, char mot);

bool isComplete(FiniteAutomaton *automate);
bool isDeterministic(FiniteAutomaton *automate);
void turnIntoComplete(FiniteAutomaton *automate);
void turnIntoDeterministic(FiniteAutomaton *automate);
#endif
