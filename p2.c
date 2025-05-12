#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void LinearSearch(int *nums, int n) {
    int ele;
    printf("Enter element: ");
    scanf("%d", &ele);

    for (int i = 0; i < n; i++) {
        if (nums[i] == ele) {
            printf("%d is found at position: %d\n", ele, i + 1);
            return;
        }
    }
    printf("Element not found\n");
}

int recursiveBinarySearch(int *nums, int ele, int low, int end) {
    int mid = (low + end) / 2;

    if (nums[mid] == ele) {
        return mid;
    }

    if (nums[mid] > ele) {
        return recursiveBinarySearch(nums, ele, low, mid - 1);
    }

    return recursiveBinarySearch(nums, ele, mid + 1, end);
}

int binarySearch(int *arr, int n, int ele) {
    int beg = 0;
    int end = n - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;

        if (arr[mid] == ele) {
            return mid;
        }

        if (arr[mid] > ele) {
            end = mid - 1;
        }

        if (arr[mid] < ele) {
            beg = mid + 1;
        }
    }
    return -1;
}

int main() {
    clock_t st, et;
    int arr[10000];

    for (int i = 0; i < 10000; i++) {
        arr[i] = i + 1;
    }

    // Linear Search
    st = clock();
    LinearSearch(arr, 10000);
    et = clock();
    double time_used = ((double)(et - st)) / CLOCKS_PER_SEC;
    printf("\nTime for Linear Search: %.6f s\n", time_used);

    // Recursive Binary Search
    clock_t st1, et2;
    st1 = clock();
    int res = recursiveBinarySearch(arr, 9992, 0, 9999);
    printf("Found in position (recursive): %d\n", res);
    et2 = clock();
    double time_used1 = ((double)(et2 - st1)) / CLOCKS_PER_SEC;
    printf("Time for Recursive Binary Search: %.6f s\n", time_used1);

    // Iterative Binary Search
    clock_t st2, et3;
    st2 = clock();
    int res1 = binarySearch(arr, 10000, 9992);
    printf("Found in position (iterative): %d\n", res1);
    et3 = clock();
    double time_used2 = ((double)(et3 - st2)) / CLOCKS_PER_SEC;
    printf("Time for Iterative Binary Search: %.6f s\n", time_used2);

    return 0;
}
