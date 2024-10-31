#include<stdio.h>
int pow(int n);
int main()
{   int math[20];
	int n;
	int num=0,count=0; 
	scanf("%d",&n);
	int m=n;
	while(m!=0)
	{
		if(m%2==1)
		{
		math[num]=pow(count);
		num++;}
		count++;
		m/=2;
	}
	for(int i=num-1;i>=0;i--)
	printf("%d ",math[i]);
	return 0;
}
int pow(int n)
{   int m=1;
	for(int i=1;i<=n;i++)
	m*=2;
	return m;
}
