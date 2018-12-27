#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e3+5;
struct Hero{
	int w,idx;
	bool operator<(const Hero& h)const{
		return w>h.w;
	}
}a[MAXN];
int g[MAXN];
int n,m;
int t;

void init(){
	cin>>n>>m;
	for(int i=1;i<=n*2;i++){
		cin>>a[i].w;
		a[i].idx=i;
	}
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		g[x]=y;	g[y]=x;
	}
	cin>>t;	t--;
}

bool used[MAXN];

void work(){
	sort(a+1,a+2*n+1);
	int x;	
	for(int i=1;i<=2*n;i++){
		t^=1;
		if(t==0){
			cin>>x;	used[x]=1;
			continue;
		}
		if(g[x]&&!used[g[x]]){
			cout<<g[x]<<endl;
			fflush(stdout);
			used[g[x]]=1;
		}
		else for(int j=1;j<=2*n;j++)
				if(!used[a[j].idx]){
					cout<<a[j].idx<<endl;
					fflush(stdout);
					used[a[j].idx]=1;
					break;
				}
	}
}

int main(){
	init();
	work();
	return 0;
}
     