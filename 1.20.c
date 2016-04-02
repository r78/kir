#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TABW 8 /* tab length */

void detab(char from[], char to[]);
int get_line(char line[], int maxline);

/* detab, replaces tabs in the input with the
 proper number of blanks to space to the next
 tab stop */

main() {
  int len;
  char line[MAXLINE];  
  char detabbed[MAXLINE];  

  while ((len = get_line(line, MAXLINE)) > 0) {
    detab(line, detabbed);
    printf("%s", detabbed);
  }
  return 0;
}

void detab(char from[], char to[]) {
  int i, j, ct_spaces;
  char c;
  j = 0;

  for (i = 0; (c = from[i]) != '\0'; i++) {
    if (c != '\t') {
      to[j++] = c;
    } else {
      ct_spaces = TABW - (j % TABW);
      while(ct_spaces-- > 0) {
        to[j++] = ' ';
      }
    }
  }
  to[j] = '\0';
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
