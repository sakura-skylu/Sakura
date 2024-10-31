# include <stdio.h>
int main()
{
	int count = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for(int k=1;k<=4;k++)
				if (i != j && i != k && j != k)
				{
					printf("%d\n", i * 100 + j * 10 + k);
					count++;
				}
		}
	}
	printf("%d", count);
	return 0;
}