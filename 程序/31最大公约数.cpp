#include<stdio.h>
int main()
{
	int a,b,x,max=0,i;
	
	scanf("%d%d",&a,&b);
	if(a==0||b==0)
	{
		max=a==0?b:a;
		printf("%d",max);
	}
	else 
	{
		if(a>b)
		{
			x=a;a=b;b=x;
		}
		max=1;
		for(i=2;i<=a;i++)
		{
			if(a%i==0)
			{
				if(b%i==0)
				max=i;
			}
		}
		printf("%d",max);
	}
	return 0;
}
