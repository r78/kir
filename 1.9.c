#include <stdio.h>

/* copies its input to its output, replacing each string of one
 * or more blanks by a single blank */

main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
           while ((c = getchar()) == ' ')
            ;
            putchar(' ');
            putchar(c);
        } else
            putchar(c);
    }
}
