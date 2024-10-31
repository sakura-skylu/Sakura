#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 999 && n >= 100)
	{
		if (n == pow(n % 10, 3) + pow(n / 10 % 10, 3) + pow(n / 100 % 10, 3))
			printf("Yes");
		else
			printf("No");
	}
	else
		printf("-1");
	return 0;
}
