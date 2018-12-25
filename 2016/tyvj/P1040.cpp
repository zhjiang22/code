#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1550;
char c[MAXN];
struct bign
{
	int a[MAXN];
	int len;
	bign()
	{
		memset(a,0,sizeof(a));
		len=1;
	}
	void operator =(const char c[])
	{
		len=strlen(c);
		for(int i=len;i>=1;i--)
			a[i]=c[len-i]-'0';
	}
	bign operator +(const bign& c)
	{
		bign p;	p.len=max(len,c.len)+1;
		for(int i=1;i<=p.len;i++)
		{
			p.a[i]+=a[i]+c.a[i];
			p.a[i+1]+=p.a[i]/10;
			p.a[i]%=10;
		}
		while(p.a[p.len]==0)
			p.len--;
		return p;
	}
};

bool isnum(char ch)
{
	return ch>='0'&&ch<='9';
}

int main()
{
	char ch;
	bign p;
	bign ans;
	int l=0;
	while(scanf("%c",&ch)==1)
	{
		if(isnum(ch))
			c[l++]=ch;
		else
		{
			c[l++]='\0';
			p=c;
			c[0]='\0';
			l=0;
			ans=ans+p;
			memset(p.a,0,sizeof(p.a));
			p.len=1;
		}
	}
	c[l++]='\0';
	p=c;
	ans=ans+p;
	for(int i=ans.len;i>=1;i--)
		cout<<ans.a[i];
	return 0;
}
     