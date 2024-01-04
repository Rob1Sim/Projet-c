#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "State.h"
#include "FiniteAutomaton.h"

int main() {
    
    executeTest();

    void automatonMenu(FiniteAutomaton *automaton){
        bool isContinue2 = true;

        do
        {
            int choice2;
            printf("---------------------------------------------\n");
            printf("\033[1;34mMenu\033[0m\n");
            printf("Enter the number :\n");
            printf("    1: Display automaton \n");
            printf("    2: Export Automaton \n");
            printf("    3: Check word in automaton \n");
            printf("    4: Is complete ? \n");
            printf("    5: Is deterministic ? \n");
            printf("    6: Turn into complete \n");
            printf("    7: Turn into deterministic \n");
            printf("    8: Create mirror automaton \n");
            printf("    9: Create complement automaton \n");
            printf("    10: Create product automaton \n");
            printf("    11: Create concatenation automaton \n");
            printf("\033[31m    12: Quit \033[0m\n");
            printf("---------------------------------------------\n");

            scanf("%d", &choice2);

            switch (choice2)
            {
                case 1:
                    displayAutomaton(automaton);
                    break;
                case 2:
                    bool isDataValid = false;
                    do {
                        char filename[100];
                        printf("Enter the name of the file : \n");
                        scanf("%99s", filename);
                        if (filename == NULL)
                        {
                            printf("Invalid filename.\n");
                        }else{
                            isDataValid = true;
                            exportAutomaton(automaton, filename);
                            printf("\033[32mThe automaton has been exported in out/%s.\033[0m\n",filename);
                        }
                    } while (!isDataValid);
                    break;
                case 3:
                    char word[100];
                    printf("Check word in automaton : \n");
                    printf("Enter the word : \n");
                    scanf("%99s", word);
                    if (checkWordInAutomaton(automaton, word))
                    {
                        printf("\033[32mThe word is in the automaton.\033[0m\n");
                    }
                    else
                    {
                        printf("\033[32mThe word is not in the automaton.\033[0m\n");
                    }
                    break;
                case 4:
                    if (isComplete(automaton))
                    {
                        printf("\033[32mThe automaton is complete.\033[0m\n");
                    }
                    else
                    {
                        printf("\033[32mThe automaton is not complete.\033[0m\n");
                    }
                    break;
                case 5:
                    if (isDeterministic(automaton))
                    {
                        printf("\033[32mThe automaton is deterministic.\033[0m\n");
                    }
                    else
                    {
                        printf("\033[32mThe automaton is not deterministic.\033[0m\n");
                    }
                    break;
                case 6:
                    turnIntoComplete(automaton);
                    printf("\033[32mThe automaton has been turned into complete.\033[0m\n");
                    break;
                case 7:
                    printf("\033[31mThis function is not available yet.\033[0m\n");
                    //turnIntoDeterministic(automaton);
                    break;
                case 8:
                    printf("\033[31mThis function is not available yet.\033[0m\n");
                    //createMirrorAutomaton(automaton);
                    break;
                case 9:
                    printf("\033[31mThis function is not available yet.\033[0m\n");
                    //createComplementAutomaton(automaton);
                    break;
                case 10:
                    printf("\033[31mThis function is not available yet.\033[0m\n");
                /*
                    FiniteAutomaton *automaton2;
                    printf("Create product automaton : \n");
                    printf("Enter the location of the second automaton : \n");
                    scanf("%s", location);
                    importAutomaton(automaton2, location);
                    createProductAutomaton(automaton, automaton2);*/
                    break;
                case 11:
                    printf("\033[31mThis function is not available yet.\033[0m\n");
                    /*
                    FiniteAutomaton *automaton2;
                    printf("Create concatenation automaton : \n");
                    printf("Enter the location of the second automaton : \n");
                    scanf("%s", location);
                    importAutomaton(automaton2, location);
                    createConcatenationAutomaton(automaton, automaton2);
                    */
                    break;
                case 12:
                    isContinue2 = false;
                    deleteAutomaton(automaton);
                    exit(0);
                    break;
                default:
                    printf("\033[31mInvalid choice.\033[0m\n");
            }
        } while (isContinue2);
        

    }

    void createAutomaton(){
        // Variables
        char *alphabet;
        int numberOfStates;
        int alphabetSize;
        int initialState;
        int numberOfFinalStates;
        int numberOfTransitions;
        FiniteAutomaton *automaton = malloc(sizeof(FiniteAutomaton));
        
        // Build the automaton
        printf("---------------------------------------------\n");
        printf("Create automaton : \n");
        printf("   Enter the size of the alphabet : \n");
        scanf("%d", &alphabetSize);
        printf("   Enter the alphabet : \n");
        scanf("%s", alphabet);
        printf("   Enter the number of states : \n");
        scanf("%d", &numberOfStates);
        initAutomaton(automaton, alphabet, numberOfStates, alphabetSize);

        // Add the initial state
        bool isDataValid = false;
        do
        {
            printf("   Enter the initial state : \n");
            scanf("%d", &initialState);
            if (initialState > numberOfStates)
            {
                printf("Invalid initial state.\n");
            }
            else
            {
                isDataValid = true;
            }
        } while (!isDataValid);
        editState(automaton, initialState, true, false);

        isDataValid = false;
        do
        {
            printf("   Enter the number of final states : \n");
            scanf("%d", &numberOfFinalStates);
            if (numberOfFinalStates > numberOfStates)
            {
                printf("Invalid number of final states.\n");
            }
            else
            {
                isDataValid = true;
            }
        } while (!isDataValid);

        for (int i = 0; i < numberOfFinalStates; i++)
        {
            int finalState;
            printf("   Enter the final state : \n");
            scanf("%d", &finalState);
            editState(automaton, finalState, false, true);
        }

        // Add the transitions
        isDataValid = false;
        do{
            printf("   Enter the number of transitions : \n");
            scanf("%d", &numberOfTransitions);
            if (numberOfTransitions > numberOfStates)
            {
                printf("Invalid number of transitions.\n");
            }
            else
            {
                isDataValid = true;
            }
        } while (!isDataValid);


        for (int i = 0; i < numberOfTransitions; i++)
        {
            int startState;
            int endState;
            int letter;
            bool isDataValid2 = false;
            do{
                printf("   Enter the start state : \n");
                scanf("%d", &startState);
                if (startState > numberOfStates)
                {
                    printf("Invalid start state.\n");
                }
                else
                {
                    isDataValid2 = true;
                }
            } while (!isDataValid2);

            isDataValid2 = false;
            do{
                printf("   Enter the ending state : \n");
                scanf("%d", &endState);
                if (endState > numberOfStates)
                {
                    printf("Invalid ending state.\n");
                }
                else
                {
                    isDataValid2 = true;
                }
            } while (!isDataValid2);

            isDataValid2 = false;
            do{
                printf("   Enter the letter (number in the alphabet) : \n");
                scanf("%d", &letter);
                if (letter > alphabetSize)
                {
                    printf("Invalid letter.\n");
                }
                else
                {
                    isDataValid2 = true;
                }
            } while (!isDataValid2);

            addTransition(automaton, automaton->states[startState], automaton->states[endState], letter);
        }
        printf("\033[32mThe automaton has been created.\033[0m\n");

        automatonMenu(automaton);

    }

    int choice;
    bool isContinue = true;
    while (isContinue)
    {
        printf("\033[1;34m");  // Set text color to blue

        printf("   .--.");
        printf("\n");
        printf("  |o_o |");
        printf("\n");
        printf("  |:_/ |");
        printf("\n");
        printf(" //   \\ \\");
        printf("\n");
        printf("(\\_\\ _/ )");
        printf("\n");
        printf(" \\_/_\\_/ ");
        printf("\n");

        printf("\033[0m");  // Reset text color
        printf("---------------------------------------------\n");
        printf("\033[1;34mMenu\033[0m\n");

        printf("Enter the number :\n");
        printf("    1: Create automaton \n");
        printf("    2: Import Automaton \n");
        printf("\033[31m    3: Quit \033[0m\n");
        printf("---------------------------------------------\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAutomaton();
                break;

            case 2:
                char location[100];
                printf("Import automaton : \n");
                printf("Enter the location of the file : \n");
                scanf("%99s", location);
                FiniteAutomaton *automaton = malloc(sizeof(FiniteAutomaton));
                importAutomaton(automaton, location);
                automatonMenu(automaton);
                break;
            case 3:
                isContinue = false;
                break;


            default:
                printf("\033[31mInvalid choice.\033[0m\n");
        }
    }

    return 0;
}
