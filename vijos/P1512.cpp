/*
因为数据很弱？所以直接一维就可以弄下来惹~
那么这道题其实就很容易转换为一个
区间修改和查询求和的问题
线段树或者BIT都可以很好解决惹
正好练习了一下BIT
只要把C数组改成二维的
查询的时候一维查询然后累加就好了
还是挺简单的模板题哒~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1050;
int c[MAXN][MAXN];
int a[MAXN];
int n,m,ans;

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int v,int x,int d)
{
	while(x<=n)
	{
		c[v][x]+=d;
		x+=lowbit(x);
	}
}

int sum(int v,int x)
{
	int tot=0;
	while(x>0)
	{
		tot+=c[v][x];
		x-=lowbit(x);
	}
	return tot;
}

int main()
{
	cin>>n;
	while(cin>>m)
	{
		if(m==1)
		{
			int x,y,k;
			cin>>x>>y>>k;
			add(x+1,y+1,k);
		}
		else	if(m==2)
		{
			int x1,y1,x2,y2;	ans=0;
			cin>>x1>>y1>>x2>>y2;
			for(int i=x1+1;i<=x2+1;i++)
				ans+=sum(i,y2+1)-sum(i,y1);
			cout<<ans<<endl;
		}
		else
			break;
	}
	return 0;
}
     