/* http://insecure.org/stf/smashstack.html */
/* $gcc -S -o assemble/example1.s example1.c */

void function(int a, int b, int c) {
   char buffer1[5];
   char buffer2[10];
}

void main() {
  function(1, 2, 3);
}

/*

bottom of                                                            top of
memory                                                               memory
           buffer2       buffer1   sfp   ret   a     b     c
<------   [            ][        ][    ][    ][    ][    ][    ]

top of                                                            bottom of
stack                                                                 stack

sfp - stack frame pointer
ret - return from procedure

*/
