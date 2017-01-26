#include <stdio.h>

int normalize(int, int, int);

int main(){
  int arr[] = {1, 2, 3, 4, 5, -1, -2, -3 ,-4};
  int i, min, max;
  min = max = arr[0];

  printf("Array:\n");
  for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    printf("%d ", arr[i]);

  for(i = 0; i < sizeof(arr)/sizeof(int); i++){
    if(arr[i] < min)
      min = arr[i];
    if(arr[i] > max)
      max = arr[i];
  }

  for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    arr[i] = normalize(arr[i], min, max);

  printf("Normalize array:\n");
  for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    printf("%d ", arr[i]);

  return 0;
}

int normalize(int x, int min, int max) {
  int norma = (x - min) / (max - min);
  return norma;
}
