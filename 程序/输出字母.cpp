#include<stdio.h>
void format(void);

int main()
{
	int i;

	for (i = 97; i <= 122; i++)
	{
		printf("%c", i);
		format();
	}
	for (i = 122; i >= 97; i--)
	{
		printf("%c", i);
		format();
	}
	return 0;
}
void format()
{
	static int m = 0;
	m++;
	if (m<26)
	{
		printf(" ");
	}
	else
	{
		printf("\n");
		m = 0;
	}
	return;
}