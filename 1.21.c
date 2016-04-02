#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define IN 1 /* inside a string of blanks */
#define OUT 0 /* outside a string of blanks  */
#define TABW 8 /* tab length */

void entab(char from[], char to[]);
int get_line(char line[], int maxline);

/* entab, replaces strings of blanks by the minimum number
 of tabs and blanks to achieve the same spacing
 tabs are given preference */

main() {
  int len;
  char line[MAXLINE];  
  char entabbed[MAXLINE];  

  while ((len = get_line(line, MAXLINE)) > 0) {
    entab(line, entabbed);
    printf("%s", entabbed);
  }
  return 0;
}

void entab(char from[], char to[]) {
  int i, j, state, ct_spaces, sp_to_next_col;
  char c;
  j = 0;
  state = OUT;
  ct_spaces = 0;
  sp_to_next_col = 0;

  for (i = 0; (c = from[i]) != '\0'; i++) {
    if (c == ' ') {
      if (state == OUT)
        ct_spaces = 1;
      else
        ct_spaces++;
      state = IN;
    } else {
      if (state == IN) {
        while (ct_spaces > 0) {
          sp_to_next_col = TABW - ((i - ct_spaces) % TABW);
          if (ct_spaces > TABW) {
            to[j++] = '\t';
            ct_spaces -= sp_to_next_col;
          } else {
            if (sp_to_next_col <= ct_spaces) {
              to[j++] = '\t';
              ct_spaces -= sp_to_next_col;
            } else {
              to[j++] = ' ';
              ct_spaces--;
            }
          }
        }
        to[j++] = c;
      } else {
        to[j++] = c;
      }
      state = OUT;
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
