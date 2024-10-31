#include <stdio.h>
int isrunyear(int year)
{
	return((year % 4 == 0 && year % 400 != 0 || year % 100 == 0) == 0);
}

int main()
{
	int y,month = 0;
	int d;
	char months[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf_s("%d %d", &y, &d);
	if (isrunyear(y))
	{
		months[1] = 29;
		while (d > months[month])
		{
			d -= months[month];
			month++;
		}
	else
		month[1] = 28;
	while (d > months[month])
	{
		d -= months[month];
		month++;
	}
	}
	printf("%d %d", month+1, d+1);
	return 0;
}

