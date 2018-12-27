#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=5e4+5;
const int MAXM=1e6;
struct Edge{
	int to,nxt,w;
	Edge(){
		to=nxt=-1;
		w=0;
	}
}e[MAXM];
int tot;
int first[MAXN];
int n=50000;
int m;

inline void Add_Edge(int u,int v,int w){
	e[++tot].nxt=first[u];	first[u]=tot;
	e[tot].w=w;	e[tot].to=v;
}

void init(){
	memset(first,-1,sizeof(first));
	int a,b,c;
	cin>>m;
	for(int i=0;i<=n;i++)
		Add_Edge(i,i+1,0),Add_Edge(i+1,i,-1);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		Add_Edge(a,b+1,c);
	}
}

bool inq[MAXN];
int d[MAXN];
queue<int> q;

void work(){
	memset(d,0x3f,sizeof(d));
	d[0]=0;	inq[0]=0;	q.push(0);
	while(!q.empty()){
		int u=q.front();	q.pop();	inq[u]=0;
		for(int i=first[u];i!=-1;i=e[i].nxt){
			int& v=e[i].to;	int w=-e[i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	printf("%d\n",-d[n+1]);
}

int main(){
	init();
	work();
	return 0;
}