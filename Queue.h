#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

#ifndef __QUEUE__

typedef struct _queue_ {
} Queue;

Queue *qCreate(int maxItems);

int qDestroy(Queue *q);

Queue *qFirst(Queue *q);

int qIsEmpty(Queue *q);

int qEnqueue(Queue *q, void *data);

void *qDequeue(Queue *q);

#endif