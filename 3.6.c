#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/* Write a version of itoa that accepts three arguments instead of two. 
 * The third argument is a minimum field width; 
 * the converted number must be padded with blanks on the left 
 * if necessary to make it wide enough. */

void reverse(char s[]);
void itoa(int n, char s[], int w);

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
void itoa(int n, char s[], int w) {
    int i, sign;
    if ((sign = n) < 0) /* record sign */
    n = -n;
    /* make n positive */
    i = 0;
    do {
        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0'; /* get next digit */
    } while (abs(n /= 10) > 0);
    
    while (i < w) {
        s[i++] = ' ';
    }
    
    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char snum[12];
    int n = 3456;
    itoa(n, snum, 6);
    printf("%s\n", snum);
    return 0;
}
