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

// Function to insert an item at the front of the deque
void insertFront(Deque* dq, int data) {
    Node* temp = newNode(data);
    if (dq->front == NULL) {
        dq->front = dq->rear = temp;
        return;
    }
    temp->next = dq->front;
    dq->front->prev = temp;
    dq->front = temp;
}

// Function to insert an item at the rear of the deque
void insertRear(Deque* dq, int data) {
    Node* temp = newNode(data);
    if (dq->rear == NULL) {
        dq->front = dq->rear = temp;
        return;
    }
    temp->prev = dq->rear;
    dq->rear->next = temp;
    dq->rear = temp;
}

// Function to delete an item from the front of the deque
int deleteFront(Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

// Function to delete an item from the rear of the deque
int deleteRear(Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

int main() {
    Deque* dq = createDeque();
    insertFront(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);
    insertRear(dq, 30);

    printf("Deleted from front: %d\n", deleteFront(dq));
    printf("Deleted from rear: %d\n", deleteRear(dq));
    printf("Deleted from front: %d\n", deleteFront(dq));
    printf("Deleted from rear: %d\n", deleteRear(dq));

    return 0;
}
