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

    return 0;
}
