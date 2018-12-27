#include <stdio.h>

int leapYear(int year)
{
	if((year%400==0)||(year%100!=0 && year%4==0))
		return 1;
	else
		return 0;
}

int main()
{
	int a, b, c;//a为年份，b为月份，c为日期
	scanf("%d%d%d",&a,&b,&c);
	int i, result = 0;
	for(i=1;i<=a-1;i++)
	{
		result+=(leapYear(i)+365)%7;
	}
	for(i=1;i<=b-1;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		{
			result+=31%7;
			result%=7;
		}
		else if(i==4||i==6||i==9||i==11)
		{
			result+=30%7;
			result%=7;
		}
		else if(i==2)
		{
			result+=(28+leapYear(a))%7;
			result%=7;
		}
	}
	result+=c%7;
	result%=7;
	printf("%d\n",result);
	if(result==0)
		result = 7;
	printf("%d\n",736612%7);
	return 0;
}