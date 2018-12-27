#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=15;
const int n=9;
struct L
{
	int idx,tot;
	bool operator<(const L& l)const
	{
		return tot>l.tot;
	}
}Line[MAXN];
int g[MAXN][MAXN];
char ch;
int row[MAXN][MAXN];
int column[MAXN][MAXN];
int fg[MAXN][MAXN];
bool already;

inline int getfg(const int& x,const int& y)
{
	return ((x-1)/3)*3+(y-1)/3+1;
}

void init()
{
	memset(row,0,sizeof(row));
	memset(column,0,sizeof(column));
	memset(fg,0,sizeof(fg));
	for(int i=1;i<=n;i++)
	{
		Line[i].idx=i;
		Line[i].tot=0;
	}
	already=false;
	if(ch=='.')
		g[1][1]=-1;
	else
		g[1][1]=ch-'0';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==1&&j==1)
				continue;
			else
			{
				ch=getchar();
				if(ch=='.')
					g[i][j]=-1;
				else
					g[i][j]=ch-'0';
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(~g[i][j])
			{
				row[i][g[i][j]]=1;;
				column[j][g[i][j]]=1;
				fg[getfg(i,j)][g[i][j]]=1;;
				Line[i].tot++;
			}
	sort(Line+1,Line+n+1);
}

void dfs(int curp,int y)
{
	int& x=Line[curp].idx;
	if(curp==n+1)
	{
		already=1;
		return;
	}
	if(y==n+1)
	{
		dfs(curp+1,1);
		return;		
	}
	if(~g[x][y])
	{
		dfs(curp,y+1);
		return;
	}
	for(int cur=1;cur<=n;cur++)
	{
		if(!row[x][cur]&&!column[y][cur]&&!fg[getfg(x,y)][cur])
		{
			row[x][cur]=column[y][cur]=fg[getfg(x,y)][cur]=1;
			g[x][y]=cur;
			dfs(curp,y+1);
			if(already)
				return;
			row[x][cur]=column[y][cur]=fg[getfg(x,y)][cur]=0;
			g[x][y]=-1;
		}
	}
}

void work()
{
	dfs(1,1);
	if(already)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				printf("%d",g[i][j]);
	}
	printf("\n");
}

int main()
{
	for(;;)
	{
		ch=getchar();
		if(ch=='\n')
			ch=getchar();
		if(ch=='e'||ch=='n'||ch=='d')
			break;
		else
		{
			init();
			work();
		}
	}
	return 0;
}