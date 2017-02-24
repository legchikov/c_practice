#include <stdio.h>

#define SIZE 5

void xor_swap(int *x, int *y);
void tmp_swap(int *x, int *y);
void reverse_array(int *arr, int start, int end);
void print_array(int *arr, int size);


int main(){
    int a[SIZE] = {1, 2, 3, 4, 5};
    print_array(a, SIZE);
    reverse_array(a, 0, SIZE-1);
    print_array(a, SIZE);

    return 0;
}

void xor_swap(int *x, int *y){
    if(x != y){
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

void tmp_swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void reverse_array(int *arr, int start, int end){
    for(; start < end; start++, end--)
        xor_swap(&arr[start], &arr[end]);
}

void print_array(int *arr, int size){
    printf("\n");
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
