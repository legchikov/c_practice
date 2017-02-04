#include <stdio.h>

#define MAX(a, b, c) {\
						int _a = (a); \
						int _b = (b); \
						(_a > _b) ? (c = _a) : (c = _b);\
					 }

int main(int argc, char const *argv[]) {
    int a = 10;
    int b = 20;
    int c = 0;

    MAX(a, b, c);
    printf("c=%d\n", c);

    MAX(a+=b, b, c);
    printf("a=%d, c=%d\n", a, c);

    MAX(++a, b, c);
    printf("a=%d, c=%d\n", a, c);

    return 0;
}
