#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Vector{
  int* data;
  int lenght;
  int capacity;
  int* ptr;
};

struct Vector vectorCreate(){
  struct Vector vec;
  vec.data     = malloc(SIZE*sizeof(int));
  vec.ptr      = vec.data;
  vec.capacity = SIZE;
  vec.lenght   = 0;
  return vec;
}

void vectorDecreate(struct Vector* vec){
  free(vec->data);
}

void vectorPush(struct Vector* vec, int value){
  if(vec->lenght == vec->capacity){
    vec->capacity += 10;
    vec->data = (int*)realloc(
      vec->data, vec->capacity*sizeof(int)
    );
  }

  *vec->ptr = value;
  vec->ptr++;
  vec->lenght++;
}


int vectorPop(struct Vector* vec){
  vec->ptr--;
  int value = *vec->ptr;
  *vec->ptr = 0;
  vec->lenght--;

  return value;

}
