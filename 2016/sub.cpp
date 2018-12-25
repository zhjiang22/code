#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=520;

	string x,y;
int a[MAXN],b[MAXN],c[MAXN];
int c1,c2,s;

void init()
{
	for(int i=0;i<c1;i++)
	a[i]=x[c1-i-1]-'0';
	for(int i=0;i<c2;i++)
	b[i]=y[c2-i-1]-'0';
}

void powder(int a[],int b[],int on)
{
	for(int i=0;i<s;i++)
	{
		if(a[i]<b[i])
		{
		a[i+1]--;
		a[i]+=10;
		}
		c[i]=a[i]-b[i];
	}
	for(int i=s-1;i>=0;i--)
	if(c[i]==0)
	s--;
	else
	break;
	if(on)
	c[s-1]=-c[s-1];
	for(int i=s-1;i>=0;i--)
	cout<<c[i];
}

int main()
{
	freopen("sub.in","r",stdin);
	freopen("sub.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>x>>y;
	c1=x.length();
	c2=y.length();
	s=max(c1,c2);
	init();
	if(c1>c2)
	powder(a,b,0);
	else if(c1<c2)
	powder(b,a,1);
	else
	{
		if(x==y)
		{
			cout<<"0";
			return 0;
		}
		else if(x<y)
		powder(b,a,1);
		else
		powder(a,b,0);
	}
	return 0;
}