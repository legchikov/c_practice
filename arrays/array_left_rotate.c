#include <stdio.h>
#define SIZE 3
#define SHIFT 1

void array_shift(int *arr, int size, int shift){
    int tmp, i;
    tmp = arr[shift % size];

    for (i = 0; i < size-1; i++) {
        arr[(i + shift) % size] = arr[i];
    }
    arr[shift % size] = tmp;
}

void printArray(int *arr, int size){
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

int main(int argc, char const *argv[]) {
    int array[SIZE] = {0, 1, 2};

    printArray(array, SIZE);
    array_shift(array, SIZE, SHIFT);
    printArray(array, SIZE);

    return 0;
}
