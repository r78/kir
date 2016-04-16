#include <stdio.h>

int htoi(char s[]);

/* converts a string of hexadecimal digits 
 * including an optional 0x or 0X into its
 * equivalent integer value */

int main() {
    printf("%d\n", htoi("0xF"));
    printf("%d\n", htoi("0XF"));
    printf("%d\n", htoi("0xf"));
    printf("%d\n", htoi("0xCDF9FB8"));
    return 0;
}

int htoi(char s[]) {
  int i, n;
  n = 0;

  for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f') || s[i] == 'x' || s[i] == 'X'; i++) {
      if (i == 0 && s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
        continue;
      } else if (i == 1 && s[i-1] == '0' && (s[i] == 'x' || s[i] == 'X')) {
        continue;
      } else {
        if (s[i] >= '0' && s[i] <= '9') {
          n = 16 * n + (s[i] - '0');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
          n = 16 * n + (s[i] - 'A' + 10);
        } else {
          n = 16 * n + (s[i] - 'a' + 10);
        }
      }
    }

  return n;
}
