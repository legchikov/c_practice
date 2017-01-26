#include <stdio.h>

int main(){
  int bar = 10;
  int *foo; /* NOT INIT */

  foo = 5; /* never make */
  /* *foo = &bar; // OK */
  printf("*foo = %d; foo = %p\n", *foo, foo);

  return 0;
}
