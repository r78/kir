#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);

/* remove trailing blanks and tabs from each line of input
 * and delete entirely blank lines */

main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 1)
            printf("%s\n", line);
    }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;
    int ct_trailing = 0;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && (c!='\n'); ++i) {
        s[i] = c;
        if (c == ' ' || c == '\t') {
            ct_trailing++;
        } else {
            ct_trailing = 0;
        }
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i-ct_trailing-1] = '\0';
    return i-ct_trailing;
}
