#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

// Function to add a new node with a given value to the end of the list
void add_to_end(Node* root, int value) {
    // 1. Create a new node
    Node* newNode = malloc(sizeof(Node));
    newNode->x = value;
    newNode->next = NULL;

    // 2. Traverse to the end of the list
    while (root->next != NULL) {
        root = root->next;
    }

    // 3. Append the new node to the end
    root->next = newNode;
}

int main() {
    Node* root = malloc(sizeof(Node));   // Allocate memory for root
    root->x = 1;
    root->next = malloc(sizeof(Node));
    root->next->x = 2;
    root->next->next = NULL;

    // Add a new element to the end
    add_to_end(root, 3);

    Node* elem = root; 
    while (elem != NULL) {
        printf("The element is: %d\n", elem->x);
        elem = elem->next;
    }

    return 0;
}
