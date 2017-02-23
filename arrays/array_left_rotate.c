#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void left_rotate_by_one(int *arr, int size);
void left_rotate(int *arr, int size, int shift);
void left_rotate_2(int *arr, int size, int shift);
void create_array(int *buf, int size);
void print_array(int *arr, int size);
double get_time(clock_t begin, clock_t end);

int main(int argc, char const *argv[]) {
    int const SIZE = 50000;
    int const SHIFT = 30000;
    clock_t begin;
    clock_t end;
    int array[SIZE];
    create_array(array, SIZE);

    printf("\nShift = %d\n", SHIFT);

    begin = clock();
    left_rotate(array, SIZE, SHIFT);
    end = clock();
    printf("\nExecution time [left_rotate]: %f seconds.\n", get_time(begin, end));

    begin = clock();
    left_rotate_2(array, SIZE, SHIFT);
    end = clock();
    printf("\nExecution time [left_rotate_2]: %f seconds.\n", get_time(begin, end));

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

// Time complexity: O(size * shift)
// Space: O(1)
void left_rotate(int *arr, int size, int shift){
    shift %= size;
    int i;
    for (i = 0; i < shift; i++)
        left_rotate_by_one(arr, size);
}

// Time complexity: O(size)
// Space: O(size)
void left_rotate_2(int *arr, int size, int shift){
    shift %= size;
    int arr_copy[size];
    int i;
    for (i = 0; i < size; i++)
        arr_copy[i] = arr[i];
    for (i = 0; i < size; i++)
        arr[i] = arr_copy[(i + shift) % size];
}

void create_array(int *buf, int size) {
    int i;
    for(i = 0; i < size; ++i)
        buf[i] = i;
}

void print_array(int *arr, int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
double get_time(clock_t begin, clock_t end){
    return (double)(end - begin) / CLOCKS_PER_SEC;
}
