#include <stdio.h>

int main(void) {
	int number = 0;
	int times = 0, mi = 1, save = 0, situation = 0, mult = 0;
	scanf("%d", &number);
	if (number % 2 == 1) {
		printf("-1");
		return 0;
	}
	save = number;
	do {
		save /= 2;
		times++;
	} while (save > 1);
	while (number != 0) {
		while (mult != times) {
			mi *= 2;
			mult++;
		}
		if (number - mi >= 0) {
			number -= mi;
			printf("%d ", mi);
			if (number - mi == 0)
				return 0;
			mult--;
			times--;
			mi /= 2;
		} else {
			mult--;
			times--;
			mi /= 2;
		}
	}
	printf("\b");
	return 0;
}
