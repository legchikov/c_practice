#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void left_rotate_by_one(int *arr, int size);
void left_rotate(int *arr, int size, int shift);
void left_rotate_2(int *arr, int size, int shift);
void left_rotate_3(int *arr, int size, int shift);
void create_array(int *buf, int size);
void reverse_array(int *arr, int start_index, int end_index);
void print_array(int *arr, int size);
double runtime(clock_t begin, clock_t end);

int main(int argc, char const *argv[]) {
    int const SIZE = 10;
    int const SHIFT = 3;
    clock_t begin;
    clock_t end;
    int array[SIZE];
    create_array(array, SIZE);

    printf("\nShift = %d\n", SHIFT);

    print_array(array, SIZE);

    begin = clock();
    left_rotate(array, SIZE, SHIFT);
    end = clock();
    printf("\nExecution time [left_rotate]: %f seconds.\n", runtime(begin, end));
    print_array(array, SIZE);

    begin = clock();
    left_rotate_2(array, SIZE, SHIFT);
    end = clock();
    printf("\nExecution time [left_rotate_2]: %f seconds.\n", runtime(begin, end));
    print_array(array, SIZE);

    begin = clock();
    left_rotate_3(array, SIZE, SHIFT);
    end = clock();
    printf("\nExecution time [left_rotate_3]: %f seconds.\n", runtime(begin, end));
    print_array(array, SIZE);

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

void left_rotate_3(int *arr, int size, int shift){
    reverse_array(arr, 0, shift-1);
    reverse_array(arr, shift, size-1);
    reverse_array(arr, 0, size-1);
}

void create_array(int *buf, int size) {
    int i;
    for(i = 0; i < size; ++i)
        buf[i] = i;
}

void reverse_array(int *arr, int start, int end){
    int tmp;
    while(start < end){
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++, end--;
    }
}

void print_array(int *arr, int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
double runtime(clock_t begin, clock_t end){
    return (double)(end - begin) / CLOCKS_PER_SEC;
}
