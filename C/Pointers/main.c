
#include <stdio.h>

void main () {

   int  var = 42;
   int  *ptr;
   ptr = &var;

   printf("Address of var: %x\n", &var  );
   printf("Address in ptr: %x\n", ptr );
   printf("Value of *ptr:  %d\n", *ptr );
}
