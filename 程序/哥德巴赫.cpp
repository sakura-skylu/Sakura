#include <stdio.h>
int prime(int n);
int main()
{
	int n;
	scanf("%d",&n);
	if(n==2)
	printf("1 1");
	for(int i=2;i<=n/2;i++)
	{
		if(prime(i)&&prime(n-i))
	{
			printf("%d %d",i,n-i);
		break;}}
	return 0;

}
int prime(int n)
{
	for(int j=2;j*j<n;j++)
	{
			if(n%j==0)
		{
		return 0;}
	}
	return 1;
}
