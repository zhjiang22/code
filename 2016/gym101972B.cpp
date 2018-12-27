#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+7;
vector<int> e[MAXN];
int w[MAXN];
int n;
int t;

void init(){
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%d",&w[i]);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);	e[v].push_back(u);
	}
}

void work(){
	for(int i=1;i<=n;i++)
		if(e[i].size()>2)
		{
			printf("-1\n");
			return;
		}
	for(int i=1;i<=n;i++)
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     