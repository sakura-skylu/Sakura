#include <stdio.h>
int main()
{
	int n;
	int m = 0;
	scanf_s("%d", &n);
	while (n != 0)
	{
		m += (n % 10);
		n /= 10;
	}
	printf("%d", m);
	return 0;
}
