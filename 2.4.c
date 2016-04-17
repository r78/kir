#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "achimello0_ _awoci0rldiDima0";
    char s2[] = "cia0_m0nD0";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}


/* deletes each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k]) {
                s1[j++] = s1[i];
                }
        s1[j] = '\0';
    }
}
