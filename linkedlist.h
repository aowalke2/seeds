#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* new_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed\n");
    }

    node->value = value;
    node->next = NULL;
    return node;
}

typedef struct LinkedList {
    struct Node* head;
    int size;
} LinkedList;

LinkedList* new_linked_list() {
    LinkedList* list = {new_node(-1), 0};
    return list;
}
