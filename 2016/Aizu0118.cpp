#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
char g[MAXN][MAXN];
int n,m;

void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool valid(const int& x,const int& y){
	return x<=n&&x>=1&&y<=m&&y>=1;
}

void dfs(int x,int y,char ch){
	g[x][y]=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];	int ny=y+dy[i];
		if(valid(nx,ny)&&g[nx][ny]==ch)
			dfs(nx,ny,ch);
	}
}

void work(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]){
				dfs(i,j,g[i][j]);
				ans++;
			}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		work();
	}
	return 0;
}
     