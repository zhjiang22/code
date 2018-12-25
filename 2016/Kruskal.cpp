#include<iostream>
#include<algorithm>
using namespace std;
const int INF=9999999;
const int MAXN=2000;
int n,e;

struct node
{
	int x,y,w;
}a[MAXN];

int dad[MAXN];

int cmp(node a,node b)
{
	return	a.w<b.w; 
}

int getfather(int x)
{
	if(!dad[x])
		return x;
	return dad[x]=getfather(dad[x]);
}

void Kruskal()
{
		int p=1,ans=0;
		for(int i=1;i<=e;i++)
		{
			if(getfather(a[i].x)!=getfather(a[i].y))
			{
				ans+=a[i].w;
				dad[getfather(a[i].x)]=a[i].y;
				p++;
				if(p==n)
				{
				cout<<ans;
				return;
				}
			}
		}
		
}

int main()
{
		freopen("F:\\1.txt","r",stdin);
	cin>>n>>e;
	for(int i=1;i<=e;i++)
		cin>>a[i].x>>a[i].y>>a[i].w;
		sort(a+1,a+e+1,cmp);
	
	Kruskal();
	return 0;
}
