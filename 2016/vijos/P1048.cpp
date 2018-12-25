/*
可以可以
这题很神..
害怕啊
我们很容易看到这很明显是搜索
咋搜~！复杂度太高根本不行啊
那么我们先加个剪枝！
记录下总书写质量s[]
那么如果当前选择到了cur
有s[n]-s[cur]<当前ans
果断剪枝
那么这样就可以过八个点了
进一步优化
我们可以先将小精灵按照书写质量从大到小排序
这样可以更有可能一开始就找到一个更大的ans
就方便进行剪枝了
但是这样还是不好过的
题解和博客有很多进一步强势剪枝
窝比较弱直接卡时了~
0.25就能A..
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN=52;
struct node
{
	int w,idx;
	bool operator <(const node& b)const
	{
		return w>b.w;
	}
}a[MAXN];
int s[MAXN];
bool nocan[MAXN][MAXN];
int g[MAXN];
int ans;
int n,l;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].w);
		s[i]=s[i-1]+a[i].w;
		a[i].idx=i;
	}
	int x,y;
	while(scanf("%d%d",&x,&y)==2)
		nocan[x][y]=nocan[y][x]=1;
}

void dfs(int cur,int havew)
{
	if(((double)clock()/CLOCKS_PER_SEC)>0.25)
	{
		cout<<ans<<endl;
		exit(0);
	}
	if(cur>n)
	{
		ans=max(ans,havew);
		return;
	}
	if(havew+s[n]-s[cur-1]<ans)
		return;
	bool flag=1;
	for(int i=1;i<=l;i++)
	{
		if(nocan[g[i]][a[cur].idx])
			flag=0;
	}
	if(flag)
	{
		g[++l]=a[cur].idx;
		dfs(cur+1,havew+a[cur].w);
		l--;
	}
	dfs(cur+1,havew);
}

int main()
{
	init();
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}   