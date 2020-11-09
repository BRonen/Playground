#include <stdio.h>
#include <assert.h>

int test(){
    int a = 1, b = 2, c = 3;
    int d = (a += 3, a + c);
    assert(d == 7);
    return a, b, c, d;
}

void main(){
    int a = 1, b = 0;

    b = test(), a;
    assert(b == test());

    a = 1, b = 0;

    b = (test(), a);
    assert(b == a);
}
