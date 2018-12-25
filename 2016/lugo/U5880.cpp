#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100005;
int d[MAXN];
int n,m;

int er_find(int x,int l,int r)
{
	int ans=99999999;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(d[mid]<x)
			l=mid+1;
		else
			r=mid-1,ans=min(ans,mid);
	}
	return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    	scanf("%d",&d[i]);
   	int x,y,mid;
   	int k;
	for(int i=1;i<=m;i++)
   	{
   		scanf("%d%d",&x,&y);
   		mid=(d[x]+d[y])>>1;
		k=er_find(mid,x,y);
		int a1=max(d[k]-d[x],d[y]-d[k]);
		int a2=max(d[k-1]-d[x],d[y]-d[k-1]);
		if(a1<a2)
		{
			printf("%d\n%d\n",k,a1);
		}
		else
		{
			printf("%d\n%d\n",k-1,a2);
		}
	}
	return 0;
}
 
