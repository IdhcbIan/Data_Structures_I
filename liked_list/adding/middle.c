#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

// Function to add a new node with a given value to the end of the list
void add_to_middle(Node* root, int value, int index) {
    // 2. Traverse to the end of the list
    int i = 0;
    while (i<index) {
        root = root->next;
        i++;
    }

    // 3. Append the new node to the end
    root->x = value;
}

int main() {
    Node* root = malloc(sizeof(Node));   // Allocate memory for root
    root->x = 1;
    root->next = malloc(sizeof(Node));
    root->next->x = 2;
    root->next->next = NULL;

    // Add a new element to the end
    add_to_middle(root, 4, 1);

    Node* elem = root; 
    while (elem != NULL) {
        printf("The element is: %d\n", elem->x);
        elem = elem->next;
    }

    return 0;
}
