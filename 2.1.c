#include <stdio.h>
#include <limits.h>

/* determine the ranges of char, short, int and long variables
 * both signed and unsigned */

int main() {
  //from standard headers
  printf("Minimum unsigned char value: %d\n", 0);
  printf("Maximum unsigned char value: %d\n", UCHAR_MAX);
  printf("Minimum signed char value: %d\n", CHAR_MIN);
  printf("Maximum signed char value: %d\n", CHAR_MAX);
  printf("\n");
  printf("Minimum unsigned short value: %d\n", 0);
  printf("Maximum unsigned short value: %d\n", USHRT_MAX);
  printf("Minimum signed short value: %d\n", SHRT_MIN);
  printf("Maximum signed short value: %d\n", SHRT_MAX);
  printf("\n");
  printf("Minimum unsigned int value: %d\n", 0);
  printf("Maximum unsigned int value: %u\n", UINT_MAX);
  printf("Minimum signed int value: %d\n", INT_MIN);
  printf("Maximum signed int value: %d\n", INT_MAX);
  printf("\n");
  printf("Minimum unsigned long value: %d\n", 0);
  printf("Maximum unsigned long value: %lu\n", ULONG_MAX);
  printf("Minimum signed long value: %ld\n", LONG_MIN);
  printf("Maximum signed long value: %ld\n", LONG_MAX);
  //by direct computation
  printf("----------\n");
  printf("Minimum unsigned char value: %d\n", 0);
  printf("Maximum unsigned char value: %d\n", (unsigned char) ~0);
  printf("Minimum signed char value: %d\n", -(char)((unsigned char) ~0 >> 1) - 1);
  printf("Maximum signed char value: %d\n", (char)((unsigned char) ~0 >> 1));
  printf("\n");
  printf("Minimum unsigned short value: %d\n", 0);
  printf("Maximum unsigned short value: %d\n", (unsigned short) ~0);
  printf("Minimum signed short value: %d\n", -(short)((unsigned short) ~0 >> 1) - 1);
  printf("Maximum signed short value: %d\n", (short)((unsigned short) ~0 >> 1));
  printf("\n");
  printf("Minimum unsigned int value: %d\n", 0);
  printf("Maximum unsigned int value: %u\n", (unsigned int)~0);
  printf("Minimum signed int value: %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
  printf("Maximum signed int value: %d\n", (int)((unsigned int) ~0 >> 1);
  printf("\n");
  printf("Minimum unsigned long value: %d\n", 0);
  printf("Maximum unsigned long value: %lu\n", (unsigned long)~0);
  printf("Minimum signed long value: %ld\n", -(long)((unsigned long) ~0 >> 1) -1);
  printf("Maximum signed long value: %ld\n", (long)((unsigned long) ~0 >> 1);
  return 0;
}
