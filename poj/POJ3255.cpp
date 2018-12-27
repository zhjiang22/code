#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=5005;
const int MAXM=2e5+5;
struct Edge{
	int to,nxt,w;
}e[MAXM];
int first[MAXN];
int tot;
int n,m;

inline void Add_Edge(const int& u,const int& v,const int& w){
	e[++tot].nxt=first[u];	first[u]=tot;
	e[tot].to=v;	e[tot].w=w;
}

void init(){
	int u,v,w;
	cin>>n>>m;
	memset(first,-1,sizeof(first));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		Add_Edge(u,v,w);	Add_Edge(v,u,w);
	}
}

int d[MAXN],d2[MAXN];
typedef pair<int,int> HeapNode;
priority_queue<HeapNode,vector<HeapNode>,greater<HeapNode> > q;

void work(){
	memset(d,0x3f,sizeof(d));	memset(d2,0x3f,sizeof(d2));
	d[1]=0;	q.push(HeapNode(0,1));
	while(!q.empty()){
		int u=q.top().second,dis=q.top().first;	q.pop();
		if(dis>d2[u])	continue;
		for(int i=first[u];i!=-1;i=e[i].nxt){
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>dis+w){
				d2[v]=d[v];
				d[v]=dis+w;
				q.push(HeapNode(d[v],v));
			}
			else	if(d2[v]>dis+w&&d[v]<dis+w){
				d2[v]=dis+w;
				q.push(HeapNode(d2[v],v));
			}
		}
	}
	printf("%d\n",d2[n]);
}

int main(){
	init();
	work();
	return 0;
}