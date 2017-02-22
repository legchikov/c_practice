#include "stdio.h"
#define SIZE 10

int main(int argc, char const *argv[]) {
    int m[SIZE] = {}; // Изначально заполнен нулями
    //          &m[0]         &m[9]
    int i;

    printf("array 1:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d ", m[i]);

    int *p = m;
    for(*p = m; p < m + SIZE; ++p)
        *p = (p - m) + 1; // заполнение массива числами от 1 до 10
                          // +1, чтобы числа от 1 до 10, а не от 0 до 9

    printf("\narray 2:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d ", *(m + i));

    printf("\narray 3:\n");
    for(p = &m[0]; p < m + SIZE; ++p)
        printf("%d ", *p);

    return 0;
}
