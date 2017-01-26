#include <stdio.h>
#include <stdlib.h>

int main(){
  int *p_array_1;
  int *p_array_2;

  p_array_1 = (int *)malloc(sizeof(int)*10);
  p_array_2 = (int *)malloc(sizeof(int)*10);
  printf("before:\n");
  printf("p_array_1[12]: %d\n", p_array_1[12]);
  printf("p_array_2[0]:  %d\n", p_array_2[0]);
  printf("\n");

  p_array_1[12] = 7;

  printf("p_array_1[0]:  %p\n", &p_array_1[0]);
  printf("p_array_1[9]:  %p\n", &p_array_1[9]);
  printf("p_array_1[10]: %p\n", &p_array_1[10]);
  printf("p_array_1[11]: %p\n", &p_array_1[11]);
  printf("p_array_1[12]: %p\n", &p_array_1[12]);
  printf("\n");
  printf("p_array_2[0]:  %p\n", &p_array_2[0]);
  printf("p_array_2[9]:  %p\n", &p_array_2[9]);

  printf("\nafter:\n");
  printf("p_array_1[12]: %d\n", p_array_1[12]);
  printf("p_array_2[0]:  %d\n", p_array_2[0]);

  int i;
  for(i=0; i<20000; i+=100)
    printf("p_array_1[%d]:  %d\n", i, p_array_1[i]);

  return 0;
}
