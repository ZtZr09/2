#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int findPivot(int a[], int low, int high){
    int pivot = a[low];
    int i= low;
    int j = high;
    while(i<j){
         while(i<= high && a[i] <= pivot)
             i++;
         while(j >= low && a[j] > pivot)
             j--;
         if(i<j)
             swap(&a[i],&a[j]); 
    }
    swap(&a[low],&a[j]);
    return j;
}
void quicksort(int a[],int low, int high){
    if(low<high){
        int pivot = findPivot(a,low,high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}
void printarr(int a[], int n)
{
        for(int i = 0;i<n;i++)
        printf("%d ",a[i]);
}
int main(){
    int a[] = {12,43,4,5,2,6,7,83,76,87};
    int n = sizeof(a)/sizeof(a[0]);
    clock_t st,et;
    printf("Before sorting");
    printarr(a,n);
    printf("After sorting:");
    st = clock();
    quicksort(a,0,n-1);
    et = clock();
    printarr(a,n);
    double tt = ((double)(et-st))/CLOCKS_PER_SEC;
    printf("Time taken: %f", tt);
}

