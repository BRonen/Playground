#include <assert.h>
#include "Queue.h"


void main() {
  //tests of queue made with a linked list
  struct Queue queue = queueCreate();
  
  assert(queueIsEmpty(&queue) == 1);
  
  queuePush(&queue, 43);
  queuePush(&queue, 43);
  queuePush(&queue, 43);
  
  assert(queueIsEmpty(&queue) == 0);
  
  assert(queuePull(&queue) == 43);
  assert(queuePull(&queue) == 43);
  assert(queuePull(&queue) == 43);
  
  assert(queueIsEmpty(&queue) == 1);
}
