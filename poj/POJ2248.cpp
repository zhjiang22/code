#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int n;

void init()
{
	memset(a,0,sizeof(a));
	a[0]=1;
}


int dfs(int cur,int maxdep)
{
	if(cur>maxdep)
		return 0;
	if(a[cur-1]>n)
		return 0;
	if(a[cur-1]==n)
		return 1;
	bool used[MAXN];//不可用全局变量 不然递归会影响上一层的used
	memset(used,0,sizeof(used));
	for(int i=cur-1;i>=0;i--)
		if(!used[a[i]+a[cur-1]])
		{
			used[a[i]+a[cur-1]]=1;
			a[cur]=a[i]+a[cur-1];
			if(a[cur]==n)
			{
				for(int i=0;i<cur;i++)
					printf("%d ",a[i]);
				printf("%d\n",a[cur]);
				return 1;
			}
			if(dfs(cur+1,maxdep))
				return 1;
		}
	return 0;
}

void work()
{
	if(n==1)//特判n==1时
	{
		cout<<1<<endl;
		return;
	}
	for(int i=1;i<=MAXN;i++)
		if(dfs(1,i))
			break;
}

int main()
{
	while(scanf("%d",&n)&&n)
	{
		init();
		work();
	}
	return 0;
}