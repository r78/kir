#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);

/* print all input lines longer than 8 characters */
/* write a for loop equivalent to the one in get_line 
 * without usig && and || */

int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 8) {
            printf("%s", line);
        }
    }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i=0; ((i < lim-1) + ((c=getchar()) != EOF)  + (c!='\n')) == 3; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
