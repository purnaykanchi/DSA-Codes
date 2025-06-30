#include<stdio.h>

void push(void);
void pop(void);
void display(void);

int stack[100], top = -1;

int main() {
    int n;
    printf("\n Enter the size of STACK[MAX=100]: ");
    scanf("%d", &n);
    printf("\n\nSTACK OPERATIONS USING ARRAY");
    printf("\n\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
    do {
        printf("\n Enter the choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n EXIT POINT");
                break;
            default:
                printf("\n Please enter a valid choice(1/2/3/4)");
        }
    } while(choice!=4);

    void push() {
        if(top == n-1) {
            printf("\n Stack is overflow");
        }
        else {
            printf("Enter a value to be pushed: ");
            scanf("%d", &x);
            top++;
            stack[top] = x;
        }
    }

    void pop() {
        if(top == -1) {
            printf("\n Stack is underflow");
        }
        else {
            printf("\n The popped elements is %d", stack[top]);
            top--;
        }
    }

    void display() {
        if(top == -0) {
            printf("\n The elements in stack");
            for(int i=0; i<=top; i++)
                printf("%d", stack[i]);
        }
        else {
            printf("\n Press next choice");
        }
    }
}