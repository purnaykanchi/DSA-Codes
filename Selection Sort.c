#include <stdio.h>
int *selection_sort(int *a, int n){
    int i, index, temp;
    for (i = 0; i < n - 1; i++){
        index = i;
        for (int j = i + 1; j < n; j++){
            if (*(a+j) < *(a+index)){
                index = j;
            }
        }
        temp = *(a+i);
        *(a+i) = *(a+index);
        *(a+index) = temp;
    }
    return a;
}
int main(){
    int i, a[20], n,ch;
    printf("Enter the number of terms of the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("The array is:\t");
    for (i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    selection_sort(a,n);
    printf("\n");
    printf("The array is:\t");
    for (i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    return 0;
}
