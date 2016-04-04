#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TRUE 0
#define FALSE 1

int get_line(char line[], int maxline);
void uncomment(char s[], int len);
void printbuf(char s[], int end);
void printbuftail(char s[], int start, int len);

/* removes all coments from a c program 
don't forget to handle quoted strings and characters properly
c comments do not nest */

main() {
  int len;
  char line[MAXLINE];  
  
  while ((len = get_line(line, MAXLINE)) > 0) {
    uncomment(line, len);
  }
  return 0;
}

void uncomment(char s[], int len) {
  int i;
  char c;
  int cmt_pos = -1;
  int ml_start = -1;
  int ml_end = -1;
  int in_cmt = FALSE;
  int in_ml = FALSE;
  

  for (i = 0; (c = s[i]) != '\0'; i++) {
    //TODO check if we are inside quoted text
    //TODO check wether we are inside a single comment, multiline comment, no comment
    if (in_ml == FALSE)  {
      if (in_cmt == FALSE && in_ml == FALSE && c == '/' && s[i+1] == '/') {
        cmt_pos = i;
        printf("sl, %d, in? %d, ml? %d\n", i, in_cmt, in_ml);
        printbuf(s, i);
        in_cmt = TRUE;
      } else if (in_cmt == FALSE && in_ml == FALSE && c == '/' && s[i+1] == '*') {
        //in multiline comment
        printf("mlstart, %d, in? %d, ml? %d\n", i, in_cmt, in_ml);
        ml_start = i;
        printbuf(s, i);
        in_ml == TRUE;
      } else if (in_ml == TRUE && ml_start > -1 && c == '*' && s[i+1] == '/') { //check also if in_cmt is true?
        ml_end = i + 1;
        printf("mlend, %d, in? %d, ml? %d\n", i+1, in_cmt, in_ml);
        printbuftail(s, ml_end, len);
        in_ml == FALSE;
      }
    } else {
      //we are inside a comment
    }
  }
}

void printbuf(char buf[], int end) {
  int i;
  for (i = 0; i < end; i++) 
    putchar(buf[i]);
  putchar('\n'); //DEBUG
}

void printbuftail(char buf[], int start, int len) {
  int i;
  for (i = start + 1; i < len; i++) 
    putchar(buf[i]);
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

