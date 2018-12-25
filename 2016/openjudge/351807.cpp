#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
const int MOD=10007;
struct point
{
	int x,y;
}a[MAXN];
struct node
{
	int x,y;
	int next;
}Hash[MAXN];
int fisrt[MOD+1];
int tot;
int ans;
int n;

inline void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	ans=tot=0;
}

void Hash_insert(int x,int y)
{
	int h=(x*x+y*y)%MOD;
	tot++;
	Hash[tot].x=x;
	Hash[tot].y=y;
	Hash[tot].next=fisrt[h];
	fisrt[h]=tot;
}

bool Hash_search(int x,int y)
{
	int h=(x*x+y*y)%MOD;
	int next=fisrt[h];
	while(next!=-1)
	{
		if(Hash[next].x==x&&Hash[next].y==y)
			return true;
		next=Hash[next].next;
	}
	return false;
}

int main()
{
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			break;
		init();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
			Hash_insert(a[i].x,a[i].y);
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int x1 = a[i].x - (a[i].y - a[j].y);
				int y1 = a[i].y + (a[i].x - a[j].x);
				int x2 = a[j].x - (a[i].y - a[j].y);
				int y2 = a[j].y + (a[i].x - a[j].x);
				if(Hash_search(x1,y1)&&Hash_search(x2,y2))
					ans++;
			}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int x1 = a[i].x + (a[i].y - a[j].y);
				int y1 = a[i].y - (a[i].x - a[j].x);
				int x2 = a[j].x + (a[i].y - a[j].y);
				int y2 = a[j].y - (a[i].x - a[j].x);
				if(Hash_search(x1,y1)&&Hash_search(x2,y2))
					ans++;
			}
		cout<<(ans>>2)<<endl;
	}
	return 0;
}
     