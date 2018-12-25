#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[5200],b[5200],c[5200];

int main()
{
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	memset(a,0,sizeof(a));
	memchr(b,0,sizeof(b));
	memchr(c,0,sizeof(c));
	string x,y;
	cin>>x>>y;
	int l1=x.length();
	int l2=y.length();
	for(int i=0;i<l1;i++)
	a[i]=x[l1-i-1]-'0';
	for(int i=0;i<l2;i++)
	b[i]=y[l2-i-1]-'0';
	int s=max(l1,l2);
	int i=0;
	int z=0;
	while(i<s)
	{
		c[i]=a[i]+b[i]+z;
		z=c[i]/10;
		c[i]%=10;
		i++;
	}
	c[i]=z;
	if(c[i])
	for(int j=s;j>=0;j--)
	cout<<c[j];
	else
	for(int j=s-1;j>=0;j--)
	cout<<c[j];
	return 0;
}