/* An horrible dummy malloc */

#include <sys/types.h>
#include <unistd.h>

void *dummy_malloc(size_t size){
  void *p;
  p = sbrk(0);
  printf("address (start heap): %p\n", p);

  /* if sbrk() fails, we return NULL */
  if(sbrk(size) == (void *)-1)
    return NULL;
  p = sbrk(0);
  printf("address (new start heap): %p\n", p);
  return p;
}

int main(){
  printf("\nINT:\n");
  int *ptr_int = (int *)dummy_malloc(10);
  ptr_int[0] = 0;
  ptr_int[1] = 1;
  ptr_int[9] = 9;
  printf("ptr_int[0]: %d\n", ptr_int[0]);
  printf("ptr_int[1]: %d\n", ptr_int[1]);
  printf("ptr_int[9]: %d\n", *(ptr_int+9));
  printf("address ptr_int[0]: %p\n", ptr_int+0);
  printf("address ptr_int[1]: %p\n", ptr_int+1);
  printf("address ptr_int[9]: %p\n", &ptr_int[9]);

  printf("\nDOUBLE (dummy_malloc):\n");
  double *ptr_double = (double *)dummy_malloc(10);
  ptr_double[0] = 0.0;
  ptr_double[1] = 1.1;
  ptr_double[100] = 100.100;
  printf("ptr_double[0]: %f\n", ptr_double[0]);
  printf("ptr_double[1]: %f\n", ptr_double[1]);
  printf("ptr_double[100]: %f\n", *(ptr_double+100));
  printf("address ptr_double[0]: %p\n", ptr_double+0);
  printf("address ptr_double[1]: %p\n", ptr_double+1);
  printf("address ptr_double[100]: %p\n", ptr_double+100);

  printf("\nDOUBLE (malloc):\n");
  double *ptr_double__ = (double *)malloc(10);
  ptr_double__[0] = 0.0;
  ptr_double__[1] = 1.1;
  ptr_double__[100] = 100.100;
  printf("ptr_double__[0]: %f\n", ptr_double__[0]);
  printf("ptr_double__[1]: %f\n", ptr_double__[1]);
  printf("ptr_double__[100]: %f\n", *(ptr_double__+100));
  printf("address ptr_double__[0]: %u\n", ptr_double__+0);
  printf("address ptr_double__[1]: %u\n", ptr_double__+1);
  printf("address ptr_double__[100]: %u\n", ptr_double__+100);


  return 0;
}
