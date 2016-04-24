#include <stdio.h>

/* converts characters like newline and tab into visible escape sequences 
 * like \n and \t as it copies the string t to s . Use a switch . 
 * Write a function for the other direction as well, 
 * converting escape sequences into the real characters */

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char s[50] = "hello\n\tworld";
    char s2[50] = "hello\\n\\tworld";
    char t[50];

    escape(s, t);
    printf("%s\n", s);
    printf("%s\n", t);
    printf("\n");

    unescape(s2, t);
    printf("%s\n", s2);
    printf("%s\n", t);
    return 0;
}


void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (s[i] != '\0') {
    switch(s[i]) {
      case '\t':
        t[j++] = '\\';
        t[j] = 't';
        break;
      case '\n':
        t[j++] = '\\';
        t[j] = 'n';
        break;
      default:
        t[j] = s[i];
        break;
    }
    i++;
    j++;
  }
  t[j] = s[i];
}

void unescape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (s[i] != '\0') {
    switch(s[i]) {
      case '\\':
        switch(s[++i]) {
          case 't':
            t[j] = '\t';
            break;
          case 'n':
            t[j] = '\n';
            break;
          default:
            t[j++] = '\\';
            t[j] = s[i];
            break;
        }
        break;
      default:
        t[j] = s[i];
        break;
    }
    i++;
    j++;
  }
  t[j] = s[i];
}
