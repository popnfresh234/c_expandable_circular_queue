#include "queue.h"

queue_t* queue_create() {
  queue_t* q = malloc(sizeof(queue_t));
  q->arr = calloc(5, sizeof(int));
  q->capacity = 5;
  q->num_els = 0;
  q->head = 0;
  q->tail = 0;
}

void queue_print(queue_t* q) {
  for (int i = 0; i < q->capacity; i++) {
    if (i != q->capacity - 1)
      printf("%d,", q->arr[i]);
    else
      printf("%d", q->arr[i]);
  }
  printf("\n");
}

void queue_dbl_size(queue_t* q) {
  int new_capacity = 2 * q->capacity;
  int* new_buff = calloc(new_capacity, sizeof(int));
  int i = 0;
  while (!queue_is_empty(q)) {
    int next = queue_dequeue(q);
    new_buff[i] = next;
    i++;
  }
  free(q->arr);
  q->capacity = new_capacity;
  q->arr = new_buff;
  q->head = 0;
  q->tail = i;
  q->num_els = i;
}

bool queue_enqueue(queue_t* q, int n) {
  if (q->num_els == q->capacity) {
    printf("Queue full\n");
    queue_dbl_size(q);
  }
  q->arr[q->tail] = n;
  q->num_els++;
  q->tail = (q->tail + 1) % q->capacity;
}

int queue_dequeue(queue_t* q) {
  int next = q->arr[q->head];
  q->num_els--;
  q->head = (q->head + 1) % q->capacity;
  return next;
};

bool queue_is_empty(queue_t* q) { return q->num_els == 0; }

int queue_size(queue_t* q) { return q->num_els; }

void queue_free(queue_t* q) {
  free(q->arr);
  free(q);
}

void main() {
  queue_t* q = queue_create();
  for (int i = 0; i < 21; i++) {
    queue_enqueue(q, i);
  }
  // queue_print(q);
  // printf("Dequeing: %d\n", queue_dequeue(q));
  // queue_enqueue(q, 5);
  // queue_print(q);

  // queue_enqueue(q, 6);
  // queue_enqueue(q, 7);
  // queue_enqueue(q, 8);

  // queue_enqueue(q, 9);

  // queue_enqueue(q, 10);
  // queue_enqueue(q, 11);

  queue_print(q);
  while (!queue_is_empty(q)) {
    printf("Dequeing: %d\n", queue_dequeue(q));
  }
  queue_free(q);
}