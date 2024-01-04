#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "FiniteAutomaton.h"
#include "Equation.h"
#include "State.h"
#include "EquationSystem.h"

/**
 * @brief: Initialize an equation
 * @param: eq: pointer to the equation
 * @param: nbOfState: number of states
 * @param: alphabetSize: size of the alphabet
*/
void InitEquation(Equation *eq, int nbOfState, int alphabetSize) {
  eq->coefficients = malloc(nbOfState * sizeof(char *));
  for (int i = 0; i < nbOfState; i++) {
    eq->coefficients[i] = malloc(alphabetSize * sizeof(char));
    eq->hasConstant = false;
    for (int j = 0; j < alphabetSize; j++) {
    eq->coefficients[i][j] = ' ';
    }
  }
}
 
 /**
  * @brief: Generate the system of equations
  * @param: automaton: pointer to the automaton
  * @param: System: pointer to the system of equations
 */
void generateEquations(FiniteAutomaton *automaton, EquationSystem *System) {
  printf("Systeme d'equations :\n");
  int nbOfState = automaton->numberOfStates;
  System->equations = malloc(nbOfState * sizeof(Equation));
  for (int i = 0; i < nbOfState; i++) {
    Equation eq;
    InitEquation(&eq, nbOfState, automaton->alphabetSize);
    bool empty = true;
    for (int j = 0; j < nbOfState; j++) {
      for (int k = 0; k < automaton->alphabetSize; k++) {
        if (automaton->transition[i][j][k] == 1) {
          eq.coefficients[j][k] = automaton->alphabet[k];
          empty = false;
        }
      }
    }
    if (empty) {
      eq.constant = 'e';
      eq.hasConstant = true;
    };
    if (automaton->states[i].isFinal) {
      eq.constant = 'e';
      eq.hasConstant = true;
    }
    printEquation(&eq, i, nbOfState, automaton->alphabetSize);
    printf("\n");
  }
}

/**
 * @brief: Print an equation
 * @param: eq: pointer to the equation
 * @param: i: index of the equation
 * @param: nbOfStates: number of states
*/
void printEquation(Equation *eq, int i, int nbOfStates, int alphabetSize) {
  printf("Y%d = ", i + 1);
  bool empty = true;
  for (int i = 0; i < nbOfStates; i++) {
    for (int j = 0; j < alphabetSize; j++) {
        if (eq->coefficients[i][j] != ' ') {
        if (!empty)
          printf(" + ");
        empty = false;
        printf("%c.Y%d", eq->coefficients[i][j], i + 1);
      }
    }
  }
  if (eq->hasConstant) {
    if (!empty){
        printf(" + ");
    }
    printf("e");
  }
  printf("\n");
}

/**
 * @brief: Solve the system of equations
 * @param: system: pointer to the system of equations
 * @param: size: size of the system
*/
void solveEquationSystem(EquationSystem *system, int size) {

    for (int i = 0; i < size; ++i) {

        int pivotRow = i;
 
        for (int j = i + 1; j < size; ++j) {

            if (system->equations[j].coefficients[i][i] != ' ') {

                pivotRow = j;

                break;

            }

        }
 
        if (pivotRow != i) {

            Equation temp = system->equations[i];

            system->equations[i] = system->equations[pivotRow];

            system->equations[pivotRow] = temp;

        }
 
        for (int j = i + 1; j < size; ++j) {

            char factor = system->equations[j].coefficients[i][i] / system->equations[i].coefficients[i][i];
 
            for (int k = i; k < size; ++k) {

                system->equations[j].coefficients[i][k] -= (factor * system->equations[i].coefficients[i][k]);

            }

        }

    }
 
    printf("Système après élimination de Gauss :\n");

    for (int i = 0; i < size; ++i) {

        printEquation(&(system->equations[i]), i, size, size);

    }
 
    printf("Résultats :\n");

    for (int i = size - 1; i >= 0; --i) {

        char result = system->equations[i].constant;

        for (int j = i + 1; j < size; ++j) {

            result -= (system->equations[i].coefficients[i][j] * system->equations[j].constant);

        }

        result /= system->equations[i].coefficients[i][i];

        printf("Y%d = %c\n", i + 1, result);

    }

}