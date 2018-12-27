#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=22;
int a[MAXN][MAXN];
vector<int> line[MAXN];
vector<int> list[MAXN];
int sline[MAXN],slist[MAXN];
int haveline[MAXN];
int havelist[MAXN];
int hln,hls;
int n,m;

void init()
{
	int x;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(;;)
		{
			scanf("%d",&x);
			if(x==0)
				break;;
			slist[i]+=x;
			list[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(;;)
		{
			scanf("%d",&x);
			if(x==0)
				break;;
			sline[i]+=x;
			line[i].push_back(x);
		}
	}
}

bool check()
{
	for(int i=1;i<=n;i++)
	{
		int j=1;	int l=0;
		for(;;)
		{
			if(l==line[i].size())
				break;
			while(!a[i][j])
				j++;
			int cur=0;
			while(a[i][j]==1&&j<=m)
				j++,cur++;
			if(cur==line[i][l])
				l++;
			else
				return 0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int i=1;	int l=0;
		for(;;)
		{
			if(l==list[j].size())
				break;
			while(!a[i][j]&&i<=n)
				i++;
			int cur=0;
			while(a[i][j])
				i++,cur++;
			if(cur==list[j][l])
				l++;
			else
				return 0;
		}
	}
	return 1;
}

void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(a[i][j]==1)
				cout<<"##";
			else
				cout<<"  ";
		cout<<endl;
	}
	exit(0);
}

void dfs(int x,int y)
{
	if(x>n||y>m)
	{
		if(check())
			print();
		return;
	}
	if(haveline[x]>sline[x])
		return;
	if(havelist[y]>slist[y])
		return;
	if(m-y<sline[x]-haveline[x]-2)
		return;
	if(n-x<slist[y]-havelist[y]-2)
		return;
		a[x][y]=1;
	haveline[x]++;	havelist[y]++;
	if(y==m)
		dfs(x+1,1);
	else
		dfs(x,y+1);
	haveline[x]--;	havelist[y]--;
	a[x][y]=0;
	if(y==m)
		dfs(x+1,1);
	else
		dfs(x,y+1);
}

int main()
{
	init();
	dfs(1,1);
}
     