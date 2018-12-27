#include<bits/stdc++.h>
using namespace std;

const int MAXN=505;
const int INF=1e9+10;
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],d[MAXN][MAXN];
int g[MAXN][MAXN];
int n,m;
int t;

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	memset(a,0,sizeof(a));	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=m;j++)	
			a[i][j]=max(g[i][j],max(a[i-1][j],a[i][j-1]));
	for(int i=1;i<=n;i++)	
		for(int j=m;j>-1;j--)	
			b[i][j]=max(g[i][j],max(b[i-1][j],b[i][j+1]));
	for(int i=n;i>=1;i--)	
		for(int j=1;j<=m;j++)	
			c[i][j]=max(g[i][j],max(c[i+1][j],c[i][j-1]));
	for(int i=n;i>=1;i--)	
		for(int j=m;j>=1;j--)	
			d[i][j]=max(g[i][j],max(d[i+1][j],d[i][j+1]));
}

void work(){
	int ans=INF;
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++){
			int maxv=max(a[i-1][j-1],max(b[i-1][j+1],max(c[i+1][j-1],d[i+1][j+1])));
			int minv=min(a[i-1][j-1],min(b[i-1][j+1],min(c[i+1][j-1],d[i+1][j+1])));
			ans=min(ans,maxv-minv);
		}
		printf("%d\n",ans);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     