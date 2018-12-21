#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int MAXN=1e5+5;
struct Edge {
	int to,nxt;
}e[MAXN];
int g[2005][2005];
int first[MAXN];
int tot;
int n,m;
int minw=INF;

void Add_Edge(const int& u,const int& v,const int& w) {
	minw=min(minw,w);
	if(g[u][v]!=INF) {
		g[u][v]=min(g[u][v],w);
		return;
	}
	e[++tot].nxt=first[u];	first[u]=tot;	e[tot].to=v;
	g[u][v]=w;
}

bool vis[MAXN];

void init() {
	memset(first,-1,sizeof(first));
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	tot=0;
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)	if(i!=j)	g[i][j]=INF;
	int u,v,w;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		Add_Edge(u,v,w);
	}
}

bool inq[MAXN];
int cnt[MAXN];
int d[MAXN];
deque<int> q;

int spfa(int s) {
	memset(inq,0,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	while(!q.empty())	q.pop_front();
	for(int i=1;i<=n;i++)	d[i]=INF;
	q.push_back(s);	inq[s]=1;
	d[s]=0;
	while(!q.empty()) {
		int u=q.front();	q.pop_front();
		inq[u]=0;
		for(int i=first[u];i!=-1;i=e[i].nxt) {
			int& v=e[i].to;	int& w=g[u][v];
			if(d[v]>d[u]+w) {
				d[v]=d[u]+w;
				if(!inq[v]) {
					cnt[v]++;
					if(cnt[v]>n){
						return -INF;
					}
					inq[v]=1;
					if(q.empty()) 
						q.push_back(v);
					else if(d[v]<=d[q.front()])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(d[i]!=INF)
			vis[i]=1;
	return 0;
}

int addw;
struct Node {
	int idx,d;
	bool operator<(const Node& p) const {
		return d>p.d;
	}
};

int minans;
int P,Q;
bool ini[MAXN];
int CNT[MAXN];
priority_queue<Node> dq;

void dijk(int s) {
	memset(ini,0,sizeof(ini));
	memset(CNT,0,sizeof(CNT));
	while(!dq.empty())	dq.pop();
	for(int i=1;i<=n;i++)	d[i]=INF;
	d[s]=0;	CNT[s]=0;
	dq.push((Node){s,0});
	while(!dq.empty()) {
		Node uu=dq.top();	dq.pop();
		int u=uu.idx;
		if(ini[u])	continue;
		ini[u]=1;
		for(int i=first[u];i!=-1;i=e[i].nxt) {
			int& v=e[i].to;	int w=g[u][v]+addw;
			if(!ini[v]&&d[v]>d[u]+w) {
				d[v]=d[u]+w;
				CNT[v]=CNT[u]+1;
				dq.push((Node){v,d[v]});
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(i!=s&&d[i]-CNT[i]*addw<minans) {
			minans=d[i]-CNT[i]*addw;
		}
}

void work() {
	for(int i=1;i<=n;i++)
		if(spfa(i)==-INF) {
			cout<<"-inf"<<endl;
			return;
		}
	minans=INF;
	P=0;	Q=0;
	addw=minw>=0?0:-minw;
	for(int i=1;i<=n;i++)
		dijk(i);
	cout<<minans<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		init();
		work();
	}
	return 0;
}