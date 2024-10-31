
#include <stdio.h>

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void goldbachConjecture(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            printf("%d %d\n", i, n - i);
            return;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    goldbachConjecture(n);
    return 0;
}
