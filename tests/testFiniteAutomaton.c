#include<stdio.h>
#include<stdlib.h>
#include "FiniteAutomaton.h"
#include <stdbool.h>

void testIsDeterminitic(){
    printf("Test isDeterministic\n");
    
    FiniteAutomaton *fa = malloc(sizeof(FiniteAutomaton));
    char alphabet[]= {'a','b'} ;
   
    initAutomaton(fa, alphabet, 2, 2);


    addTransition(fa,fa -> states[0],fa -> states[0],1);
    addTransition(fa,fa -> states[0],fa -> states[1],0);
    addTransition(fa,fa -> states[1],fa -> states[0],1);
    addTransition(fa,fa -> states[1],fa -> states[1],0);
    
    displayAutomaton(fa);

    if(isDeterministic(fa) == true){
        printf("Test 1 - isDeterministic passed\n");
    }
    else{
        printf("Test 1 failed\n");
    }
    deleteAutomaton(fa);

    FiniteAutomaton *fa2 = malloc(sizeof(FiniteAutomaton));
    initAutomaton(fa2, alphabet, 2, 2);

    addTransition(fa2,fa2 -> states[0],fa2 -> states[0],1);
    addTransition(fa2,fa2 -> states[0],fa2 -> states[1],1);
    addTransition(fa2,fa2 -> states[1],fa2 -> states[0],1);
    addTransition(fa2,fa2 -> states[1],fa2 -> states[1],0);

    if(isDeterministic(fa2) == false){
        printf("Test 2 - isDeterministic passed\n");
    }
    else{
        printf("Test 2 failed\n");
    }
    deleteAutomaton(fa2);
}