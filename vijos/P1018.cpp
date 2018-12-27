/*
楼天城浅谈部分搜索+高效算法在搜索问题中的应用论文不解释~
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxm=100+2;
const int maxn=100+2;

int n,m,dist[maxm],MaxT[maxm][maxn];
bool reachable[maxm][maxn],*can[maxm][maxm];
/*
m=B国武器数。
n=A国炸弹数。
dist[i]=如果A国炸弹可以重复使用，炸掉B国武器I~m的最少使用炸弹数。
MaxT[s][i]=炸弹I，从S开始炸，可以炸到的最大编号，
           如果炸弹I炸不到S，则MaxT[I][S]=S-1。
reachable[i][j]=A国炸弹i是否可以炸到B国炸弹j。
can[s][t][i]=表示A国炸弹I是否可以炸到B国武器S,S+1..T-1,T。
*/
int answer,bestv[maxn];
/*
answer=最少需要的A国炸弹数。
bestv=记录取最优解A国炸弹的使用序列。
*/
int a[maxm],b[maxn];
bool vis[maxn],*g[maxm];
/*
a[i],b[i]用于匹配，分别记录左（右）第i个点的匹配边的另一个点的编号，如果没有匹配则为0。
vis[i]用于匹配和宽度优先搜索时判重。
g[i][j]=左边第i个点到右边第j个点是否有边。
*/
void init()
{
	//读入数据并计算reachable。
	int x1[maxm],y1[maxm],x2[maxn],y2[maxn],i,j,R;
	scanf("%d%d%d",&m,&n,&R);
	for (i=1;i<=m;i++)
		scanf("%d%d",&x1[i],&y1[i]);
	for (i=1;i<=n;i++)
		scanf("%d%d",&x2[i],&y2[i]);
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			reachable[i][j]=((x1[i]-x2[j])*(x1[i]-x2[j])+(y1[i]-y2[j])*(y1[i]-y2[j])<=R*R);
}
void preprocess()
{
	//初始化，计算can,MaxT。
	int s,t,i;
	for (i=1;i<=m;i++)
		g[i]=new bool[maxn];
	for (s=1;s<=m;s++)
		for (t=s;t<=m;t++)
			can[s][t]=new bool[maxn];
	for (s=1;s<=m;s++)
	{
		for (i=1;i<=n;i++)
			can[s][s][i]=reachable[s][i];
		for (t=s+1;t<=m;t++)
			for (i=1;i<=n;i++)
				can[s][t][i]=can[s][t-1][i] && reachable[t][i];
		for (i=1;i<=n;i++)
		{
			MaxT[s][i]=s-1;
			for (t=s;t<=m;t++)
				if (can[s][t][i])
					MaxT[s][i]=t;
		}
	}
	//计算dist
	dist[m+1]=0;
	for (s=m;s>=1;s--)
	{
		t=s-1;
		for (i=1;i<=n;i++)
			if (MaxT[s][i]>t)
				t=MaxT[s][i];
		dist[s]=1+dist[t+1];
	}
}
bool find(int v)
{
	//匈牙利算法找可增广路。
	for (int i=1;i<=n;i++)
		if (g[v][i] && !vis[i])
		{
			vis[i]=true;
			if (b[i]==0 || find(b[i]))
			{
				a[v]=i;
				b[i]=v;
				return true;
			}
		}
	return false;
}
void search(int used,int s)
{
	//状态：已经使用了used个A国炸弹，编号在s之前的B国武器都已经炸毁。
	
	if (used+dist[s]>=answer)//优化一：最优性剪枝
		return;
	if (s==m+1)
	{
		//如果B国武器已经全部炸毁，更新最优解，回溯。
		answer=used;
		return;
	}
	int t,maxL,tempa[maxm],tempb[maxn],op,cl,queue[maxn],k,i;
	//宽度优先搜索计算出下一个划分的最大长度maxL
	memset(vis,false,sizeof(vis));
	maxL=s-1;
	op=cl=0;
	for (i=1;i<=n;i++)
		if (b[i]==0)
		{
			vis[i]=true;
			queue[++op]=i;
		}
	while (cl<op)
	{
		k=queue[++cl];
		if (MaxT[s][k]>maxL)
			maxL=MaxT[s][k];
		for (i=1;i<=used;i++)
			if (g[i][k] && !vis[a[i]])
			{
				vis[a[i]]=true;
				queue[++op]=a[i];
			}
	}
	if (maxL==s-1)
		return;
	used++;
	memcpy(tempa,a,sizeof(a));
	memcpy(tempb,b,sizeof(b));
	memset(vis,false,sizeof(vis));
	g[used]=can[s][maxL];
	//扩展交错路。
	find(used);
	//从大到小枚举下一段的长度。
	for (t=maxL;t>=s;t--)
	{
		g[used]=can[s][t];
		search(used,t+1);
	}
	memcpy(a,tempa,sizeof(a));
	memcpy(b,tempb,sizeof(b));
}
void out()
{
	//输出结果。
	printf("%d\n",answer);
}
int main()
{
	init();
	preprocess();
	answer=1000000000;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	search(0,1);
	out();
	return 0;
}
