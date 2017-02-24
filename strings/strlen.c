#include <stdio.h>

unsigned strlen(const char *str){
    unsigned len = 0;
    while(*str++ != '\0')
        len++;

    return len;
}

int main(){
    const char s[] = "hello world!\0";
    int len = strlen(s);
    printf("%d\n", len);

    return 0;
}
