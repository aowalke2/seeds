#include "queue.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* new_node(void* data, size_t data_size) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = malloc(data_size);
    if (!node->data) {
        free(node);
        printf("Memory allocation failed\n");
        exit(1);
    }

    memcpy(node->data, data, data_size);
    node->next = NULL;
    return node;
}

Queue* new_queue(size_t data_size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    queue->head = NULL;
    queue->size = 0;
    queue->data_size = data_size;
    return queue;
}

void enqueue(Queue* queue, void* data) {
    Node* node = new_node(data, queue->data_size);
    if (queue->head == NULL) {
        queue->head = node;
    } else {
        Node* curr = queue->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
    queue->size++;
}

void* dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return NULL;
    }

    Node* node = queue->head;
    queue->head = node->next;
    queue->size--;

    void* data = node->data;
    node->next = NULL;
    free(node);
    return data;
}

bool is_empty(Queue* queue) { return queue->size == 0; }

int length(Queue* queue) { return queue->size; }

void print_queue(Queue* queue) {
    Node* curr = queue->head;

    while (curr != NULL) {
        printf("%d->", *(int*)curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void free_queue(Queue* queue) {
    Node* curr = queue->head;
    Node* next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    queue->head = NULL;
    free(queue);
}

int main(void) {
    Queue* queue = new_queue(sizeof(int));
    int value1 = 12;
    enqueue(queue, &value1);

    int value2 = 13;
    enqueue(queue, &value2);

    int value3 = 5;
    enqueue(queue, &value3);

    int value4 = 7;
    enqueue(queue, &value4);

    print_queue(queue);
    printf("length: %d\n\n", length(queue));

    void* data = dequeue(queue);
    int value = *(int*)data;
    printf("dequeue: %d\n", value);

    print_queue(queue);
    printf("length: %d\n", length(queue));
    free(queue);
}
