#include <stdlib.h>

#define SIZE 4

struct Vector{
  int* data;
  int length;
  int capacity;
  int* ptr;
};

struct Vector vectorCreate(){
  struct Vector vec;
  vec.data     = malloc(SIZE*sizeof(int));
  vec.ptr      = vec.data;
  vec.capacity = SIZE;
  vec.length   = 0;
  return vec;
}

int vectorSize(struct Vector* vec){
  return vec->length;
}

int vectorCapacity(struct Vector* vec){
  return vec->capacity;
}

int vectorIsEmpty(struct Vector* vec){
  return vec->length == 0;
}

int vectorAtIndex(struct Vector* vec, int index){
  return vec->data[index];
}

void vectorResize(struct Vector* vec, int size){
  vec->capacity = size;
  vec->data = (int*)realloc(
    vec->data, vec->capacity*sizeof(int)
  );
  vec->ptr = vec->data;
  vec->ptr += vec->length;
}

void vectorDecreate(struct Vector* vec){
  free(vec->data);
}

void vectorPush(struct Vector* vec, int value){
  if(vec->length == vec->capacity){
    vectorResize(vec, vec->capacity*2);
  }

  *vec->ptr = value;
  vec->ptr++;
  vec->length++;
}

int vectorPop(struct Vector* vec){
  vec->ptr--;
  int value = *vec->ptr;
  *vec->ptr = 0;
  vec->length--;
  if(vec->length <= vec->capacity/4){
    vectorResize(vec, vec->capacity/2);
  }
  return value;
}

void vectorDelete(struct Vector* vec, int index){
  for(int i = index; i < vec->capacity-1; i++){
    vec->data[i] = vec->data[i+1];
  }
  vectorPop(vec);
}

void vectorInsert(struct Vector* vec, int index, int value){
  int tmp = vec->data[vec->length-1];
  for(int i = vec->length; i > index; --i){
    if(vec->length >= vec->capacity){
      vectorResize(vec, vec->capacity/2);
    }
    vec->data[i] = vec->data[i-1];
  }
  vec->data[index] = value;
}

void vectorPrepend(struct Vector* vec, int value){
  vectorInsert(vec, 0, value);
}

int vectorFind(struct Vector* vec, int value){
  for(int i = 1; i < vec->length; i++){
    if(vectorAtIndex(vec, i) == value){
      return i;
    }
  }
  return -1;
}

void vectorRemove(struct Vector* vec, int value){
  for(int i = 1; i < vec->length; i++){
    if(vectorAtIndex(vec, i) == value){
      vectorDelete(vec, i);
    }
  }
}
