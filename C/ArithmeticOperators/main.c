#include <stdio.h>

int main(){
    int num1, num2;
    float sum, sub, div, mul;
    
    printf("First number: ");
    scanf("%d", &num1);
    
    printf("Second: ");
    scanf("%d", &num2);
    
    sum = (float)num1 + num2,
    sub = (float)num1 - num2,
    div = (float)num1 / num2,
    mul = (float)num1 * num2;
    
    printf("\nSum: %.2f\n", sum);
    printf("Sub: %.2f\n", sub);
    printf("Div: %.2f\n", div);
    printf("Mul: %.2f\n", mul);
    return 0;
}
