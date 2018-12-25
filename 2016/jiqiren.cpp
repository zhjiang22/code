#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
const int L=2000;
int n,k;
int a[MAXN][2];
int v[5000][5000];
int x,y;
int maxx,maxy;
int minx=0x7ffffff,miny=0x7ffffff;
int ans;

void init()
{
	char ch;
	scanf("%d%d",&n,&k);
	getchar();
	for(int i=1;i<=n;i++)
	{
		ch=getchar();
		if(ch=='E')
			a[i][0]=1;
		else	if(ch=='W')
			a[i][0]=-1;
		else	if(ch=='S')
			a[i][1]=-1;
		else	if(ch=='N')
			a[i][1]=1;
	}
}

int main()
{
	init();
	x+=L;	y+=L;
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)
		{
			v[x][y]=1;
			x+=a[i][1];	y+=a[i][0];
			maxx=max(maxx,x);	maxy=max(maxy,y);
			minx=min(minx,x);	miny=min(miny,y);
		}
	for(int i=minx;i<=maxx;i++)
		for(int j=miny;j<=maxy;j++)
			if(v[i][j]&&v[i+1][j]&&v[i][j+1]&&v[i+1][j+1])
				ans++;
	cout<<ans<<endl;
	return 0;
}
     