#include "linkedlist.h"

#include <stdio.h>

void insert_at_front(LinkedList* list, int value) {
    Node* node = new_node(value);
    Node* next = list->head->next;
    node->next = next;
    list->head->next = node;
    list->size++;
}

// void insert_at_end(LinkedList* list, int value);
// void insert(LinkedList* list, int value, int index);
// void delete(LinkedList* list, int index);

int length(LinkedList* list) { return list->size; }

void print_list(LinkedList* list) {
    Node* curr = list->head->next;
    while (curr != NULL) {
        printf("%d->", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void free_list(LinkedList* list) {
    Node* curr = list->head;
    Node* next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    free(list);
}

int main(void) {
    LinkedList* list = new_linked_list();
    insert_at_front(list, 12);
    insert_at_front(list, 13);
    print_list(list);
    printf("length: %d\n", length(list));
    free(list);
}
