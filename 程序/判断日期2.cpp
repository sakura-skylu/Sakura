# include<stdio.h>
int isyear(int year);
int main()
{
	int year, day, i;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf_s("%d %d", &year, &day);
	if (isyear(year))
		month[1] = 28;
	else
		month[1] = 29;
	for (i = 0; day >=month[i]; i++)
		day -= month[i];
	printf("%d %d", i+1, day+1);
	return 0;

}
int isyear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	return 0;
}