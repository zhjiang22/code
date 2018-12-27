#include<bits/stdc++.h>
using namespace std;

int sum;
int maxx;
int n;

void init()
{
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum+=x;
		maxx=max(maxx,x);
	}
}

void work()
{
	sum*=2;	sum++;
	if(sum%n==0)
		printf("%d\n",max(maxx,sum/n));
	else
		printf("%d\n",max(maxx,sum/n+1));
}

int main()
{
	init();
	work();
	return 0;
}
     