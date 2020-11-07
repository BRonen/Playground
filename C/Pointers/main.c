
#include <stdio.h>

void changeValue(int *ptr){
    *ptr = (printf("changed\n"), 24);
}

void main (){
   int  var = 42;
   int  *ptr;
   ptr = &var;

   printf("Address of var: %x\n", &var  );
   printf("Address in ptr: %x\n\n", ptr );

   printf("Value of *ptr before:  %d\n", *ptr );
   changeValue(ptr);
   printf("Value of *ptr after:  %d\n", *ptr );
}
