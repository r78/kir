#include <ctype.h>
#include <math.h>
#include <stdio.h>

/* Extend atof to handle scientific notation of the form
  123.45e-6
  where a floating-point number may be followed by e or E and an optionally signed exponent.*/

/* atof: convert string s to double */
double atof(char s[]) {
  double val, power;
  int i, sign, exp, expval;
  char expsign;

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E'){
    i++;
    if (s[i] == '-') {
      expsign = '-';
      i++;
    } else if (s[i] == '+') {
      expsign = '+';
      i++;
    } else {
      expsign = '+';
    } 
    for (expval = 0; isdigit(s[i]); i++) {
      expval = 10 * expval + (s[i] - '0');
      exp *= 10;
    }
  }

  if (expsign == '+') {
    return (sign * val / power) * pow(10, expval);
  } else {
    return (sign * val / power) / pow(10, expval);
  }
}

int main() {
  double val = atof("123.45e-6");
  printf("%f\n", val);
  return 0;
}
