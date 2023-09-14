#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Define the Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

// Function to create an empty deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

int main() {
      Deque* dq = createDeque();

    return 0;
}
