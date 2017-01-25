#include <stdio.h>
#include <stdlib.h>

int main(){
  int v = 3;
  printf("Code is at  %p\n", (void *)main);
  printf("Heap is at  %p\n", malloc(8));
  printf("Stack is at %p\n", (void *)&v);

  return 0;
}

/*

Memory organisation:
+---------+
|  Code   |
+---------+
|  Heap   |
+---------+
| / / / / |
| /Free / |
| / / / / |
+---------+
|  Stack  |
+---------+

*/
