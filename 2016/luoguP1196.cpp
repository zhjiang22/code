#include <bits/stdc++.h>
using namespace std;

const int MAXN=30005;
int size[MAXN];
int fa[MAXN];
int d[MAXN];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=30004;i++)
		fa[i]=i,size[i]=1;
	for(int i=1;i<MAXN;i++)
		d[i]=0;
}

int getfather(const int& x)
{
	if(fa[x]==x)
		return x;
	int father=fa[x];
	int fx=getfather(fa[x]);
	d[x]+=d[father];
	return fa[x]=fx;
}

void work()
{
	char c;
	int x,y;
	while(n--)
	{
		cin>>c;
		scanf("%d%d",&x,&y);
		if(c=='M')
		{
			int fx=getfather(x);
			int fy=getfather(y);
			d[fx]=size[fy];

			fa[fx]=fy;
			size[fy]+=size[fx];
		}
		else
		{
			
			if(getfather(x)!=getfather(y))
				printf("-1\n");
			else
			{
				/*for(int i=1;i<=5;i++)
				cout<<d[i]<<" ";
			cout<<endl;
			for(int i=1;i<=5;i++)
				cout<<fa[i]<<" ";
			cout<<endl;*/
				printf("%d\n",abs(d[x]-d[y])-1);
				/*cout<<endl;*/
			}
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}