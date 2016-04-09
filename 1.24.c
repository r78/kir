#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TRUE 0
#define FALSE 1

int get_line(char line[], int maxline);
void check(char s[], int len);
void find_errors(char c);
int in_cmt, in_quote, quote_chr;
int brace, paren, bracket;

/* checks a C program for syntax errors like
 * unmatched parentheses, brackets and braces
 * don't forget quotes, escape sequences and comments */

int main() {
  int len;
  char line[MAXLINE];
  extern int in_cmt;
  extern int brace, paren, bracket;
  in_cmt = FALSE;
  in_quote = FALSE;
  brace = 0;
  paren = 0;
  bracket = 0;

  while ((len = get_line(line, MAXLINE)) > 0) {
    check(line, len);
  }

  if (brace != 0)
    printf("Unmatched braces.\n");
  if (paren != 0)
    printf("Unmatched parentheses.\n");
  if (bracket != 0)
    printf("Unmatched brackets.\n");
  return 0;
}

void find_errors(char c) {
  extern int brace, paren, bracket;
  if (c == '{')
    brace++;
  else if (c == '}')
    brace--;
  else if (c == '(')
    paren++;
  else if (c == ')')
    paren--;
  else if (c == '[')
    bracket++;
  else if (c == ']')
    bracket--;
}

void check(char s[], int len) {
  int i;
  char c;
  extern int in_cmt, in_quote, quote_chr;
  
  for (i = 0; (c = s[i]) != '\0'; i++) {
    //check if we are inside quoted text
    if (in_quote == FALSE) {
      if (c == '"' || c == '\'') {
        quote_chr = c;
        in_quote = TRUE;
      }
      if (in_quote == FALSE) {
        if (in_cmt == FALSE) {
          if (c == '/' && s[i+1] == '*') {
            i++;
            in_cmt = TRUE;
          }
          if (in_cmt == FALSE)
            find_errors(s[i]);
        } else {
          if (c == '*' && s[i+1] == '/') {
            i++;
            in_cmt = FALSE;
          }
        }
      }
    } else {
      if (c == quote_chr) {
        in_quote = FALSE;
        quote_chr = '\0';
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
