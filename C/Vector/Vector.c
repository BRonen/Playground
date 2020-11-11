#include <stdlib.h>
#include <assert.h>
#include "Vector.h"

int main(){
    struct Vector vec = vectorCreate();
    assert(vec.lenght == 0);
    assert(vec.capacity == SIZE);
    for(int i = 0; i<SIZE; ++i){
      assert(*vec.data == 0);
      vec.data++;
    }

    return 0;
}
