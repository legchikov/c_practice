#include <stdio.h>

void set_bit_one(int *x, int n);
void set_bit_zero(int *x, int n);
void switch_bit(int *x, int n);
int int_max();
int int_min();

int main(){
	int x = 0;
	printf("int x = 0;\n");
	
	set_bit_one(&x, 10);
	printf("set_bit_one(&x, 10) --> %d\n", x);
	
	set_bit_zero(&x, 10);
	printf("set_bit_zero(&x, 10) --> %d\n", x);
	
	switch_bit(&x, 5);
	printf("switch_bit(&x, 5) --> %d\n", x);
	
	switch_bit(&x, 5);
	printf("switch_bit(&x, 5) --> %d\n", x);
	
	printf("int_max() --> %d\n", int_max());
	printf("int_min() --> %d\n", int_min());
	
	return 0;
}

/* Set n-th bit to 1 */
void set_bit_one(int *x, int n){
	*x |= (1<<n);
}

/* Set n-th bit to 0 */
void set_bit_zero(int *x, int n){
	*x &= ~(1<<n);
}

/* Switch n-th bit */
void switch_bit(int *x, int n){
	*x ^= (1<<n);
}

/* Get max integer value */
int int_max(){
	return ~(1 << 31);
	/* return (1 << 31) - 1; */
	/* return (1 << -1) - 1; */
}

/* Get min integer value */
int int_min(){
	return (1 << 31);
	/* return (1 << -1); */
}
