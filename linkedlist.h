#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* newNode(int value) {}

typedef struct LinkedList {
    struct Node* head;
} LinkedList;

LinkedList* newLinkedList();
