/* fastest-primes: count primes <= N (1 <= N <= 5,000,000).
 * Odd-only Sieve of Eratosthenes. Reads N from stdin, prints pi(N).
 * Compile: cc -O3 -o primes primes.c
 * Run:     echo 1000000 | ./primes   -> 78498
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    long n;
    if (scanf("%ld", &n) != 1) return 0;
    if (n < 2) { puts("0"); return 0; }
    if (n == 2) { puts("1"); return 0; }

    /* is_comp[i] covers odd number 2*i+1, i = 1 .. (n-1)/2 */
    long m = (n + 1) / 2;                 /* count of odds <= n (incl. 1) */
    unsigned char *is_comp = malloc(m);
    if (!is_comp) return 1;
    memset(is_comp, 0, m);

    for (long p = 3; p * p <= n; p += 2) {
        if (!is_comp[p >> 1]) {
            long step = p << 1;
            for (long j = p * p; j <= n; j += step)
                is_comp[j >> 1] = 1;
        }
    }
    long cnt = 1;                          /* prime 2 */
    for (long i = 1; i < m; i++)
        if (!is_comp[i]) cnt++;
    free(is_comp);
    printf("%ld\n", cnt);
    return 0;
}
