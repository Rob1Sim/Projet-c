#include<stdio.h>
#include<stdlib.h>
#include "StateQueue.h"

/**
 * @brief Create a new queue
 * @return the new queue
 */
StateQueue* createQueue() {
    StateQueue* queue = malloc(sizeof(StateQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
/**
 * @brief Add a state to the queue
 * @param queue : queue to which we want to add a state
 * @param state : state to add
 */
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
/**
 * @brief Remove a state from the queue
 * @param queue : queue from which we want to remove a state
 * @return the state removed
 */
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
/**
 * @brief Check if the queue is empty
 * @param queue : queue to check
 * @return 1 if the queue is empty, 0 otherwise
 */
int isEmpty(StateQueue* queue) {
    return queue->front == NULL;
}