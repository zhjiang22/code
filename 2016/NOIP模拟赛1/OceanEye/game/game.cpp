#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1000000;

struct matrix
{
	int a[5010][5010];
	matrix()
	{
		memset(a, 0x3f, sizeof(a));
	}
};

matrix map,ans;

int n,i,j,k;

int read()
{
	char ch=getchar();
	while(ch==' '||ch=='\n') ch=getchar();
	return ch-48;
}

void get_ans(int x)
{
	int y,z;
	for(int i=1;i<=n;i++) if(ans.a[x][i]==1)
			for(int j=1;j<=n;j++) if(ans.a[i][j]==1) 
				if(ans.a[j][x]==1)
				{
					printf("%d %d %d\n",x,i,j);
					break;
				}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n); int m=n;
	int cur;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cur=read();
			if (cur==0) continue;
			map.a[i][j] = cur;
		}
	ans = map;
			int ii,jj,kk;
			for(kk=1;kk<=n;kk++)
				for(ii=1;ii<=n;ii++)
					for(jj=1;jj<=n;jj++)
					if(map.a[ii][kk] + ans.a[kk][jj] < ans.a[ii][jj])
					ans.a[ii][jj] = map.a[ii][kk] + ans.a[kk][jj];
	for(i=1;i<=n;i++) if(ans.a[i][i]==3)
	{
		get_ans(i);
		return 0;
	}
	return 0;
}

