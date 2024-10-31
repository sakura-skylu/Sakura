#include <stdio.h>
#include <math.h>
int main()
{
	int n1,n2;
	float h1 = 7.86, h2 = 19.3;
	float m1, m2;
	scanf("%d %d", &n1, &n2);
	m1 = 4.0 * pow(n1 / 10 / 2, 3) * 3.1415926 * h1 / 3.0;
	m2 = 4.0 * pow(n2/ 10 / 2, 3) * 3.1415926 * h2 / 3.0;
	printf("%.3f %.3f", m1, m2);
	return 0;
}
