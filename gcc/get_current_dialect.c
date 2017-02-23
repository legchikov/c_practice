#include <stdio.h>

int main() {
#ifdef __STRICT_ANSI__
    printf("c");
#else
    printf("gnu");
#endif

#ifdef __STDC_VERSION__
  #if __STDC_VERSION__ == 199901L
    puts("99");
  #elif __STDC_VERSION__ == 201112L
    puts("11");
  #else
    puts("(unknown)");
  #endif
#else
  puts("90");
#endif
  return 0;
}
