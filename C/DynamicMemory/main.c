#include <stdlib.h>
#include <assert.h>

#define size 5

int main(){
    int* ptr;

    ptr = malloc(size * sizeof(int));

    assert(!(ptr == NULL));

    int i;o
    for (i = 0; i < size; i++) {
      *ptr = i;
      ptr++;
    }

    ptr -= i;

    for (i = 0; i < size; i++) {
      assert(*ptr == i);
      ptr++;
    }

    return 0;
}
