#include "stdio.h"
#include "string.h"

int main(void) {
    char str[] = "Where there is will, there is a way.Hello!Azazazaz, xse xeki xeuj?QQQ.";
    printf("%s\n\n", str);

    char *copy = strdup(str);
    char *delim = "!?.";
    char delim_str[2] = "\0";
    char *res = strtok(str, delim);
    char *sentense;
    const char *arr[4];
    int i = 0;

    while (res) {
        delim_str[0] = copy[res-str+strlen(res)];
        sentense = strdup(res);
        strcat(sentense, delim_str);
        arr[i] = sentense;
        i++;
        //printf("%s\n", sentense);
        res = strtok(NULL, delim);
    }

    printf("%s\n", "Strings:");
    int j;
    for (j = 0; j < 4; j++)
        printf("arr[%d] = %s\n", j, arr[j]);

    return 0;
}
