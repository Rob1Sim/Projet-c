
#ifndef H_STATE_H
#define H_STATE_H
typedef struct State State;
#include "FiniteAutomaton.h"
#include <stdbool.h>

/**
 * @brief Struct of a state
 * @param stateNumber : number of the state
 * @param isFinal : true if the state is final, false otherwise
*/
struct State {        
    int stateNumber;
    bool isFinal;      
};

void addState (FiniteAutomaton *automate, bool estInitial, bool isFinal);
void editState (FiniteAutomaton *automate, int stateNumber, bool estInitial, bool isFinal);
void deleteState (FiniteAutomaton *automate, int stateNumber );
void displayState (FiniteAutomaton *automate, int stateNumber);
void displayStates (FiniteAutomaton *automate);
#endif
