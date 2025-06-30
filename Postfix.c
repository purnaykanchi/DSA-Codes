#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    else
        return s->items[(s->top)--];
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int evaluatePostfix(char postfix[]) {
    Stack s;
    initialize(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];
        if (isdigit(symbol)) {
            push(&s, symbol - '0'); // Convert char to int
        }
        else if (isOperator(symbol)) {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (symbol) {
                case '+': push(&s, operand1 + operand2); break;
                case '-': push(&s, operand1 - operand2); break;
                case '*': push(&s, operand1 * operand2); break;
                case '/': push(&s, operand1 / operand2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char postfix[] = "23*5+";
    int result = evaluatePostfix(postfix);
    printf("Result of %s = %d\n", postfix, result);
    return 0;
}