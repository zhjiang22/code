#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
string a[MAXN];
int v[MAXN];
int n,m;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
}

int find(string x)
{
	int l=1;	int r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==x)
			return mid;
		else	if(a[mid]<x)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}

int main()
{
	init();
	string a;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		cin>>a;
		int x=find(a);
		if(x==-1)
			printf("WRONG\n");
		else if(!v[x])
			printf("OK\n"),v[x]=1;
		else	
			printf("REPEAT\n");
	}
	return 0;
}
     