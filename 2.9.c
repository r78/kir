#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("%d\n", bitcount(1));
    printf("%d\n", bitcount(2));
    printf("%d\n", bitcount(3));
    printf("%d\n", bitcount(4));
    printf("%d\n", bitcount(127));
    printf("%d\n", bitcount(1337));
    return 0;
}

/* a faster version of bitcount: count 1 bits in x */
int bitcount(unsigned x) {
  int b;
  for (b = 0; x != 0; x >>= 1) {
    x &= (x-1);
    b++;
  }
  return b;
}
