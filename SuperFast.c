#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_upper_bound(int n) {
    if (n == 0) return 1;
    return calculate_upper_bound(n - 1) + (1 << ((n / 2) - 1));
}

void find_combinations_count(int total, int *count, int last_num) {
    if (total == 0) {
        *count = 1;
        return;
    }

    *count = 0;
    for (int num = last_num; num <= total; ++num) {
        int sub_count = 0;
        find_combinations_count(total - num, &sub_count, num);
        *count += sub_count;
    }
}

int main() {
    int max_num = 99;
    
    for (int total = 1; total <= max_num; ++total) {
        int count = 0;
        find_combinations_count(total, &count, 1);
        printf("Total = %d: (%d combinations)\n", total, count);
    }

    return 0;
}
