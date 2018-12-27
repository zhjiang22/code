/*
QAQ写了四十多分钟
真恶心唉还是我基础功不好Orz
真心给跪啊
不过还好
竟然直接一遍过了
还用了好多小数据测试
rp果然++了
233333333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int p1,p2,p3;
string a;

bool isnum(char x)
{
	return (x<='9'&&x>='0');
}

bool isxiao(char x)
{
	return (x<='z'&&x>='a');
}

void work(char x,char y,int l)
{
	if(p1==3)
	{
		for(int i=1;i<=(y-x-1)*p2;i++)
					cout<<'*';
		return;
	}
	else	if(p1==1)
	{
			if(p3==1)
			{
				for(int i=x+1;i<y;i++)
						for(int j=1;j<=p2;j++)
							cout<<char(i);
			}
			else	if(p3==2)
			{
				for(int i=y-1;i>x;i--)
					for(int j=1;j<=p2;j++)
						cout<<char(i);
			}
	}
	else	if(p1==2)
	{
		if(isxiao(x)&&isxiao(y))
		{
			if(p3==1)
			{
				for(int i=x+1;i<y;i++)
						for(int j=1;j<=p2;j++)
							cout<<char(i-('a'-'A'));
			}
			else	if(p3==2)
			{
				for(int i=y-1;i>x;i--)
					for(int j=1;j<=p2;j++)
						cout<<char(i-('a'-'A'));
			}
		}
		else
		{
			if(p3==1)
			{
				for(int i=x+1;i<y;i++)
						for(int j=1;j<=p2;j++)
							cout<<char(i);
			}
			else	if(p3==2)
			{
				for(int i=y-1;i>x;i--)
					for(int j=1;j<=p2;j++)
						cout<<char(i);
			}
		}
	}
}

void check(int x)
{
	char s=a[x-1];
	char e=a[x+1];
	bool ok=0;
	if((isnum(s)&&isnum(e))||(isxiao(s)&&isxiao(e)))
		if(s<e)
			ok=1;

	if(ok)
	{
		if(s==e-1)
			return;
		else
			work(s,e,x);
	}
	else
	{
		cout<<"-";
	}
}

int main()
{
	cin>>p1>>p2>>p3;
	cin>>a;
	int l=a.length();
	for(int i=0;i<l;i++)
	{
		if(a[i]!='-')
			cout<<a[i];
		else
		{
			check(i);
		}
	}
	return 0;
}
     