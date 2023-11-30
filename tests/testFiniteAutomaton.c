#include<stdio.h>
#include<stdlib.h>
#include "FiniteAutomaton.h"
#include <stdbool.h>

void testIsDeterminitic(){
    printf("\033[32mTest isDeterministic\033[0m\n");
    
    FiniteAutomaton *fa = malloc(sizeof(FiniteAutomaton));
    char alphabet[]= {'a','b'} ;
   
    initAutomaton(fa, alphabet, 2, 2);


    addTransition(fa,fa -> states[0],fa -> states[0],1);
    addTransition(fa,fa -> states[0],fa -> states[1],0);
    addTransition(fa,fa -> states[1],fa -> states[0],1);
    addTransition(fa,fa -> states[1],fa -> states[1],0);
    

    if(isDeterministic(fa) == true){
        printf("\033[32mTest 1 - isDeterministic passed\033[0m\n");
    }
    else{
        printf("\033[31mTest 1 failed\033[0m\n");
    }
    deleteAutomaton(fa);

    FiniteAutomaton *fa2 = malloc(sizeof(FiniteAutomaton));
    initAutomaton(fa2, alphabet, 2, 2);

    addTransition(fa2,fa2 -> states[0],fa2 -> states[0],1);
    addTransition(fa2,fa2 -> states[0],fa2 -> states[1],1);
    addTransition(fa2,fa2 -> states[1],fa2 -> states[0],1);
    addTransition(fa2,fa2 -> states[1],fa2 -> states[1],0);

    if(isDeterministic(fa2) == false){
        printf("\033[32mTest 2 - isDeterministic passed\033[0m\n");
    }
    else{
        printf("\033[31mTest 2 failed\033[0m\n");
    }
    deleteAutomaton(fa2);
    printf("\033[32m------------------------------\033[0m\n");
}

void testCreateAutomaton(){
    printf("\033[32mTest createAutomaton\033[0m\n");

    char alphabet[2] ;
    alphabet[0] = 'a' ;
    alphabet[1] = 'b' ;
    int nombreEtat = 2 ;

    //Création de l'automate
    FiniteAutomaton *automate = malloc(sizeof(FiniteAutomaton));
    initAutomaton(automate, alphabet, nombreEtat,2);
    
    //Ajout d'un état final et d'un état initial
    editState(automate,0,true,false);
    editState(automate,1,false,true);

    //Ajout des transitions
    addTransition(automate,automate -> states[0],automate -> states[1],1);
    addTransition(automate,automate -> states[0],automate -> states[0],0);
    addTransition(automate,automate -> states[0],automate -> states[1],0);
    printf("\033[32mTest createAutomaton passed\033[0m\n");
    
    printf("\033[32m------------------------------\033[0m\n");

}