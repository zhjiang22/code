/*
水题啊
这四个数据我给满分	随便写了个dfs都过了
还是秒杀？666666
我们来看这道题
因为要求是走k城市前所有1-k-1城市都要走过
然后我们看到n就只有100
随随便便写两下dfs不就好了？
dfs传4个参数
即三个人的位置分别为x,y,z	还有一个当前花费w
递归边界是有一个人到达了n
即x==n||y==n||z==n
然后就取个所有到达的条件的最小代价就好咯~
水题
完全不用记忆化DP Orz
也可能是我太弱惹
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int INF=0x7fffff;
int d[MAXN][MAXN];
bool v[MAXN];
int n;
int ans=INF;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cin>>d[i][j];
}

void dfs(int x,int y,int z,int w)
{
	if(x==n||y==n||z==n)
	{
		ans=min(ans,w);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		bool ok=0;
		if(!v[i])
		{
			for(int j=1;j<i;j++)
				if(!v[j])	
				{
					ok=1;
					break;
				}
			if(ok)
				continue;
			v[i]=1;
			if(x<i)
				dfs(i,y,z,w+d[x][i]);
			if(y<i)
				dfs(x,i,z,w+d[y][i]);
			if(z<i)
				dfs(x,y,i,w+d[z][i]);
			v[i]=0;
		}
	}
}

int main()
{
	init();
	v[1]=1;
	dfs(1,1,1,0);
	cout<<ans<<endl;
	return 0;
}
/*
void dfs(int x,int y,int z,int w)
{
	if(x==n||y==n||z==n)
	{
		ans=min(ans,w);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		bool ok=0;
		if(!v[i])
		{
			for(int j=1;j<i;j++)
				if(!v[j])	
				{
					ok=1;
					break;
				}
			if(ok)
				continue;
			v[i]=1;
			if(x<i)
				dfs(i,y,z,w+d[x][i]);
			if(y<i)
				dfs(x,i,z,w+d[y][i]);
			if(z<i)
				dfs(x,y,i,w+d[z][i]);
			v[i]=0;
		}
	}
}
*/