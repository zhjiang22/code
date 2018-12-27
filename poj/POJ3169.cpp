#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int INF=1061109567;
const int MAXM=1e6;
const int MAXN=1e3+5;
struct Edge{
	int to,nxt,w;
}e[MAXM];
int tot;
int first[MAXN];
int n,ml,md;

inline void Add_Edge(const int u,const int v,const int w){
	e[++tot].nxt=first[u];	first[u]=tot;
	e[tot].w=w;	e[tot].to=v;
}

void init(){
	memset(first,-1,sizeof(first));	tot=0;
	int x,y,d;
	for(int i=1;i<n;i++)
		Add_Edge(i+1,i,0);
	for(int i=1;i<=ml;i++){
		scanf("%d%d%d",&x,&y,&d);
		Add_Edge(x,y,d);
	}
	for(int i=1;i<=md;i++){
		scanf("%d%d%d",&x,&y,&d);
		Add_Edge(y,x,-d);
	}
}

bool inq[MAXN];
int cnt[MAXN];
int d[MAXN];
queue<int> q;

void work(){
	memset(d,0x3f,sizeof(d));
	memset(inq,0,sizeof(inq));	memset(cnt,0,sizeof(cnt));
	while(!q.empty())	q.pop();
	d[1]=0;    inq[1]=1;	q.push(1);	cnt[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();	inq[u]=0;
		for(int i=first[u];i!=-1;i=e[i].nxt){
			int& v=e[i].to;	int & w=e[i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(!inq[v]){
					cnt[v]++;
					if(cnt[v]>=n){
						printf("-1\n");
						return;
					}
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	if(d[n]==INF)	printf("-2\n");
	else	printf("%d\n",d[n]);
}

int main(){
	while(cin>>n>>ml>>md){
		init();
		work();
	}
	return 0;
}
     