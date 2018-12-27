#include<bits/stdc++.h>
using namespace std;

const int MAXN=1005;
struct Point{
	int x,y;
	int p,t;
};
bool vis[MAXN][MAXN][10];
char g[MAXN][MAXN];
int chese[MAXN][MAXN];
int n,m,k;
int sx,sy;

void init(){
	int cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			if(g[i][j]=='S')
				sx=i,sy=j;
			else	if(g[i][j]<='9'&&g[i][j]>='0')
				chese[i][j]=++cnt;
		}
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool valid(const int& x,const int& y){
	return x<=n&&x>=1&&y<=m&&y>=1;
}

void work(){
	queue<Point> q;	while(!q.empty()) q.pop();
	q.push((Point){sx,sy,0,0});	vis[sx][sy][0]=1;
	while(!q.empty()){
		int x=q.front().x;	int y=q.front().y;
		int p=q.front().p;	int t=q.front().t;
		// cout<<x<<" "<<y<<" "<<p<<" "<<t<<endl;
		q.pop();
		if(p==k){
			printf("%d\n",t);
			return;
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i];	int ny=y+dy[i];
			if(!valid(nx,ny)||g[nx][ny]=='X')	continue;
			if(g[nx][ny]=='.'){
				if(!vis[nx][ny][p]){
					q.push((Point){nx,ny,p,t+1});
					vis[nx][ny][p]=1;
				}
			}
			else{
				int k=g[nx][ny]-'0';
				if(k==p+1){
					q.push((Point){nx,ny,p+1,t+1});
					vis[nx][ny][p+1]=1;
				}
				else	if(!vis[nx][ny][p]){
						q.push((Point){nx,ny,p,t+1});
						vis[nx][ny][p]=1;
					}
			}
		}
	}
}

int main(){
	init();
	work();
	return 0;
}
     