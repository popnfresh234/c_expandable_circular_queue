#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int* arr;
  int capacity;
  int head;
  int tail;
  int num_els;
} queue_t;

// create(): creates a new queue
queue_t* queue_create();
// enqueue(item): add an item to the queue
bool queue_enqueue(queue_t* Q, int n);
// dequeue(): remove an item from the queue
int queue_dequeue(queue_t* Q);
// isEmpty():  checks if the stack is queue
bool queue_is_empty(queue_t* Q);
void queue_free(queue_t* Q);
int queue_size(queue_t* Q);