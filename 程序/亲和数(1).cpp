#include <stdio.h>

int main () {
	int n, m, sum1 = 0, sum2 = 0;
	int i1 = 0, i2 = 0;
	scanf("%d %d", &n, &m);
	for (int x = 1; x < n; x++) {
		if (n % x == 0) {
			sum1 += x;
			i1++;
		}
	}
	for (int y = 1; y < m; y++) {
		if (m % y == 0) {
			sum2 += y;
			i2++;
		}
	}
	if (sum1 == m && sum2 == n)
		printf("yes ");
	else
		printf("no ");
	printf("%d %d", i1, i2);
	return 0;
}