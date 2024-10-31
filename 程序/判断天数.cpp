#include <stdio.h>
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}
int main()
{
	int n,m,day;
	scanf("%d %d",&n,&m);
	if(m==2)
	{
		if(isLeapYear(n)==1)
		day=29;
		else
		day=28;
	}
	else
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		day=31;
	if(m==4||m==6||m==9||m==11)
	day=30;

printf("%d",day);
	return 0;}
	
