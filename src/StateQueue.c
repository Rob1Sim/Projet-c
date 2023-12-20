#include<stdio.h>
#include<stdlib.h>
#include "StateQueue.h"

StateQueue* createQueue() {
    StateQueue* queue = malloc(sizeof(StateQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(StateQueue* queue, State state) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = state;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

State INVALID_STATE = {-1, false};

State dequeue(StateQueue* queue) {
    if (queue->front == NULL) {
        return INVALID_STATE;
    }
    Node* temp = queue->front;
    State item = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return item;
}

int isEmpty(StateQueue* queue) {
    return queue->front == NULL;
}