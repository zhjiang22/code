#include <bits/stdc++.h>
using namespace std;
int s[100009];
struct edge{
	int ed,wt;
}st[100009];
bool operator <(edge x,edge y){
	return x.wt<y.wt;
}
vector<edge> e[100009];
int fa[100009],t;
void pu(edge x){
	while(st[t].wt>=x.wt)
		t--;
	st[++t]=x;
}
int dfs(int x){
	for(int i=0;i<e[x].size();i++){
		int nxt=e[x][i].ed;
		if(nxt!=fa[x]){
			fa[nxt]=x;
			pu(e[x][i]);
			dfs(nxt);
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	int T,n,q,u,v,w;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)e[i].clear();
		memset(fa,0,sizeof(fa));
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(edge{v,w});
			e[v].push_back(edge{u,w});
		}
		for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
		t=0;
		st[0]=edge{0,-1};
		pu(edge{1,0});
		dfs(1);
		for(int i=1;i<=q;i++)scanf("%d",&s[i]);
		sort(s+1,s+q+1);
		long long ans=0;	
		for(int i=q;i;i--){
			while(st[t].wt>=s[i])t--;
			ans+=st[t].ed;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
