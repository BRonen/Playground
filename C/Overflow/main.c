#include <stdio.h>

void main(){
	int a = 2147483647;
	printf("%d\n", a);
	printf("%d\n", ++a);
	int b = 4294967295;
	printf("%d\n", b);
	printf("%d\n", ++b);
}
