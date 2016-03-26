#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */


/* prints a histogram of the lengths of words in its input */

main() {

    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            printf("\n");
            state = IN;
        }
        if (state == IN)
            putchar('#');
        if (c == '\n')
            putchar('\n');
    }

}
