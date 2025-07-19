#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* new_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(1);
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
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    list->head = new_node(-1);
    list->size = 0;
    return list;
}

void insert_at_front(LinkedList* list, int value);
void insert_at_end(LinkedList* list, int value);
void insert(LinkedList* list, int value, int index);
void delete(LinkedList* list, int index);
int length(LinkedList* list);
void print_list(LinkedList* list);
void free_list(LinkedList* list);
