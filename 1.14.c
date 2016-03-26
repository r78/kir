#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */


/* prints a histogram of the frequencies of 
 * different characters in its input */

main() {

    int c, i, j, state;
    int characters[128];

    state = OUT;

    for (i = 0; i <= 127; i++)
        characters[i] = 0;

    while ((c = getchar()) != EOF) {
        ++characters[c]; 

        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
            state = IN;

        if (c == '\n') {
            for (i = 0; i <= 127; i++) {
                if (characters[i] != 0 && i != 10) {
                    printf("'%c': ", i);
                    for (j = 0; j < characters[i]; j ++) 
                        printf("#");
                    printf("\n");
                }
            }
            for (i = 0; i <= 127; i++)
                characters[i] = 0;
        }
    }
    
}
