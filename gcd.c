#include "stdio.h"

int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

unsigned int gcd2(int a, int b){
    return a == 0 ? b : gcd(b%a, a);
}

int main(){
    int number1 = 6;
    int number2 = 21;

    printf("%d\n", gcd(number1, number2));
    printf("%d\n", gcd2(number1, number2));

    return 0;
}
