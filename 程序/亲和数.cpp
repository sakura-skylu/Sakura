#include <stdio.h>
int main()
{
	int n,m;
	int count1=0;
	int count2=0;
	int sum1=0;
	int sum2=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{	sum1+=i;
		count1++;}
		else
		continue;
	 } 
	 for(int j=1;j<m;j++)
	{
		if(m%j==0)
		{
		sum2+=j;
		count2++;}
		else
		continue;
	 } 
	 if(sum1==m&&sum2==n)
	 {
	 printf("yes %d %d",count1,count2);}
	 else
	 {
	 printf("no %d %d",count1,count2);}
	 return 0;
	 
}
