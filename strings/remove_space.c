#include <stdio.h>

int main() {
    int count = 0;
    char c = '\0';
    while (scanf("%s", &c)) {
        if(c == '\0'){
            if(count > 0)
                printf("%c\n", c);
            else{
                count++;
                continue;
            }
        } else{
            count = 0;
            printf("%c\n", c);
        }
    }

	return 0;
}
