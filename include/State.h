
#ifndef H_STATE_H
#define H_STATE_H
typedef struct State State;
#include "FiniteAutomaton.h"
#include <stdbool.h>

struct State {        
    int stateNumber;
    bool isFinal;      
};

void addState (FiniteAutomaton *automate, bool estInitial, bool isFinal);
void editState (FiniteAutomaton *automate, int stateNumber, bool estInitial, bool isFinal);
void deleteState (FiniteAutomaton *automate, int stateNumber );
void dislpayState (FiniteAutomaton *automate, int stateNumber);
void displayStates (FiniteAutomaton *automate);
#endif
