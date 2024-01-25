#include <stdio.h>
#include <gmp.h>

#define MAX_TOTAL 722

void find_combinations_count(int total, int last_num, mpz_t memo[MAX_TOTAL + 1][MAX_TOTAL + 1], mpz_t count) {
    if (total == 0) {
        mpz_set_ui(count, 1);
        return;
    }
    if (mpz_cmp_si(memo[total][last_num], -1) != 0) {
        mpz_set(count, memo[total][last_num]);
        return;
    }

    mpz_set_ui(count, 0);
    for (int num = last_num; num <= total; ++num) {
        mpz_t temp_count;
        mpz_init(temp_count);
        find_combinations_count(total - num, num, memo, temp_count);
        mpz_add(count, count, temp_count);
        mpz_clear(temp_count);
    }

    mpz_set(memo[total][last_num], count);
}

int main() {
    mpz_t memo[MAX_TOTAL + 1][MAX_TOTAL + 1];
    for (int i = 0; i <= MAX_TOTAL; ++i) {
        for (int j = 0; j <= MAX_TOTAL; ++j) {
            mpz_init_set_si(memo[i][j], -1);
        }
    }

    for (int total = 1; total <= MAX_TOTAL; ++total) {
        mpz_t count;
        mpz_init(count);
        find_combinations_count(total, 1, memo, count);
        gmp_printf("Total = %d: (%Zd combinations)\n", total, count);
        mpz_clear(count);
    }

    // Clear the memoization array
    for (int i = 0; i <= MAX_TOTAL; ++i) {
        for (int j = 0; j <= MAX_TOTAL; ++j) {
            mpz_clear(memo[i][j]);
        }
    }

    return 0;
}

