#include <stdio.h>
#include "first_fit_malloc.h"

int main(int argc, char const *argv[]) {
  int *arr = (int*)first_fit_malloc(sizeof(int)*10);

  int i;
  for(i = 0; i<10; i++)
    arr[i] = i;

  for(i = 0; i<20; i++)
    printf("arr[%d] = %d\n", i, arr[i]);

  return 0;
}
