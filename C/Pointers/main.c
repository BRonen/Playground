#include <stdio.h>
#include <assert.h>

void func1(int *a){
    *a = 1;
}

void func2(int *a){
    *a = 2;
}

//receive a pointer to a pointer to a function
void changeValue(void (**ptr)()){
    //set pointer of pointer to func2
    *ptr = &func2;
}

void main (){
    int a = 0;
    void (*ptr)(); //pointer to "void function()"
    ptr = &func1; //ptr -> func1
    assert(ptr == &func1);

    ptr(&a); //func1()
    assert(a == 1);

    changeValue(&ptr); //passing ptr memory address
    assert(ptr == &func2);

    ptr(&a); //func2()
    assert(a == 2);
}
