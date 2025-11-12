#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isBalanced(char *exp) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            char ch = pop();
            if ((exp[i] == ')' && ch != '(') ||
                (exp[i] == '}' && ch != '{') ||
                (exp[i] == ']' && ch != '['))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Expression is well parenthesized.\n");
    else
        printf("Expression is NOT well parenthesized.\n");
}
