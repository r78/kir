#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
int reverse(char s[]);
int reverse2(char s[]);

/* reverses its input a line at a time */

main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && (c!='\n'); ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int reverse(char s[]) {
    char ch;
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
    }
    i--;
    i--;

    for (j = 0; j < i; j++) {
        ch = s[j];
        s[j] = s[i];
        s[i] = ch;
        i--;
    }

    return 0;
}

int reverse2(char s[]) {
    char r[MAXLINE];
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        r[i] = s[i];
    }
    i--;

    for (j = i-1; j >= 0; j--) {
        s[i-j-1] = r[j];
    }

    return 0;
}
