#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[]);

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) /* record sign */
    n = -n;
    /* make n positive */
    i = 0;
    do {
        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0'; /* get next digit */
    } while (abs(n /= 10) > 0);
    /* delete it */
    if (sign < 0)
    s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char snum[3];
    int n = INT_MIN;
    itoa(n, snum);
    printf("%s\n", snum);
    return 0;
}
