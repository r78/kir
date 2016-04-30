#include <stdio.h>

/* expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters of either
 * case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange
 * that a leading or trailing - is taken literally. */

void expand(char s1[], char s2[]);
void test(char s1[], char s2[]);

int main() {
    char s1[200] = "a-z";
    char s2[200];
    test(s1, s2);

    char s3[200] = "0-9";
    char s4[200];
    test(s3, s4);

    char s5[200] = "a-b-c";
    char s6[200];
    test(s5, s6);

    char s7[200] = "a-z0-9";
    char s8[200];
    test(s7, s8);

    return 0;
}

void test(char s1[], char s2[]) {
  expand(s1, s2);
  printf("%s = %s\n", s1, s2);
}

void expand(char s1[], char s2[]) {
  int i = 0;
  int j = 0;
  char c;
  while (s1[i] != '\0') {
    switch(s1[i]){
      case '-':
        if (i == 0) {
          s2[j] = s1[i];
        } else {
          c = s1[i-1];
          j--;
          while (c <= s1[i+1]) {
            s2[j++] = c;
            c++;
          }
            //s2[j++] = '@';
        }
        break;
      default:
        s2[j] = s1[i];
        break;
    }
    i++;
    j++;
  }
  j--;
  s2[--j] = '\0';
}
