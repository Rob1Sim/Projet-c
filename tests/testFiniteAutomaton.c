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
    return;
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
    
    deleteAutomaton(automate);
    printf("\033[32m------------------------------\033[0m\n");
    return;
}

void testAddState(){
    printf("\033[32mTest addState\033[0m\n");
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

    //Ajout d'un état
    addState(automate,false,false);
    editState(automate,2,false,false);

    addTransition(automate,automate -> states[2],automate -> states[2],1);
    addTransition(automate,automate -> states[2],automate -> states[2],0);
    displayAutomaton(automate);
    printf("\033[32mTest addState passed\033[0m\n");
    deleteAutomaton(automate);
    printf("\033[32m------------------------------\033[0m\n");
    return;
}

void testTurnIntoComplete(){
    printf("\033[32mTest turnIntoComplete\033[0m\n");
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
    addTransition(automate,automate -> states[0],automate -> states[1],1); // 0 -> 1 b
    addTransition(automate,automate -> states[1],automate -> states[1],1); // 1 -> 1 b
    addTransition(automate,automate -> states[1],automate -> states[1],0); // 1 -> 1 a

    displayAutomaton(automate);
    turnIntoComplete(automate);
    displayAutomaton(automate);
    printf("\033[32mTest turnIntoComplete passed\033[0m\n");
    deleteAutomaton(automate);
    printf("\033[32m------------------------------\033[0m\n");
    return;
}

void testTurnIntoDeterministic(){
    printf("\033[32mTest turnIntoDeterministic\033[0m\n");
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
    addTransition(automate,automate -> states[0],automate -> states[1],0); // 0 -> 1 a
    addTransition(automate,automate -> states[0],automate -> states[0],0); // 0 -> 0 a
    addTransition(automate,automate -> states[1],automate -> states[1],1); // 1 -> 1 b
    addTransition(automate,automate -> states[1],automate -> states[1],0); // 1 -> 1 a

    displayAutomaton(automate);
    printf("\033[32m------------------------------\033[0m\n");

    turnIntoDeterministic(automate);
    displayAutomaton(automate);

    if (isDeterministic(automate))
    {
        printf("\033[32mTest turnIntoDeterministic passed\033[0m\n"); 
    }
    else
    {
        printf("\033[31mTest turnIntoDeterministic failed\033[0m\n");
    }
    deleteAutomaton(automate);

    // Test turnIntoDeterministic 2
    printf("\033[32m    Test 2 - turnIntoDeterministic\033[0m\n");
    char alphabet2[2] ;
    alphabet2[0] = 'a' ;
    alphabet2[1] = 'b' ;
    int nombreEtat2 = 4 ;

    //Création de l'automate
    FiniteAutomaton *automate2 = malloc(sizeof(FiniteAutomaton));
    initAutomaton(automate2, alphabet2, nombreEtat2,2);
    
    //Ajout d'un état final et d'un état initial
    editState(automate2,0,true,false);
    editState(automate2,1,false,true);

    //Ajout des transitions
    addTransition(automate2,automate2 -> states[0],automate2 -> states[0],0); // 0 -> 0 a
    addTransition(automate2,automate2 -> states[0],automate2 -> states[2],0); // 0 -> 2 a
    addTransition(automate2,automate2 -> states[0],automate2 -> states[1],1); // 0 -> 1 b
    addTransition(automate2,automate2 -> states[1],automate2 -> states[0],1); // 1 -> 0 b
    addTransition(automate2,automate2 -> states[1],automate2 -> states[3],1); // 1 -> 3 b
    addTransition(automate2,automate2 -> states[2],automate2 -> states[1],1); // 2 -> 1 b
    addTransition(automate2,automate2 -> states[2],automate2 -> states[3],0); // 2 -> 3 a
    addTransition(automate2,automate2 -> states[3],automate2 -> states[3],0); // 3 -> 3 a
    addTransition(automate2,automate2 -> states[3],automate2 -> states[1],1); // 3 -> 1 b



    displayAutomaton(automate2);
    printf("\033[32m------------------------------\033[0m\n");

    turnIntoDeterministic(automate2);
    displayAutomaton(automate2);

    if (isDeterministic(automate2))
    {
        printf("\033[32m    Test 2 -  turnIntoDeterministic passed\033[0m\n");
    }
    else
    {
        printf("\033[31m    Test 2 -  turnIntoDeterministic failed\033[0m\n");
    }
    deleteAutomaton(automate2);

    printf("\033[32m------------------------------\033[0m\n");
    return;
}
