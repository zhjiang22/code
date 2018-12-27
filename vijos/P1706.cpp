/*
Orz很明显是一道裸的树形dp
可是好像因为初学的原因	记忆化出了几次问题
调了半天才好
我太弱了
唉一道水题弄了半个小时QWQ
想半个月前的我还要把它转为二叉树来做
QWQ
直接用个vector数组储存一下边
然后定义
f[i][1]:表示选第i个节点
f[i][0]:表示不选第i个节点
然后很明显对应的状态转移也就出来了
如果选的话
f[i][1]=sum{f[son][0]}+a[i]
如果不选
f[i][0]=sum{max(f[son][0],f[son][1])}
然后随便加个记忆化就过了
QWQ书上有很多这种讲解
自己好好领悟吧
睡觉去咯Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=5005;
vector<int> g[MAXN];
int a[MAXN];
int f[MAXN][MAXN];
int ans;
int n;

void init()
{
	int dad;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		cin>>dad;
		g[dad].push_back(i);
	}
}

int dp(int fa,int x)//1表示参加，0表示不参加
{
	if(f[fa][x])
		return f[fa][x];
	
	int d=g[fa].size();
	
	if(x==0)
		for(int i=0;i<d;i++)
		{
			int v=g[fa][i];
			f[fa][x]+=max(dp(v,1),dp(v,0));
		}
	else	if(x==1)
		for(int i=0;i<d;i++)
		{
			int v=g[fa][i];
			f[fa][x]+=dp(v,0);
		}
	if(x==1)
		f[fa][x]+=a[fa];
	return f[fa][x];
}

int main()
{
	init();	
	ans=max(dp(1,0),dp(1,1));
	cout<<ans<<endl;
	return 0;
}
     
