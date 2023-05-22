#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

#ifndef __CQUEUE__

typedef struct _cqueue_ {
} CQueue;

int incCirc(int i, int maxItems);

int decCric(int i, int maxItems);

CQueue *cQueueCreate(int maxItems);

int cEqueue(CQueue *qc, void *elm);

void *cDequeue(CQueue *qc);

int cqIsEmpty(CQueue *qc);

int cqDestroy(CQueue *qc);

void *cqFirst(CQueue *qc);

#endif