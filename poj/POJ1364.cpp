#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=1e5;
struct Edge{
	int to,nxt,w;
}e[MAXN];
int tot;
int first[MAXN];
int n,m;

inline void Add_Edge(int u,int v,int w){
	e[++tot].nxt=first[u];	first[u]=tot;
	e[tot].to=v;	e[tot].w=w;
}

void init(){
	memset(first,-1,sizeof(first));	tot=0;
	string t;	int a,b,c;
	while(m--){
		scanf("%d%d",&a,&b); b=a+b;
		cin>>t; scanf("%d",&c);
		if(t[0]=='g')
			Add_Edge(b,a-1,-c-1);
		else
			Add_Edge(a-1,b,c-1);
	}
	for(int i=0;i<=n;i++)
		Add_Edge(n+1,i,0);
}

bool inq[MAXN];
int cnt[MAXN];
int d[MAXN];
queue<int> q;

void work(){
	memset(inq,0,sizeof(inq));	memset(cnt,0,sizeof(cnt));
	memset(d,0x3f,sizeof(d));	while(!q.empty())	q.pop();
	d[n+1]=0;	inq[n+1]=1; cnt[n+1]=1;	q.push(n+1);
	while(!q.empty()){
		int u=q.front();	q.pop();	inq[u]=0;
		for(int i=first[u];i!=-1;i=e[i].nxt){
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(!inq[v]){
					cnt[v]++;
					if(cnt[v]>=n+2){//一共有n+2个点
						printf("successful conspiracy\n");
						return;
					}
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	printf("lamentable kingdom\n");
}

int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		work();
	}
	return 0;
}
     