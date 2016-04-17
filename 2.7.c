#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void DisplayBits(unsigned value);

int main() {
    DisplayBits(555);
    printf("\n");
    DisplayBits(invert(555, 7, 4));
    return 0;
}


/* returns x with the n bits that begin at position p inverted
 * leaving the others unchanged */
unsigned invert(unsigned x, int p, int n) {
  return x ^ ( (~(~0 << n)) << (p+1-n) );
}


void DisplayBits(unsigned value) {
    int i = 0, numbits = sizeof(unsigned int)*8;
    for(;i<numbits;i++) {
        if(!(i%4) && i)
            printf(" ");
        printf("%d", !(!(value & (1<<(numbits-i-1)))));
    }
    printf("\n");
}
