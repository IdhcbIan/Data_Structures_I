#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

int main() {
    Node* root = malloc(sizeof(Node));   // Allocate memory for root
    root->x = 1;
    root->next = malloc(sizeof(Node));
    root->next->x = 2;
    root->next->next = NULL;

    Node* elem = root; 
    while (elem != NULL) {
        printf("The element is: %d\n", elem->x);
        elem = elem->next;
    }


    // Note how we can use a while loop with the same
    // condition to iterate over the list and free up the memory
    Node* temp = NULL;
    while (root != NULL) {
        temp = root->next;
        free(root);
        root = temp;
    }
 
    return 0;
}
