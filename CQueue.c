#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

typedef struct _cqueue_ {
  int front, rear;
  int maxItems, numElms;
  void **elms;
} CQueue;

int incCirc(int i, int maxItems) {
  if (i == maxItems - 1) {
    return 0;
  }
  return i + 1;
};

int decCric(int i, int maxItems) {
  if (i == 0) {
    return maxItems - 1;
  }
  return i - 1;
};

CQueue *cQueueCreate(int maxItems) {
  CQueue *cq;
  if (maxItems > 0) {
    cq = (CQueue *)malloc(sizeof(CQueue));
    if (cq != NULL) {
      cq->elms = (void **)malloc(sizeof(void *) * maxItems);
      if (cq->elms) {
        cq->front = 0;
        cq->rear = -1;
        cq->maxItems = maxItems;
        cq->numElms = 0;
        return TRUE;
      }
    }
  }
  return NULL;
};

int cEqueue(CQueue *qc, void *elm) {
  if (qc != NULL && qc->numElms < qc->maxItems) {
    qc->rear = incCirc(qc->rear, qc->maxItems);
    qc->elms[qc->rear] = elm;
    qc->numElms++;
    return TRUE;
  }
  return FALSE;
};

void *cDequeue(CQueue *qc) {
  void *elm;
  if (qc != NULL && qc->numElms > 0) {
    elm = qc->elms[qc->front];
    qc->front = incCirc(qc->front, qc->maxItems);
    qc->numElms--;
    return elm;
  }
  return NULL;
};

int cqIsEmpty(CQueue *qc) {
  if (qc != NULL && qc->numElms == 0) {
    return TRUE;
  }
  return FALSE;
};

int cqDestroy(CQueue *qc) {
  if (qc != NULL && qc->numElms == 0) {
    free(qc->elms);
    free(qc);
    return TRUE;
  }
  return FALSE;
};

void *cqFirst(CQueue *qc) {
  if (qc != NULL && qc->numElms > 0) {
    return qc->elms[qc->front];
  }
  return NULL;
};