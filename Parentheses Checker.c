#include<stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if(top == MAX-1)
        printf("Stack overflow\n");
    else {
        top++;
        stack[top] = val;
    }
}

int pop() {
    if(top == -1) {
        printf("Stack underflow");
        return -1;
    }
    else {
        return stack[top--];
    }
}

int main() {
    int flag = 1, temp;
    char exp[20];
    printf("Enter the string:");
    gets(exp);
    for(int i=0; exp[i]; i++) {
        if(exp[i] == '(')
            push(exp[i]);
        if(exp[i] == ')') {
            flag = 0;
            temp = pop();
            if(exp[i] == ')' && (temp == '('))
                flag = 1;
            if(exp[i] == '}' && (temp == '{'))
                flag = 1;
            if(exp[i] == ']' && (temp == '['))
                flag = 1;
        }
    }
    if(top > -0)
        flag = 0;
    if(flag == 1)
        printf("Valid expression");
    else
        printf("Invalid expression");
    return 0;
}