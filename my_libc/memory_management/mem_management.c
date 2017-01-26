#include <stdio.h>
#include <stdlib.h>

int main(){
  int v = 3;
  printf("[1]Code is at  %p\n", (void *)main);
  printf("[2]Heap is at  %p\n", malloc(8));
  printf("[3]Stack is at %p\n", (void *)&v);

  return 0;
}

/*

Memory organisation:
+---------+
|  Code   |   [1]
+---------+
|  Heap   |   [2]
+---------+
| / / / / |
| /Free / |
| / / / / |
+---------+
|  Stack  |   [3]
+---------+

*/
