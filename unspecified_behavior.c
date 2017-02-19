#include <stdio.h>
#include "math.h"
int main(int argc, char const *argv[]) {

    /* unspecified behavior */
    int i = 10;
    i = (i += 5) + (i * 10);
    printf("%d\n", i);

    return 0;
}
