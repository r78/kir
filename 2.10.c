#include <stdio.h>

int lower(int c);

int main() {
    printf("%c\n", lower('A'));
    printf("%c\n", lower('B'));
    printf("%c\n", lower('C'));
    printf("%c\n", lower('x'));
    printf("%c\n", lower('y'));
    printf("%c\n", lower('z'));
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
