#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10

int top = -1;
char stack[MAX];
char p[10];

void push(char item) {
    top = top + 1;
    stack[top] = item;
}

char pop() {
    char x;
    x = stack[top];
    top = top - 1;
    return x;
}

int precedence(char o) {
    switch (o) {
        case '_':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
    }
    return -1; // Handle other characters as well
}

int main() {
    char in[20];
    int j = 0;
    int i = 0;
    int x, z;
    char l;

    printf("Enter infix expression:\n");
    scanf("%s", in);

    while (in[i] != '\0') {
        if (in[i] == '(') {
            push(in[i]);
        } else if (isalpha(in[i])) {
            p[j] = in[i];
            j++;
        } else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/') {
            z = precedence(in[i]);
            while (top >= 0 && precedence(stack[top]) >= z) {
                p[j++] = pop();
            }
            push(in[i]);
        } else if (in[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                p[j++] = pop();
            }
            l = pop(); // Pop the '('
        }
        i++;
    }

    while (top >= 0) {
        p[j++] = pop();
    }
    p[j] = '\0';

    printf("Required expression: %s\n", p);
    return 0;
}

