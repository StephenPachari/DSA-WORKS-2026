/* Q3: Convert infix expression A + B * (C - D) / E to postfix using a stack. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop(void) { return stack[top--]; }

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main(void) {
    char infix[] = "A+B*(C-D)/E";
    char postfix[100];
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum((unsigned char)c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1) pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';

    printf("Infix: A + B * (C - D) / E\n");
    printf("Postfix: %s\n", postfix);
    return 0;
}
/*
Sample Output:
Infix: A + B * (C - D) / E
Postfix: ABCD-*E/+ 
*/
