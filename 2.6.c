#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void DisplayBits(unsigned value);

int main() {
    DisplayBits(234);
    DisplayBits(555);
    printf("\n");
    DisplayBits(setbits(234, 7, 4, 555));
    return 0;
}


/* returns x with the n bits that begin at position p set 
 * to the rightmost n bits of y , leaving the other bits unchanged. */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  //rightmost n bits of y
  //y & ~(~0 << n);
  return (x & ~(~(~0 << n) << (p+1-n))) | ((y & ~(~0 <<n))<< (p+1-n));
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
