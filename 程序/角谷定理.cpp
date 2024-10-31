#include <stdio.h>
int main()
{
	int n, count;
	scanf_s("%d", &n);
	for (count = 0; n != 1; count++)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
	}
	printf("%d", count);
	return 0;

}