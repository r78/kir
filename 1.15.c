#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 
 * using a function */

float fahr_to_celsius(int fahr);

main() {

    float fahr, celsius;
    float lower,upper, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;

    while (fahr <= upper) {
        printf("%3.0f\t%6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr = fahr + step;
    }
    return 0;
}

float fahr_to_celsius(int fahr) {
    return 5.0 * (fahr - 32.0) / 9.0;
}
