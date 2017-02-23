#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void left_rotate_by_one(int *arr, int size);
void left_rotate(int *arr, int size, int shift);
void create_array(int *buf, int count);
void print_array(int *arr, int size);

int main(int argc, char const *argv[]) {
    int array[50000] = {0};
    create_array(array, 50000);
    int SIZE = sizeof(array) / sizeof(int);
    int SHIFT = 30000;

    //print_array(array, SIZE);
    clock_t begin = clock();
    left_rotate(array, SIZE, SHIFT);
    clock_t end = clock();
    printf("\nSHIFT --> [%d]\n", SHIFT);
    //print_array(array, SIZE);
    printf("\n\nExecution time: %f seconds.\n", (double)(end - begin) / CLOCKS_PER_SEC);

    return 0;
}

// Complexity: O(size)
void left_rotate_by_one(int *arr, int size){
    int tmp = arr[0];
    int i;
    for (i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];
    arr[size - 1] = tmp;
}

// Complexity: O(size * shift)
void left_rotate(int *arr, int size, int shift){
    shift %= size;
    int i;
    for (i = 0; i < shift; i++)
        left_rotate_by_one(arr, size);
}

void create_array(int *buf, int count) {
    int i;
    for(i = 0; i < count; ++i)
        buf[i] = i;
}

void print_array(int *arr, int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
