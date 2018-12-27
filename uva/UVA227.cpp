#include<bits/stdc++.h>
using namespace std;

const int MAXN=10;
const int n=5;
char g[MAXN][MAXN];
char a[100005];
int curx,cury;
int Case;
int cur;

int get_idx(char x)
{
	if(x=='A')
		return 0;
	if(x=='B')
		return 1;
	if(x=='L')
		return 2;
	if(x=='R')
		return 3;
	return 0;
}

void init()
{
	for(int i=1;i<n;i++)
		gets(g[i]);
	cur=0;
	char ch;
	while(true)
	{
		ch=getchar();
		if(ch=='0')
			break;
		if(ch=='\n')
			continue;
		a[cur++]=ch;
	}
	a[cur]='\0';
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g[i][j]==' ')
			{
				curx=i;	cury=j;
				return;
			}
}

int dx[5]={-1,1,0,0};
int dy[5]={0,0,-1,1};

bool valid(const int& x,const int& y)
{
	return x<n&&x>=0&&y<n&&y>=0;
}

void work()
{
	for(int i=0;i<cur;i++)
	{		
		int k=get_idx(a[i]);
		int newx=curx+dx[k];	int newy=cury+dy[k];
		if(!valid(newx,newy))
		{
			printf("Puzzle #%d:\n",++Case);
			printf("This puzzle has no final configuration.\n");
			return;
		}
		swap(g[newx][newy],g[curx][cury]);
		curx=newx;	cury=newy;
	}
	printf("Puzzle #%d:\n",++Case);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%c%c",g[i][j],j==n-1?'\n':' ');
	}
}

int main()
{
	int first=1;
	while(true)
	{
		gets(g[0]);
		if(g[0][0]=='Z')
			break;
		if(first)
			first=0;
		else
			printf("\n");
		init();
		work();
		getchar();
	}
	return 0;
}
     