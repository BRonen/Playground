#include <stdio.h>
#include <assert.h>

int main(){
	int a = 2147483647;
    assert(a == 2147483647);
	assert(++a == -2147483648);

    a = 4294967295;
	assert(a == -1);
	assert(++a == 0);

    return 0
}
