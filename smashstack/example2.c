/* http://insecure.org/stf/smashstack.html */
/* $gcc -S -o example2.s example2.c */

/* If you run this program you will get a segmentation violation. */
void function(char *str) {
   char buffer[16];

   strcpy(buffer,str);
}

void main() {
  char large_string[256];
  int i;

  for( i = 0; i < 255; i++)
    large_string[i] = 'A';

  function(large_string);
}
