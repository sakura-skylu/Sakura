#include <stdio.h>

int main() {
	float a;
	scanf("%f", &a);
	float x = a ;
	float x1;
	while (1) {
		x1 = (x + a / x) / 2;
		if (x1 - x < 1e-5 && x1 - x > -1e-5)
			break;
		x = x1;
	}
	printf("%.5f", x1);
	return 0;
}