/* Queue implemented with fixed size arrays */

#include <stdio.h>
#include <stdlib.h>

struct QueueAL{
  int* buffer;
  int length;
  int* head;
  int* tail;
};

struct QueueAL queueALCreate(int size){
  struct QueueAL queueAL;
  queueAL.buffer = malloc(sizeof(int)*size);
  queueAL.length = size;
  queueAL.head = queueAL.tail = queueAL.buffer;
  
  return queueAL;
}

int queueALIsEmpty(struct QueueAL *queueAL){
  if(queueAL->head == queueAL->tail)
    return 1;
  else
    return 0;
}

int queueALIsFull(struct QueueAL *queueAL){
  int* head = queueAL->head + 1;
  if(head > &(queueAL->buffer[queueAL->length])){
    head = queueAL->buffer;
  }
  if(head == queueAL->tail)
    return 1;
  else
    return 0;
}

int queueALPush(struct QueueAL *queueAL, int data){
  if( queueALIsFull(queueAL) ){
    return 1;
  }
  *(queueAL->head) = data;
  queueAL->head++;
  if(queueAL->head > &(queueAL->buffer[queueAL->length])){
    queueAL->head = queueAL->buffer;
  }
  return 0;
}

int queueALPull(struct QueueAL *queueAL){
  int data = *queueAL->tail;
  *queueAL->tail = 0;
  queueAL->tail++;
  return data;
}

void queueALPrint(struct QueueAL *queueAL){
  printf("\n\nindex final: %d\n", queueAL->length - 1);
  for(int i = 0; i < queueAL->length; i++){
    printf("[%d] => %d\n", i, queueAL->buffer[i]);
  }
}