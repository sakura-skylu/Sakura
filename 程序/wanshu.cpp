#include <stdio.h>
int main()
{
	int a,b,m,i,sum;
	scanf("%d %d",&a,&b);
	for(m=a;m<=b;m++)
	{
		int sum=0;
		for(i=1;i<m;i++)
		{
			if(m%i==0)
			sum+=i;
		}
	if(sum==m)
	printf("%d\n",m);
}
return 0;}
