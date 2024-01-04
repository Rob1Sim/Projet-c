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
 * @param transition : transition matrix of the automaton, the first transition table corresponds to the first state, the second to the second state, and the last to the index of the letter in the alphabet.
 * @param alphabetSize : size of the alphabet
 */
struct FiniteAutomaton{ 
    char *alphabet;     
    int initialState;    
    int numberOfStates;
    State *states;        
    int ***transition;   
    int alphabetSize;
};

void initAutomaton(FiniteAutomaton *automate, char *alphabet, int numberOfStates, int alphabetSize);

void addTransition (FiniteAutomaton *automate, State depart, State fin, int lettre );
void deleteTransition (FiniteAutomaton *automate, State depart, State fin, int lettre );

void displayAutomaton(FiniteAutomaton *automate);

void deleteAutomaton(FiniteAutomaton *automate);

void importAutomaton (FiniteAutomaton *automaton, char *location);
void invalidFileFormatError(char *alphabet, int *finalStates);

void exportAutomaton (FiniteAutomaton *automate, char *filename);

bool checkWordInAutomaton(FiniteAutomaton *automate, char mot);
bool isComplete(FiniteAutomaton *automate);
bool isDeterministic(FiniteAutomaton *automate);

void turnIntoComplete(FiniteAutomaton *automate);
void turnIntoDeterministic(FiniteAutomaton *automate);
bool isTheStateInTheArray(State *array, int arraySize, State state);
void copyTransitionsToANewState(FiniteAutomaton *automaton, State states,   State currentState );

FiniteAutomaton* createMirrorAutomaton(const FiniteAutomaton *original);
FiniteAutomaton* createComplementAutomaton(const FiniteAutomaton *original);
FiniteAutomaton createProductAutomaton(const FiniteAutomaton *automatonA, const FiniteAutomaton *automatonB);
FiniteAutomaton createConcatenationAutomaton(FiniteAutomaton *automaton1, FiniteAutomaton *automaton2);
#endif
