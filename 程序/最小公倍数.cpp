#include <stdio.h>
int main()
{
	int a,b,i,max,num,min;
	scanf("%d %d",&a,&b);
	for(i=2;i<=a;i++)
		{
			if(a%i==0)
			{
				if(b%i==0)
				max=i;
			}
		}
	if(a>b)
	{
	num=a;
	min=b;}
	else
	{num=b;
	min=a;}
	max=a*b/max;
	printf("%d %d %d",min,num,max);
	return 0;
}
