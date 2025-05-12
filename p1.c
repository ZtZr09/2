#include <stdio.h>
#include <time.h>

int gcd(int x, int y) {
    int rem = x % y;
    if (rem == 0) return y;
    while (rem != 0) {
        return gcd(y, rem);
    }
    return -1;
}

void middle_school(int x, int y) {
    int temp = 1;

    if (x > y) {
        int temp_swap = x;
        x = y;
        y = temp_swap;
    }

    for (int i = 1; i <= x; i++) {
        if (x % i == 0 && y%i== 0) {
            temp = i;
        }
    }

    printf("GCD is %d\n", temp);
}

int gcd2(int x, int y) {
    int gcd = (x < y) ? x : y;

    while (gcd > 0) {
        if (x % gcd == 0 && y % gcd == 0) {
            return gcd;
        } else {
            gcd--;
        }
    }
    return 1;
}

int main() {
    clock_t st, st2, et, st1, et1, et3;

    printf("%.6f\n", 0.0); 

    st = clock();
    int res = gcd(3000000, 6900);
    et = clock();
    double time_used = ((double)(et - st)) / CLOCKS_PER_SEC;
    printf("GCD is %d\nTime Used for Euclidean: %.6f s\n", res, time_used);

    st1 = clock();
    int res1 = gcd2(3000000, 6900);
    et1 = clock();
    double time_used1 = ((double)(et1 - st1)) / CLOCKS_PER_SEC;
    printf("GCD is %d\nTime Used for Consecutive: %.6f s\n", res1, time_used1);

    st2 = clock();
    middle_school(3000000, 6900);
    et3 = clock();
    double time_used2 = ((double)(et3 - st2)) / CLOCKS_PER_SEC;
    printf("Time Used for Middle School: %.6f s\n", time_used2);

    return 0;
}
