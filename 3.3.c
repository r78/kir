#include <stdio.h>

/* expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters of either
 * case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange
 * that a leading or trailing - is taken literally. */

void expand(char s1[], char s2[]);
void test(char s1[], char s2[]);

int main() {
    char s1[4000] = "a-z / 0-9 / a-b-c / a-z0-9";
    //char s1[4000] = "a-f / 0-4";
    char s2[4000];
    test(s1, s2);

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
          j--;
          while (c < s1[i+1]) {
            s2[++j] = c;
            c++;
          }
        }
        break;
      default:
        s2[j] = s1[i];
        break;
    }
    i++;
    j++;
  }
  s2[j] = '\0';
}
