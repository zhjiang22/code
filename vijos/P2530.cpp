/*
题目不完全可以去洛谷上看~
*/
/*
解法1:BFS搜索~
呵呵哒一开始看到第一直觉就是直接无脑搜索呀~
很简单的搜索因为n也很小也就100
就可以直接乱搞~！
我们判重就是可以直接用一个bool数组
vis[p][i][j][k]
表示到了第p个位置当前三种纯度的成品分别由i,j,k个
那么唯一要注意一下的就是扩展的方式了
直接枚举每次丢掉的三种方式就好~
还有就是我一开始错的地方(90分wa了一个点)
如果总数一开始就没有10个
这个时候创立初始结点的时候一定要小心
而且注意一些细节问题
详细见代码啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=105;
const int MAXV=12;
struct Node
{
	int p,step;
	int c[3];
	Node(int p1,int step1,int x,int y,int z)
	{
		p=p1;	step=step1;
		c[0]=x;	c[1]=y;	c[2]=z;	
	}
};
bool vis[MAXN][MAXV][MAXV][MAXV];
int a[MAXN];
int n;
queue<Node> q;

void init()
{
	char ch;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		a[i]=ch-'A';
	}
	Node t(min(n,10),0,0,0,0);
	for(int i=1;i<=10&&i<=n;i++)
		t.c[a[i]]++;
	q.push(t);
	vis[10][t.c[0]][t.c[1]][t.c[2]]=1;
}

void doit(Node& t)
{
	if(vis[t.p][t.c[0]][t.c[1]][t.c[2]])
		return;
	vis[t.p][t.c[0]][t.c[1]][t.c[2]]=1;
	q.push(t);
}

int BFS()
{
	while(!q.empty())
	{
		Node u=q.front();	q.pop();
		int& p=u.p;		int& step=u.step;	
		int& x=u.c[0];	int& y=u.c[1];	int& z=u.c[2];
		if(p==n&&x==0&&y==0&&z==0)
			return step;
		if(p>n)
			continue;
		for(int i=0;i<=2;i++)
		{
			Node t(p,step+1,x,y,z);
			t.c[i]=0;
			for(int j=p+1;j<=p+u.c[i]&&j<=n;j++)
				t.c[a[j]]++,t.p++;
			doit(t);
		}
	}
}

int main()
{
	init();
	cout<<BFS()<<endl;
}
     