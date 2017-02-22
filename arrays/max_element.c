#include "stdio.h"

int max_element(int *m, size_t size){
    int max = *m;

    int i;
    for(i = 0; i < size; i++) {
        if(m[i] > max)
            max = m[i];
    }
    return max;
}

int main(int argc, char const *argv[]) {
    int arr[5] = {1, 5, 10, 3, 1};
    int max = max_element(arr, sizeof(arr)/sizeof(int));
    printf("%d\n", max);

    return 0;
}
