#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

/* Add the commands to print the top elements of the stack without popping, 
to duplicate it, and to swap the top two elements. 
Add a command to clear the stack. */

int getop(char []);
void push(double);
double pop(void);
void clear(void);

/* reverse Polish calculator */

int main() {
    int type;
    double op2, op1;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                /* 4.3 add the modulus operator */
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 'p':
                /* 4.4 print the top element */
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'd':
                /* 4.4 duplicate the top element */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                /* 4.4 swap the top two elements */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':
                /* 4.4 clear the stack */
                clear();
                break;
            case 'i':
                /* 4.5 sin */
                push(sin(pop()));
                break;
            case 'e':
                /* 4.5 sin */
                push(exp(pop()));
                break;
            case 'w':
                /* 4.5 sin */
                op2 = pop();
                push(pow(pop(), op2));
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* 4.4 clear the stack */
void clear(void) {
    sp = 0;
}

#include <ctype.h>
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (c == '-') { /* 4.3 add provisions for negative numbers */
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        }
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void) { 
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
