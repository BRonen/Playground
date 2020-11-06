#include <stdio.h>

int test(){
    printf("begin of test()\n");
    int a = 1, b = 2, c = 3;
    int i = (a += 3, a + c);
    printf("\ta = %d\tb = %d\tc = %d\ti = %d\n", a, b, c, i);
    printf("end of test()\n");
    return a, b, c, i;
}

void main(){
    int a = 1, b = 0;
    printf("\ta = %d\tb = %d\n", a, b);
    b = test(), a;
    printf("\ta = %d\tb = %d\n", a, b);
    b = 0, a = 1;
    b = (test(), a);
    printf("\ta = %d\tb = %d\n", a, b);
}
