#include "linkedlist.h"

#include <stdio.h>

void insert_at_front(LinkedList* list, int value) {
    Node* node = new_node(value);
    Node* next = list->head->next;
    node->next = next;
    list->head->next = node;
    list->size++;
}

void insert_at_end(LinkedList* list, int value) {
    Node* curr = list->head->next;
    Node* prev = list->head;
    while (curr != NULL) {
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = new_node(value);
    list->size++;
}

void insert(LinkedList* list, int value, int index) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }

    if (index == list->size) {
        insert_at_end(list, value);
        return;
    }

    Node* curr = list->head->next;
    Node* prev = list->head;
    int count = 0;
    while (count < index) {
        count++;
        prev = prev->next;
        curr = curr->next;
    }

    Node* node = new_node(value);
    prev->next = node;
    node->next = curr;
    list->size++;
}

void delete(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }

    Node* curr = list->head->next;
    Node* prev = list->head;
    int count = 0;
    while (count < index) {
        count++;
        prev = prev->next;
        curr = curr->next;
    }

    prev->next = curr->next;
    free(curr);
    list->size--;
}

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
    insert_at_end(list, 5);
    insert_at_end(list, 7);
    insert(list, 35, 2);
    insert(list, 55, 0);
    insert(list, 20, list->size);
    print_list(list);
    printf("length: %d\n", length(list));

    delete(list, 2);
    print_list(list);
    printf("length: %d\n", length(list));
    free(list);
}
