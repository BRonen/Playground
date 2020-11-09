#include <assert.h>

#define size 4

int main(){
    int arr[size] = {0, 1, 2, 3};
    int* ptr = arr;
    assert(*ptr == arr[0]);

    for(int i = 0; i <= size; i++){
        assert(i == *ptr);
	ptr++;
    }

    return 0;
}
