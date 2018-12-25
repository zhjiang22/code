#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=25;
int v[MAXN<<1];
int a[MAXN];
int n,l;
char color[MAXN];
int c[MAXN];
int k;
int sum;

void init()
{
	char ch;
	int t,sum=0;
	cin>>n;
	while(1)
	{
		cin>>ch>>t;
		if(ch=='Q')
			break;
		color[++l]=ch;
		c[l]=t;
		sum+=t;
	}
	k=n-sum;
}

void print()
{
	for(int i=1;i<=l+k;i++)
	{
		if(a[i]<=l&&a[i]>=1)
		{
			for(int j=1;j<=c[a[i]];j++)
				printf("%c",color[a[i]]);
		}
		else
			cout<<" ";
	}
	cout<<endl;
}

void dfs(int cur)
{
	if(cur==l+k+1)
	{
		sum++;
		print();
		return;
	}
	for(int i=1;i<=l+k;i++)
		if(!v[i])
			if((i<=l&&a[cur-1]>l)||i>l)
			{
				v[i]=1;
				a[cur]=i;
				dfs(cur+1);
				v[i]=0;
			}
}

int main()
{
	init();
	
}
     