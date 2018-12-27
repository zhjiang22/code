#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=25;
int g[MAXN][MAXN];
int sx,sy;
int n,m;
int ans;

void init(){
	char ch;
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>ch;
			if(ch=='#')	g[i][j]=1;
			if(ch=='@')	sx=i,sy=j;
		}
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool valid(const int& x,const int& y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}

void dfs(int x,int y){
	ans++;	g[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(!valid(nx,ny)||g[nx][ny]==1)	continue;
		dfs(nx,ny);
	}
}

void work(){
	ans=0;
	dfs(sx,sy);
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&m,&n)==2&&n&&m){
		init();
		work();
	}
	return 0;
}
     