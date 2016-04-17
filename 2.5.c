#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    printf("%d\n", any("velociraptor", "abcd"));
    printf("%d\n", any("triceratops", "xyz"));
    return 0;
}


/* returns the first location in s1 where any character from s2 occurs 
 * or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[]) {
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++)
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] == s2[k])
                return i;
    return -1;
}
