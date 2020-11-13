#include <assert.h>
#include "Vector.h"

int main(){
    struct Vector vec = vectorCreate();
    assert(vec.length == 0);
    assert(vec.capacity == SIZE);

    for(int i = 1; i<50; i++){
      vectorPush(&vec, i);
    }

    for(int i = 1; i<45; i++){
      assert(vectorPop(&vec) == 50-i);
    }

    vectorInsert(&vec, 5, 42);
    assert(vectorAtIndex(&vec, 5) == 42);

    vectorDelete(&vec, 5);
    assert(vectorAtIndex(&vec, 5) == 0);

    assert(vectorAtIndex(&vec, 3) == 4);
    vectorRemove(&vec, 4);
    assert(vectorAtIndex(&vec, 3) == 0);

    vectorPrepend(&vec, 24);
    assert(vectorAtIndex(&vec, 0) == 24);

    assert(vectorFind(&vec, 54) == -1);
    assert(vectorFind(&vec, 2) == 2);

    vectorDecreate(&vec);

    return 0;
}
