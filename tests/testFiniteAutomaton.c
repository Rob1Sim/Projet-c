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

void testCreateMirrorAutomaton(){
    printf("\033[32mTest createMirrorAutomaton\033[0m\n");
    
    FiniteAutomaton *fa = malloc(sizeof(FiniteAutomaton));

    char alphabet[]= {'a','b'} ;
   
    initAutomaton(fa, alphabet, 2, 2);

 
    addTransition(fa,fa -> states[0],fa -> states[0],1);
    addTransition(fa,fa -> states[0],fa -> states[1],0);
    addTransition(fa,fa -> states[1],fa -> states[0],1);
    addTransition(fa,fa -> states[1],fa -> states[1],0);
    
    FiniteAutomaton *fa2 = createMirrorAutomaton(fa);
    deleteAutomaton(fa);
    deleteAutomaton(fa2);
    printf("\033[32mTest createMirrorAutomaton passed\033[0m\n");
}

void testCreateComplementAutomaton(){
    printf("\033[32mTest createComplementAutomaton\033[0m\n");
    
    FiniteAutomaton *fa = malloc(sizeof(FiniteAutomaton));

    char alphabet[]= {'a','b'} ;
   
    initAutomaton(fa, alphabet, 2, 2);

 
    addTransition(fa,fa -> states[0],fa -> states[0],1);
    addTransition(fa,fa -> states[0],fa -> states[1],0);
    addTransition(fa,fa -> states[1],fa -> states[0],1);
    addTransition(fa,fa -> states[1],fa -> states[1],0);
    
    FiniteAutomaton *fa2 = createComplementAutomaton(fa);
    deleteAutomaton(fa);
    deleteAutomaton(fa2);
    printf("\033[32mTest createComplementAutomaton passed\033[0m\n");
}

void testIsComplete(){
    printf("\033[32mTest isComplete\033[0m\n");
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

    printf("\033[32m------------------------------\033[0m\n");

    if (!isComplete(automate))
    {
        printf("\033[32mTest 1 - isComplete passed\033[0m\n"); 
    }
    else
    {
        printf("\033[31mTest isComplete failed\033[0m\n");
    }
    addTransition(automate,automate -> states[0],automate -> states[0],0); // 0 -> 0 a
    if (isComplete(automate))
    {
        printf("\033[32mTest 2 - isComplete passed\033[0m\n"); 
    }
    else
    {
        printf("\033[31mTest 2 - isComplete failed\033[0m\n");
    }
    deleteAutomaton(automate);
}

void testExportAutomaton(){
    printf("\033[32mTest exportAutomaton\033[0m\n");
    char alphabet[2];
    alphabet[0] = 'a';
    alphabet[1] = 'b';
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

    printf("\033[32m------------------------------\033[0m\n");

    exportAutomaton(automate,"testExportAutomaton.txt");
    printf("\033[32mTest exportAutomaton passed\033[0m\n");
    deleteAutomaton(automate);
}

void testImportAutomaton(){
    printf("\033[32mTest importAutomaton\033[0m\n");
    
    char alphabet[2];
    alphabet[0] = 'a';
    alphabet[1] = 'b';
    int nombreEtat = 2 ;

    //Création de l'automate
    FiniteAutomaton *initialAutomaton = malloc(sizeof(FiniteAutomaton));
    initAutomaton(initialAutomaton, alphabet, nombreEtat,2);
    
    //Ajout d'un état final et d'un état initial
    editState(initialAutomaton,0,true,false);
    editState(initialAutomaton,1,false,true);

    //Ajout des transitions
    addTransition(initialAutomaton,initialAutomaton -> states[0],initialAutomaton -> states[1],1); // 0 -> 1 b
    addTransition(initialAutomaton,initialAutomaton -> states[1],initialAutomaton -> states[1],1); // 1 -> 1 b
    addTransition(initialAutomaton,initialAutomaton -> states[1],initialAutomaton -> states[1],0); // 1 -> 1 a
    printf("\033[32m------------------------------\033[0m\n");
    
    exportAutomaton(initialAutomaton,"testImportAutomaton.txt");

    FiniteAutomaton *importedAutomaton = malloc(sizeof(FiniteAutomaton));
    importAutomaton(importedAutomaton,"out/testImportAutomaton.txt");

    if (importAutomaton == NULL)
    {
        printf("\033[31mTest 1 - importAutomaton failed\033[0m\n");
    }
    else
    {
        printf("\033[32mTest 1 - importAutomaton passed\033[0m\n");
    }
    
    if (importedAutomaton -> alphabetSize == initialAutomaton -> alphabetSize)
    {
        printf("\033[32mTest 2 - importAutomaton passed\033[0m\n");
    }
    else
    {
        printf("\033[31mTest 2 - importAutomaton failed\033[0m\n");
    }

    if (importedAutomaton -> numberOfStates == initialAutomaton -> numberOfStates)
    {
        printf("\033[32mTest 3 - importAutomaton passed\033[0m\n");
    }
    else
    {
        printf("\033[31mTest 3 - importAutomaton failed\033[0m\n");
    }

    if (importedAutomaton -> initialState == initialAutomaton -> initialState)
    {
        printf("\033[32mTest 4 - importAutomaton passed\033[0m\n");
    }
    else
    {
        printf("\033[31mTest 4 - importAutomaton failed\033[0m\n");
    }

    if (importedAutomaton -> states[0].isFinal == initialAutomaton -> states[0].isFinal)
    {
        printf("\033[32mTest 5 - importAutomaton passed\033[0m\n");
    }
    else
    {
        printf("\033[31mTest 5 - importAutomaton failed\033[0m\n");
    }
    int testCount = 6;
    for (int i = 0; i < importedAutomaton -> numberOfStates; i++)
    {
        for (int j = 0; j < importedAutomaton -> alphabetSize; j++)
        {
            for (int y = 0; y < importedAutomaton->numberOfStates; y++)
            {
                if (importedAutomaton -> transition[i][y][j] == initialAutomaton -> transition[i][y][j])
                {
                    printf("\033[32mTest %d - importAutomaton passed\033[0m\n",testCount);
                }
                else
                {
                    printf("\033[32mTest %d - importAutomaton failed\033[0m\n",testCount);
                }
                testCount++;
            }
            
            
        }
    }

    printf("\033[32mTest importAutomaton passed\033[0m\n");
    deleteAutomaton(importedAutomaton);
    deleteAutomaton(initialAutomaton);
}

void testCreateProductAutomaton(){

}
void testCreateConcatenationAutomaton(){

}
void testCheckWordInAutomaton(){
    printf("\033[32mTest checkWordInAutomaton\033[0m\n");
    char alphabet[2];
    alphabet[0] = 'a';
    alphabet[1] = 'b';
    int nombreEtat = 2 ;

    //Création de l'automate
    FiniteAutomaton *automaton = malloc(sizeof(FiniteAutomaton));
    initAutomaton(automaton, alphabet, nombreEtat,2);
    
    //Ajout d'un état final et d'un état initial
    editState(automaton,0,true,false);
    editState(automaton,1,false,true);

    //Ajout des transitions
    addTransition(automaton,automaton -> states[0],automaton -> states[1],1); // 0 -> 1 b
    addTransition(automaton,automaton -> states[1],automaton -> states[1],1); // 1 -> 1 b
    addTransition(automaton,automaton -> states[1],automaton -> states[1],0); // 1 -> 1 a

    printf("\033[32m------------------------------\033[0m\n");

    if (checkWordInAutomaton(automaton,"b"))
    {
        printf("\033[32mTest 1 - checkWordInAutomaton passed\033[0m\n");
    }
    else
    {
        printf("\033[31mTest 1 - checkWordInAutomaton failed\033[0m\n");
    }
    
    if (!checkWordInAutomaton(automaton,"ab"))
    {
        printf("\033[32mTest 2 - checkWordInAutomaton passed\033[0m\n");
    }
    else
    {
        printf("\033[31mTest 2 - checkWordInAutomaton failed\033[0m\n");
    }
    deleteAutomaton(automaton);
}