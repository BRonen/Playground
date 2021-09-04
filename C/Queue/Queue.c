#include <assert.h>
#include "QueueLL.h"
#include "QueueAL.h"


int main() {
    //tests of queue made with a linked list
    struct QueueLL queueLL = queueLLCreate();
    
    assert(queueLLIsEmpty(&queueLL) == 1);
    
    queueLLPush(&queueLL, 43);
    queueLLPush(&queueLL, 43);
    queueLLPush(&queueLL, 43);
    
    assert(queueLLIsEmpty(&queueLL) == 0);
    
    assert(queueLLPull(&queueLL) == 43);
    assert(queueLLPull(&queueLL) == 43);
    assert(queueLLPull(&queueLL) == 43);
    
    assert(queueLLIsEmpty(&queueLL) == 1);
  
    //tests of queue made with a array list
    struct QueueAL queueAL = queueALCreate(10);
    
    assert(queueALIsEmpty(&queueAL) == 1);
    
    for(int i = 10; i <= 90; i++){
      queueALPush(&queueAL, i*i);
    }
    
    assert(queueALIsEmpty(&queueAL) == 0);
    
    for(int i = 10; i <= 90; i++){
      if(!queueALIsEmpty(&queueAL)){
        assert(queueALPull(&queueAL) == i*i);
      }
    }
    
    assert(queueALIsEmpty(&queueAL) == 1);
  return 0;
}
