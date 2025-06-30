#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int left, int mid, int right);
void Merge_Sort(int arr[], int left, int right);

int main()
{
    int size;
    printf("Enter the size:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of array:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    Merge_Sort(arr,0,size-1);
    printf("The sorted array is:");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void merge(int arr[], int left, int mid, int right)
{
    int i,j,k;
    int size1 = mid-left+1;
    int size2 = right-mid;
    int L[size1], R[size2];  // Changed from left[] and right[] to avoid confusion
    
    for(i=0;i<size1;i++)
        L[i]=arr[left+i];
    for(j=0;j<size2;j++)
        R[j]=arr[mid+1+j];  // Fixed the index calculation
    
    i=0;
    j=0;
    k=left;
    
    while(i<size1 && j<size2)
    {
        if(L[i]<=R[j])  // Changed == to <= for proper sorting
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<size1)
    {
        arr[k]=L[i];
        i++;
        k++;  // Moved inside the loop
    }
    
    while(j<size2)
    {
        arr[k]=R[j];
        j++;
        k++;  // Moved inside the loop
    }
}

void Merge_Sort(int arr[], int left, int right)
{
    if(left<right)
    {
        int mid = left+(right-left)/2;
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);  // Fixed the parameters
        merge(arr,left,mid,right);
    }
}