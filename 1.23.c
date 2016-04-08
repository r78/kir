#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TRUE 0
#define FALSE 1

int get_line(char line[], int maxline);
void uncomment(char s[], int len);
int in_cmt, cmt_end, in_quote;

/* removes all coments from a c program 
don't forget to handle quoted strings and characters properly
c comments do not nest */

int main() {
  int len;
  char line[MAXLINE];
  extern int in_cmt, cmt_end;
  in_cmt = FALSE;
  in_quote = FALSE;
  cmt_end = -1;

  while ((len = get_line(line, MAXLINE)) > 0) {
    uncomment(line, len);
  }
  return 0;
}

void uncomment(char s[], int len) {
  int i;
  char c;
  int cmt_start = -1;
  extern int in_cmt, cmt_end, in_quote;
  
  for (i = 0; (c = s[i]) != '\0'; i++) {
    //check if we are inside quoted text
    if (in_quote == FALSE) {
      if (c == '"') {
        printf("%c", c);
        in_quote = TRUE;
      }
      if (in_quote == FALSE) {
        if (in_cmt == FALSE) {
          if (c == '/' && s[i+1] == '*') {
            cmt_start = i;
            i++;
            in_cmt = TRUE;
          }
          if (in_cmt == FALSE)
            printf("%c", c);
        } else {
          if (c == '*' && s[i+1] == '/') {
            i++;
            in_cmt = FALSE;
          } else {
            if (cmt_start > -1 && c == '\n')
              printf("\n");
          }
        }
      }
    } else {
      printf("%c", c);
      if (c == '"')
        in_quote = FALSE;
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
