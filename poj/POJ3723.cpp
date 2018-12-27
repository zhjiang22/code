#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=2e4+5;
const int MAXM=1e5+5;
struct Edge{
	int u,v,w;
	bool operator<(const Edge& p)const{
		return w>p.w;
	}
}e[MAXM];
int fa[MAXN];
int n1,n2,m;
int n;
int t;

void init(){
	cin>>n1>>n2>>m;	n=n1+n2;
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		++u;	v=v+n1+1;
		e[i].u=u;	e[i].v=v;	e[i].w=w;
	}
	for(int i=1;i<=n;i++)	fa[i]=i;
}

inline int getfather(const int& x){
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

void work(){
	sort(e+1,e+m+1);
	int cnt=0,sum=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1)	break;
		int& u=e[i].u;	int& v=e[i].v;	int& w=e[i].w;
		int fu=getfather(u);	int fv=getfather(v);
		if(fu==fv)	continue;
		fa[fu]=fv;	sum+=w;	cnt++;
	}
	printf("%d\n",n*10000-sum);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}