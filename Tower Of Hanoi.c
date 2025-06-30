#include <stdio.h>

void towers(int num, char fromPeg, char toPeg, char auxPeg) {
    if (num == 1) {
        printf("\nMove disc 1 from peg %c to peg %c", fromPeg, toPeg);
        return;
    }
    towers(num - 1, fromPeg, auxPeg, toPeg);
    printf("\nMove disc %d from peg %c to peg %c", num, fromPeg, toPeg);
    towers(num - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    int num;
    printf("Enter the number of discs: ");
    scanf("%d", &num);
    printf("The sequence of moves involved are:\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}