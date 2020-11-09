#include <assert.h>

int main(){
    int num1 = 7, num2 = 8;
    float sum, sub, div, mul;

    sum = (float)num1 + num2,
    sub = (float)num1 - num2,
    div = (float)num1 / num2,
    mul = (float)num1 * num2;

    assert(sum == 15);
    assert(sub == -1);
    assert(div == 0.875);
    assert(mul == 56);
    return 0;
}
