#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

const int MAXN=105;
int g[MAXN][MAXN];
int n,m;

void init()
{
	int x,y,w;
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		read(x);	read(y);	read(w);
		g[x][y]=g[y][x]=min(g[x][y],w);
	}
}

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

void work()
{
	Floyd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		work();
	}
	return 0;
}
     