#include <stdio.h>
#include <assert.h>

#define size 4

int main(){
    int arr[size] = {0, 1, 2, 3};
    for(int i = 0; i <= size; i++){
        assert(i == arr[i]);
    }
    return 0;
}
