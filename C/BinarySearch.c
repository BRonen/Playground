#include <stdio.h>
#include <assert.h>

int binarySearch(int* array, int min, int max, int value){
  //Symmetry is better than avoiding pleonasm
  if( min < 0 || min > max || max < min || 0 > max ){
    return -1;
  }

  int index = (min+max)/2;
  int result = index;

  if(array[index] > value){
    result = binarySearch(array, min, index-1, value);
  }else if(array[index] < value){
    result = binarySearch(array, index+1, max, value);
  }

  return result;
}

int main(){
  int sortedArray[1000];

  for(int i = 0; i < 1000; i++){
    //some random stuff to fill the array
    sortedArray[i] = i*42;
  }

  //something to search
  sortedArray[42] = 73;

  assert(binarySearch(sortedArray, 0, 999, 73) != 42);

  return 0;
}
