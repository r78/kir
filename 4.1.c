#include <stdio.h>

/* Write the function strindex(s,t) which returns the position of the
 * rightmost occurrence of t in s , or -1 if there is none. */

int strindex(char s[], char t[]);

int strindex(char s[], char t[]) {
    int i, j, k;
    int pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) {
            pos = i;
        }
    }
    return pos;
}

int main() {
    printf("%d\n", strindex("abracadabra", "bra"));
    printf("%d\n", strindex("abracadabra", "c"));
    return 0;
}
