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

void initAutomaton(FiniteAutomaton *automaton, char *alphabet, int numberOfStates, int alphabetSize);

void addTransition (FiniteAutomaton *automaton, State start, State end, int letter );
void deleteTransition (FiniteAutomaton *automaton, State start, State end, int letter );

void displayAutomaton(FiniteAutomaton *automaton);

void deleteAutomaton(FiniteAutomaton *automaton);

void importAutomaton (FiniteAutomaton *automaton, char *location);
void invalidFileFormatError(char *alphabet, int *finalStates);

void exportAutomaton (FiniteAutomaton *automaton, char *filename);

bool checkWordInAutomaton(FiniteAutomaton *automaton, char *word);
bool isComplete(FiniteAutomaton *automaton);
bool isDeterministic(FiniteAutomaton *automaton);

void turnIntoComplete(FiniteAutomaton *automaton);
void turnIntoDeterministic(FiniteAutomaton *automaton);
bool isTheStateInTheArray(State *array, int arraySize, State state);
void copyTransitionsToANewState(FiniteAutomaton *automaton, State states,   State currentState );

FiniteAutomaton* createMirrorAutomaton(const FiniteAutomaton *original);
FiniteAutomaton* createComplementAutomaton(const FiniteAutomaton *original);
FiniteAutomaton createProductAutomaton(const FiniteAutomaton *automatonA, const FiniteAutomaton *automatonB);
FiniteAutomaton createConcatenationAutomaton(FiniteAutomaton *automaton1, FiniteAutomaton *automaton2);
#endif
