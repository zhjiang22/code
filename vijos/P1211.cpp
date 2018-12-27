/*
水题直接乱搞不想多说
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int y,m,d;
int day[13];

void init()
{
	day[1]=31;	day[2]=28;	day[3]=31;	day[4]=30;
	day[5]=31;	day[6]=30;	day[7]=31;	day[8]=31;
	day[9]=30;	day[10]=31;	day[11]=30;	day[12]=31;
}

int main()
{
	init();
	cin>>y>>m>>d;
	for (int i=1;i<=10000;i++)
	{
		if (y%4==0)
			day[2]=29;
		else day[2]=28;
			d++;
		if (d>day[m])
			m++,d=1;
		if (m==13)
			m=1,y++;
	}
	cout<<y<<"-"<<m<<"-"<<d<<endl;
	return 0;
}