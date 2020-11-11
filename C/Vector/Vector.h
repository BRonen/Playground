#include <stdlib.h>
#include <assert.h>

#define SIZE 5

struct Vector{
    int* data;
    int lenght;
    int capacity;
};

struct Vector vectorCreate(){
    struct Vector vec;
    vec.data = malloc(SIZE*sizeof(int));
    vec.capacity = SIZE;
    vec.lenght = 0;
    return vec;
}
