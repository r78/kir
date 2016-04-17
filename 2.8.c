#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void DisplayBits(unsigned value);

int main() {
    DisplayBits(627);
    DisplayBits(rightrot(627, 8));
    return 0;
}


/* returns the value of the integer x rotated to the right by n positions */
unsigned rightrot(unsigned x, int n) {
  return((x >> n) | (x << ((sizeof(unsigned int)*8) - n)));


void DisplayBits(unsigned value) {
    int i = 0, numbits = sizeof(unsigned int)*8;
    for(;i<numbits;i++) {
        if(!(i%4) && i)
            printf(" ");
        printf("%d", !(!(value & (1<<(numbits-i-1)))));
    }
    printf("\n");
}
