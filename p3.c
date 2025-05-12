#include <stdio.h>
#include <time.h>


void merge(int a[], int low, int mid, int high){
    int temp[high-low+1];
    int k=0;
    int left = low;
    int right = mid+1;
    while(left<=mid && right <=high){
        if(a[left] <= a[right])
            temp[k++] = a[left++];
        else
            temp[k++] = a[right++];
    }
    while(left<=mid)
        temp[k++] = a[left++];
    while(right<=high)
        temp[k++] = a[right++];

    for(int i = 0;i<k;i++)
        a[low+i] = temp[i];
}

void mergesort(int a[],int low,int high){
    if(low>=high)
        return;
    int mid = (low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
    
}
int main(){
    int a[] = {0,1,0,0,1,0,1,0,1,0,1};
    int n = sizeof(a)/sizeof(a[0]);
    clock_t st,et;
    printf("Before sorting:");
    for(int i = 0 ;i<n;i++){
        printf("%d", a[i]);
    }
    printf("After sorting:");
    st = clock();
    mergesort(a,0,n);
    et = clock();
    for(int i = 0;i<n;i++){
        printf("%d", a[i]);
    }
    double tt = (double)(et-st)/CLOCKS_PER_SEC;
    printf("Time taken: %f", tt);
}
