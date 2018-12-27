#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int MAXN=105;
int g[MAXN][MAXN];
int n,m;

void init(){
	char ch;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>ch;
			if(ch=='.')	g[i][j]=1;
			else	g[i][j]=0;
		}
}

inline bool valid(const int& x,const int& y){
	return x<=n&&x>=1&&y<=m&&y>=1;
}

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,-1,1,-1,1};

void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int nx=x+dx[i];	int ny=y+dy[i];
		if(!valid(nx,ny))	continue;
		if(!g[nx][ny]){
			g[nx][ny]=1;
			dfs(nx,ny);
		}
	}
}

void work(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!g[i][j]){
				dfs(i,j);
				ans++;
			}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		work();
	}
	return 0;
}
     