#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = value;
    newNode->next = NULL;
    return newNode;
}

void add_to_end(Node** root, int value) {
    if (!(*root)) {
        *root = create_node(value);
        return;
    }

    Node* temp = *root;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = create_node(value);
}

void display_list(Node* root) {
    while (root) {
        printf("The element is: %d\n", root->x);
        root = root->next;
    }
}

void free_list(Node* root) {
    Node* temp;
    while (root) {
        temp = root;
        root = root->next;
        free(temp);
    }
}

int main() {
    Node* root = NULL;   // Start with an empty list

    add_to_end(&root, 1);
    add_to_end(&root, 2);
    add_to_end(&root, 3);

    display_list(root);

    free_list(root);

    return 0;
}
