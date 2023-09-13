#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Function to push an item onto the stack
void push(Stack* s, int data) {
    Node* temp = newNode(data);
    temp->next = s->top;
    s->top = temp;
}

// Function to pop an item from the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }

    Node* temp = s->top;
    s->top = s->top->next;

    int data = temp->data;
    free(temp);
    return data;
}

// Function to peek (view) the top item without popping
int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data;
}

int main() {
    Stack* s = createStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top of the stack: %d\n", peek(s));
    printf("Popped item: %d\n", pop(s));
    printf("Top of the stack: %d\n", peek(s));
    
    push(s, 40);
    
    printf("Popped item: %d\n", pop(s));
    printf("Popped item: %d\n", pop(s));
    printf("Popped item: %d\n", pop(s));

    return 0;
}
