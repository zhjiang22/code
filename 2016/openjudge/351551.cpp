#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
const int MOD=100000007;
const int INF=0x7fffff;
struct node
{
	int x;
	int p,q;
	int next;
}Hash[MOD+1];
int fisrt[MOD+1];
int a[MAXN];
int ans;
int tot;
int n;

void init()
{
	cin>>n;
	if(n==0)
		exit(0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(fisrt,-1,sizeof(fisrt));
	ans=-INF;
}

void Hash_insert(int x,int i,int j)
{
	int h=(x%MOD+MOD)%MOD;
	tot++;
	Hash[tot].x=h;
	Hash[tot].p=i;
	Hash[tot].q=j;
	Hash[tot].next=fisrt[h];
	fisrt[h]=tot;
}

bool Hash_search(int x,int i,int j)
{
	int h=(x%MOD+MOD)%MOD;
	int cur=fisrt[h];
	while(cur!=-1)
	{
		if(Hash[cur].x==x&&Hash[cur].p!=i&&Hash[cur].q!=j)
			return 1;
		cur=Hash[cur].next;
	}
	return 0;
}

int main()
{
	while(1)
	{
		init();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					Hash_insert(a[i]+a[j],i,j);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					if(Hash_search(a[i]-a[j],i,j))
						ans=max(ans,a[i]);
		if(ans==-INF)
			cout<<"no solution"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
     