#include "stdio.h"

int foo(){
    printf("Hello\n");
    return 2;
}

int bar(){
    int *m[1];
    m[4] = (int *) &foo;
    return 1;
}

int main(){
    bar();
    return 0;
}
