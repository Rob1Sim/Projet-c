#ifndef H_QUEUESTATE_H
#define H_QUEUESTATE_H
#include "State.h"
#include <stdlib.h>


typedef struct Node {
    State data;
    struct Node* next;
} Node;

typedef struct StateQueue {
    Node* front;
    Node* rear;
} StateQueue;

StateQueue* createQueue();
void enqueue(StateQueue* queue, State state);
State dequeue(StateQueue* queue);
int isEmpty(StateQueue* queue);
#endif