#include <bits/stdc++.h>
using namespace std;

#define _for(i,a,b)	for(int i=(a);i<(b);i++)
#define _rep(i,a,b)	for(int i=(a);i<=(b);i++)

int t;
int l;
string a;
map<char,double> mapp;

void init()
{
	cin>>a;
	l=a.length();
	mapp['C']=12.01;
	mapp['H']=1.008;
	mapp['O']=16.00;
	mapp['N']=14.01;
}

inline bool is_num(const char& c)
{
	if(c=='C'||c=='H'||c=='O'||c=='N')
		return false;
	return true;
}

void work()
{
	double ans=0;
	double cur=0;
	int num=0;
	for(int i=0;i<l;i++)
	{
		if(!is_num(a[i])&&(i==l-1||!is_num(a[i+1])))
		{
			ans+=(cur*num);
			ans+=mapp[a[i]];
			num=0;
		}
		else	if(!is_num(a[i])&&is_num(a[i+1]))
		{
			ans+=(cur*num);
			cur=mapp[a[i]];
			num=0;
		}
		else
		{
			while(is_num(a[i])&&i<l)
			{
				num*=10;
				num+=(a[i]-'0');
				i++;
			}
			i--;
		}
	}
	ans+=cur*num;
	printf("%.3lf\n",ans);
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}