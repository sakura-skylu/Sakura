#include <stdio.h>
int main()
{
	int a, b, max, min;
	scanf_s("%d%d", &a, &b);
	if (a > b)
		max = a, min = b;
	else
		max = b, min = a;
	printf("%d %d", max % 10, min * min);
	return 0;
}