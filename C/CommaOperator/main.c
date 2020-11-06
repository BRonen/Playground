#include <stdio.h>

int test(){
    printf("test()\n");
    return 42;
}

void main(){
    int a = 1, b = 0;
    printf("a = %d\tb = %d\n", a, b);
    b = test(), a;
    printf("a = %d\tb = %d\n", a, b);
    b = 0, a = 1;
    b = (test(), a);
    printf("a = %d\tb = %d\n", a, b);
}
