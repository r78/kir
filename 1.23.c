#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TRUE 0
#define FALSE 1

int get_line(char line[], int maxline);
void uncomment(char s[], int len);
int in_ml, ml_end;

/* removes all coments from a c program 
don't forget to handle quoted strings and characters properly
c comments do not nest */

int main() {
  int len;
  char line[MAXLINE];
  extern int in_ml, ml_end;
  in_ml = FALSE;
  ml_end = -1;

  while ((len = get_line(line, MAXLINE)) > 0) {
    uncomment(line, len);
  }
  return 0;
}

void uncomment(char s[], int len) {
  int i;
  char c;
  int ml_start = -1;
  extern int in_ml, ml_end;
  
  for (i = 0; (c = s[i]) != '\0'; i++) {
    //TODO check if we are inside quoted text
    if (in_ml == FALSE) {
      if (c == '/' && s[i+1] == '*') {
        ml_start = i;
        i++;
        in_ml = TRUE;
      }
      if (in_ml == FALSE)
        printf("%c", c);
    } else {
      if (c == '*' && s[i+1] == '/') {
        i++;
        in_ml = FALSE;
      } else {
        if (ml_start > -1 && c == '\n') 
          printf("\n");
      }
    }
  }
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
