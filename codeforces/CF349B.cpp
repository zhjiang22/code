#include<bits/stdc++.h>
using namespace std;

const int MAXN=10;
int mind=1000005;
int a[MAXN];
int n;

void init()
{
	cin>>n;	
	for(int i=1;i<=9;i++)
	{
		cin>>a[i];
		mind=min(mind,a[i]);
	}
}

void work()
{
	if(mind>n)
		printf("-1\n");
	else
	{
		int cur=n;
		for(int i=1;i<=(n/mind);i++)
			for(int j=9;j>=1;j--)
				if(((cur-a[j])/mind)>=((n/mind)-i)&&cur>=a[j])
				{
					printf("%d",j);
					cur-=a[j];
				}
		printf("\n");
	}
}

int main()
{
	init();
	work();
	return 0;
}
     