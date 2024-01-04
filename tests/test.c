#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void executeTest(){
    testIsDeterminitic();
    testCreateAutomaton();
    testAddState();
    testTurnIntoComplete();
    //testTurnIntoDeterministic();
    testCreateMirrorAutomaton();
    testCreateComplementAutomaton();
    testIsComplete();
    testExportAutomaton();
    testImportAutomaton();
    //testCreateProductAutomaton();
    //testCreateMirrorAutomaton();
    //testCreateComplementAutomaton();
    //testCreateConcatenationAutomaton();
    testCheckWordInAutomaton();
}