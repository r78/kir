#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. 
In particular, itob(n,s,16) formats s as a
hexadecimal integer in s . */

void reverse(char s[]);
void itob(int n, char s[], int b);

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
void itob(int n, char s[], int b) {
    int i, sign, digit;
    if ((sign = n) < 0) /* record sign */
    n = -n;
    /* make n positive */
    i = 0;
    do {
        /* generate digits in reverse order */
        digit = abs(n % b);
        if (digit < 10)
          s[i++] = digit + '0'; /* get next digit */
        else
          s[i++] = digit + 'A' - 10; /* get next digit */
    } while (abs(n /= b) > 0);
    /* delete it */
    if (sign < 0)
    s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char snum[10];
    int n = 65535;
    itob(n, snum, 16);
    printf("%s\n", snum);

    n = 128;
    itob(n, snum, 2);
    printf("%s\n", snum);

    n = 227781;
    itob(n, snum, 26);
    printf("%s\n", snum);
    return 0;
}
