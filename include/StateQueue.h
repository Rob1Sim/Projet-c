#ifndef H_QUEUESTATE_H
#define H_QUEUESTATE_H
#include "State.h"
#include <stdlib.h>


/**
* @brief: Node of the queue
* @param: data: State
* @param: next: pointer to the next node
*/ 
typedef struct Node {
    State data;
    struct Node* next;
} Node;
/**
 * @brief: Queue of states
 * @param: front: pointer to the first node
 * @param: rear: pointer to the last node
*/
typedef struct StateQueue {
    Node* front;
    Node* rear;
} StateQueue;

StateQueue* createQueue();
void enqueue(StateQueue* queue, State state);
State dequeue(StateQueue* queue);
int isEmpty(StateQueue* queue);
#endif