#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=12;
const int MAXM=18;
struct node
{
	int x,y,v;
}a[MAXM];
int s[MAXN];
int n,m,v;
int ans;

int work(int x)
{
	memset(s,0,sizeof(s));
	int sum=0;
	for(int i=0;i<m;i++)
		if((1<<i)&x)
		{
			s[a[i+1].x]+=a[i+1].v;
			s[a[i+1].y]-=a[i+1].v;
			sum+=a[i+1].v*(a[i+1].y-a[i+1].x);
		}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=s[i];
		if(ans>v)
			return -1;
	}
	return sum;
}

int main()
{
	cin>>n>>m>>v;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].v;
	for(int i=0;i<(1<<m);i++)
	{
		ans=max(ans,work(i));
	}
	cout<<ans<<endl;
	return 0;
}
     