#include <assert.h>
#include "Vector.h"

int main(){
    struct Vector vec = vectorCreate();
    assert(vec.lenght == 0);
    assert(vec.capacity == SIZE);

    for(int i = 5; i<100; i+=10){
      vectorPush(&vec, i);
      assert(vectorPop(&vec) == i);
    }

    vectorDecreate(&vec);

    return 0;
}
