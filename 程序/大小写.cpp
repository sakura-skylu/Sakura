#include <stdio.h>
int main()
{
	char n, m;
	scanf_s("%c", &n);
	if (n >= 'a' && n <= 'z')
	{
		m = n - 32;
		printf("%c", m);
	}
	else
		printf("%c", n);
	return 0;
}