#include <stdio.h>
#include <stdlib.h>

// Defining Node strcture
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Defining the queue data strucure
//that is a collection of nodes
//
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int main() {
    Queue* q = createQueue();
    
    return 0;
}
