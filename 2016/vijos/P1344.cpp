/*
一道字符串处理题
OTZ竟然写了快半个小时
我太弱了Orz肿么办
NOIP又要被虐了QWQ
这种题目做法无数啊也没有啥固定的思路
反正我都是随便想个思路写一步试一步
然后慢慢地改正细节错误
然后再做几个可能没有注意到的地方的数据
这道题就是有的地方没有注意好调了一会
总体思路还是挺清楚的
我们可以用一个sum和t
分别记录常数项移到左边的总和和变量移到左边的系数
然后模拟一个一个字符串处理
因为只有+ -所以其实很好写的
注意一些标记变量的用法和及时的清零等细节就好
然后直接解方程除法就好了
水题OTZ
我好水啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
string a;
int sum;
char bian;

int check(char x)
{
	if(x<='9'&&x>='0')
		return 1;
	else	if(x<='z'&&x>='a')
		return 2;
	else	return 3;
}

int main()
{
	cin>>a;
	char ch;
	int num=0;
	bool fu=0;
	int i=0;
	int l=a.length();
	while(i!=l)
	{
		ch=a[i++];
		int d=check(ch);
		if(d==2)
		{
			if(fu)
			{
				t-=num;
				num=0;
			}
			else
			{
				t+=num;
				num=0;
			}
			bian=ch;
		}
		else	if(d==1)
			num=(num*10)+(ch-'0');
		else	if(d==3)
		{
			if(fu)
			{
				sum-=num;
				num=0;
			}
			else
			{
				sum+=num;
				num=0;
			}
			if(ch=='-')
				fu=1;
			else	
				fu=0;
		}
		if(ch=='=')
			break;
	}
	while(i!=l)
	{
		ch=a[i++];
		int d=check(ch);
		if(d==2)
		{
			if(fu)
			{
				t+=num;
				num=0;
			}
			else
			{
				t-=num;
				num=0;
			}
			bian=ch;
		}
		else	if(d==1)
			num=(num*10)+(ch-'0');
		else	if(d==3)
		{
			if(fu)
			{
				sum+=num;
				num=0;
			}
			else
			{
				sum-=num;
				num=0;
			}
			if(ch=='-')
				fu=1;
			else	
				fu=0;
		}
	}
	if(fu)
		sum+=num;
	else
		sum-=num;
	double ans=(double)(-sum)/t;
	cout<<bian<<"=";
	printf("%.3lf\n",ans);
	return 0;
}
