/*
LIS问题~
其实说白了LIS就是满足条件找一条最长链而已
或者换句话说这个题目就是一个DAG上的动态规划
和lrj的紫书的嵌套矩形本质是一样的
所以我们只需要判断一下两个单词是否可以链接
因为注意到我们是要严格按照顺序来的
所以我们完全没有必要去建图~
因为两个单词本来最多就只会比较一次
建图反而效率会更低
这样我们就可以直接沿用LIS的模式
只是判断大小变成了是否可以链接
进行尝试转移就好了~
QAQ总体还是挺简单的
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string a[2003];
int f[2003];
int ans;
int n;

int check(int x,int y)//检查a[y]是否可以连在a[x]上
{
	int l1=a[x].length();
	int l2=a[y].length();
	if(l1<=l2)
		return 0;
	for(int i=0;i<l2;i++)
		if(a[x][i]!=a[y][i])
			return 0;
	return 1;
}

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

void DP()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)//逆序尝试是否可以接在前面的某个string上
			if(check(i,j))
				f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	DP();
}
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2005;
string a[MAXN];
int f[MAXN];
int g[MAXN][MAXN];
int n;

int check(int x,int y)
{
	int l1=a[x].length();
	int l2=a[y].length();
	if(l1<=l2)
		return 0;
		for(int i=0;i<l2;i++)
		if(a[x][i]!=a[y][i])
			return 0;
	return 1;
}

int main()
{
	int ans=-999;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(check(i,j))
				g[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=i-1;j>=0;j--)
			{
				if(g[i][j])
				f[i]=max(f[i],f[j]+1);
			}
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}  
*/   