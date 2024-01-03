#include<stdio.h>
#include<stdlib.h>
#include "FiniteAutomaton.h"
#include "StateQueue.h"
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

    free(automaton->states);
    for (int i = 0; i < automaton->numberOfStates; i++)
    {
        for (int j = 0; j < automaton->numberOfStates; j++)
        {
            free(automaton->transition[i][j]);
        }
        free(automaton->transition[i]);
    }
    free(automaton->transition);
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
void turnIntoDeterministic(FiniteAutomaton *automaton) {

    StateQueue *queue = createQueue();
    State initialState = automaton->states[0];
    enqueue(queue, initialState);

    while (!isEmpty(queue)) {
        State currentState = dequeue(queue);

        for (int i = 0; i < automaton->alphabetSize; i++) {
            State *nextStates = malloc(automaton->numberOfStates * sizeof(State));
            int nextStatesCount = 0;
            nextStates[nextStatesCount] = currentState;
            for (int j = 0; j < automaton->numberOfStates; j++) {
                if (automaton->transition[currentState.stateNumber][j][i] == 1) {
                    nextStates[nextStatesCount++] = automaton->states[j];
                }
            }

            // si y'a deux fois la meme lettre
            if (nextStatesCount > 1) {
                addState(automaton, false, false);
                for (int j = 1; j < nextStatesCount; j++) {
                    copyTransitionsToANewState(automaton, nextStates[j],currentState);   

                    if (nextStates[j].isFinal) {
                        automaton->states[automaton->numberOfStates - 1].isFinal = true;
                    }
                }
                
                bool isReflective = true;
                for (int j = 0; j < automaton->numberOfStates; j++) {

                    if (automaton->transition[automaton->numberOfStates - 1][j][i] == 1 && !isTheStateInTheArray(nextStates, nextStatesCount, automaton->states[j])) {
                        isReflective = false;
                    }

                }

                if (isReflective){
                    for (int j = 0; j < nextStatesCount; j++)
                    {
                        deleteTransition(automaton, automaton->states[automaton->numberOfStates - 1], nextStates[j], i);
                    }
                    addTransition(automaton, automaton->states[automaton->numberOfStates - 1], automaton->states[automaton->numberOfStates - 1], i);
                }

                enqueue(queue, automaton->states[automaton->numberOfStates - 1]);
                addTransition(automaton, currentState, automaton->states[automaton->numberOfStates - 1], i);
            }


        }
    }

    free(queue);
}

void copyTransitionsToANewState(FiniteAutomaton *automaton, State states, State currentState ) {
    int numberOfStates = automaton->numberOfStates;

    for (int j = 0; j < automaton->alphabetSize; j++) {
        for (int y = 0; y < numberOfStates; y++) {
            if (automaton->transition[states.stateNumber][y][j] == 1) {
                addTransition(automaton, automaton->states[numberOfStates-1], automaton->states[y], j);
            }

            if (automaton->transition[currentState.stateNumber][y][j] == 1){
                deleteTransition(automaton, automaton->states[currentState.stateNumber], automaton->states[y], j);
            }
        }
    }
}

bool isTheStateInTheArray(State *array, int arraySize, State state) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i].stateNumber == state.stateNumber) {
            return true;
        }
    }
    return false;
}
/**
 * @brief Create a mirror automaton from an original automaton
 * @param original : original automaton
*/
FiniteAutomaton* createMirrorAutomaton(const FiniteAutomaton *original) {
    FiniteAutomaton *mirror = malloc(sizeof(FiniteAutomaton));
 
    // Copy the basic information
    mirror->alphabet = original->alphabet;
    mirror->initialState = -1; // Placeholder for the initial state of the mirror, to be set later
    mirror->numberOfStates = original->numberOfStates;
    mirror->states = (State *)malloc(sizeof(State) * mirror->numberOfStates);
    mirror->transition = (int ***)malloc(sizeof(int **) * mirror->numberOfStates);
    mirror->alphabetSize = original->alphabetSize;
 
    // Create mirror states (reversing the isFinal flag)
    for (int i = 0; i < mirror->numberOfStates; ++i) {
        mirror->states[i].stateNumber = i;
        mirror->states[i].isFinal = !original->states[i].isFinal;
    }
 
    // Create mirror transitions
    for (int i = 0; i < mirror->numberOfStates; ++i) {
        mirror->transition[i] = (int **)malloc(sizeof(int *) * mirror->numberOfStates);
        for (int j = 0; j < mirror->numberOfStates; ++j) {
            mirror->transition[i][j] = (int *)malloc(sizeof(int) * mirror->alphabetSize);
            for (int k = 0; k < mirror->alphabetSize; ++k) {
                // Reverse the direction of the transition
                mirror->transition[i][j][k] = original->transition[j][i][k];
            }
        }
    }
 
    // Set the initial state of the mirror
    mirror->initialState = original->numberOfStates - 1;
 
    return mirror;
}