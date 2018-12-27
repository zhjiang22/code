#include<bits/stdc++.h>
using namespace std;

const int MAXN=5005;
struct EDGE
{
	int u,v;
}e[MAXN];
vector<int>Edge[MAXN];
bool vis[MAXN];
int tot;
int n,m;

inline void Add_Edge(const int& u,const int& v){
	Edge[u].push_back(v);
}
int k;

vector<int> path;

void init(){
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		Add_Edge(u,v);	Add_Edge(v,u);
		e[++tot].u=u;	e[tot].v=v;
	}
}

void dfs(int u){
	path.push_back(u);
	vis[u]=1;	int l=Edge[u].size();
	for(int i=0;i<l;i++){
		int& v=Edge[u][i];
		if(k!=0&&u==e[k].u&&v==e[k].v)	continue;
		if(k!=0&&u==e[k].v&&v==e[k].u)	continue;
		if(!vis[v])	dfs(v);
	}
}

void work(){
	for(int i=1;i<=n;i++)
		sort(Edge[i].begin(),Edge[i].end());
	memset(vis,0,sizeof(vis));
	dfs(1);
	for(int i=0;i<n;i++)
		printf("%d ",path[i]);
	printf("\n");
}


void work2(){
	for(int i=1;i<=n;i++)
		sort(Edge[i].begin(),Edge[i].end());
	vector<int> ans;
	for(k=1;k<=tot;k++){
		path.clear();
		memset(vis,0,sizeof(vis));
		dfs(1);
		if(path.size()<n)	continue;
		if(!ans.size())	ans=path;
		else	ans=min(ans,path);
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
}

int main(){
	cin>>n>>m;
	init();
	if(n==m+1)
		work();
	else
		work2();
	return 0;
}
     