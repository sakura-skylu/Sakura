#include<stdio.h>
int main()
{
	int math[] = { 0 };
	int n, m;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i <= (n-1); i++)
		math[i] = 1;
	for (int k = 2; k <= m; k++)//������ѭ��
	{
		for (int j = 1; j <= n; j++)//�Ƶı�ŵ�ѭ��
		{
			if (j % k == 0)
			{
				if (math[j - 1] == 1)
					math[j - 1] = 0;
				else if (math[j - 1] == 0)
					math[j - 1] = 1;
			}
		}
	}
	for (int q = 0; q <= n - 1; q++)
	{
		if (math[q] == 1)
			printf("%d ", (q + 1));
	}
	return 0;
}