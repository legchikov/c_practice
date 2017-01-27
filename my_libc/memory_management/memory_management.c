#include <stdio.h>
#include <stdlib.h> 

int main(){
	printf("using malloc()\n");
	int *p = malloc(10 * sizeof *p);
	if (p == NULL) {
		perror("malloc() failed");
		return -1;
	} else {
		printf("Address of p: %p\n", (void *)p);
		printf("Address of p: %p\n", (void *)&p);
	}

	printf("using calloc()\n");
	int *q = calloc(10, sizeof *q);
	if(q == NULL) {
		perror("calloc() failed");
		return -1;
	} else {
		printf("Address of q: %p\n", (void *)q);
		printf("Address of q: %p\n", (void *)&q);
	}
	free(p);
	free(q);
	return 0;
}
