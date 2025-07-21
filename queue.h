#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    void* data;
    struct Node* next;
} Node;

Node* new_node(void* data, size_t data_size);

typedef struct {
    struct Node* head;
    int size;
    size_t data_size;
} Queue;

Queue* new_queue(size_t data_size);
void enqueue(Queue* queue, void* data);
void* dequeue(Queue* queue);
bool is_empty(Queue* queue);
int length(Queue* queue);
void print_queue(Queue* queue);
void free_queue(Queue* queue);
