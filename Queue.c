#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

typedef struct _queue_ {
  int front, rear;
  int maxItems;
  void **items;
} Queue;

Queue *qCreate(int maxItems) {
  Queue *q;
  if (maxItems > 0) {
    q = (Queue *)malloc(sizeof(Queue));
    if (q != NULL) {
      q->items = (void **)malloc(sizeof(void *) * maxItems);
      if (q->items != NULL) {
        q->maxItems = maxItems;
        q->front = 0;
        q->rear = -1;

        return q;
      }
    }
    free(q);
  }
  return NULL;
};

int qDestroy(Queue *q) {
  if (q != NULL && q->rear < 0) {
    free(q->items);
    free(q);
    return TRUE;
  }
  return FALSE;
};

Queue *qFirst(Queue *q) {
  if (q != NULL && q->rear >= 0) {
    return q->items[q->front];
  }
  return NULL;
};

int qIsEmpty(Queue *q) {
  if (q != NULL && q->rear < 0) {
    return TRUE;
  }
  return FALSE;
};

int qEnqueue(Queue *q, void *data) {
  if (q != NULL && q->rear < q->maxItems - 1) {
    q->rear++;
    q->items[q->rear] = data;
    return TRUE;
  }
  return FALSE;
};

void *qDequeue(Queue *q) {
  void *excItem;
  int cur, next;
  if (q != NULL && q->rear >= 0) {
    excItem = q->items[q->front];
    for (int i = 0; i < q->rear - 1; i++) {
      cur = i;
      next = i++;
      q->items[cur] = q->items[next];
    }
    q->rear--;
    return excItem;
  }
  return NULL;
};
