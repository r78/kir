#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

void fold(char s[], int pos);
int get_line(char line[], int maxline);

/* folds long input lines into two or more shorter lines
 * after the last non-blank character that occurs before
 * the nth column of input */
  
main() {
  int len;
  char line[MAXLINE];  
  
  while ((len = get_line(line, MAXLINE)) > 0) {
    fold(line, 40);
  }
  return 0;
}   

void printbuf(char buf[], int k) {
  int i;
  for (i = 0; i < k; i++) 
    putchar(buf[i]);
}

void fold(char s[], int pos) {
  int i;
  char c; 
  char buf[pos];
  int pos_space = -1;
  int j = 0;
  int k = 0;
  int l;
  int col = 0;

  for (i = 0; (c = s[i]) != '\0'; i++) {
    if(c == ' ') {
      if (k >= pos) {
        printbuf(buf, k);
        putchar('\n');
        k = 0;
        col = 0;
        pos_space = -1;
      } else {
        buf[k] = c;
        pos_space = k;
        k++;
        col++;
      }
    } else if (c == '\n') {
      printbuf(buf, k);
    } else {
      if (k >= pos) {
        if (pos_space > 0) {
          printbuf(buf, pos_space);
          putchar('\n');
          i -= k - pos_space;
          k = 0;
          col = 0;
          pos_space = -1;
        } else {
          printbuf(buf, k);
          putchar('\n');
          buf[0] = c;
          k = 1;
          col = 1;
          pos_space = -1;
        }
      } else {
        buf[k] = c;
        col++;
        k++;
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

