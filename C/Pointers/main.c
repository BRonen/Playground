
#include <stdio.h>

void func1(){
    printf("Hello from func1\n");
}

void func2(){
    printf("Hello again from func2\n");
}

//receive a pointer to a pointer to a function
void changeValue(void (**ptr)()){
    //set pointer of pointer to func2
    *ptr = (printf("changed\n"), &func2);
}

void main (){
    void (*ptr)(); //pointer to "void function()"
    ptr = &func1; //ptr -> func1

    ptr(); //func1()
    changeValue(&ptr); //passing ptr memory address
    ptr(); //func2()
}
