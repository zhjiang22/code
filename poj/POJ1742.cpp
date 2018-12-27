#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXM=1e5+10;
const int MAXN=105;
int f[MAXM];//f[j]表示凑到j元，当前第i个硬币最多剩下的个数
int a[MAXN],c[MAXN];
int n,m;
int ans;

void init(){
	memset(f,-1,sizeof(f));
	f[0]=0;	ans=0;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>c[i];
}

void work(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++)
			if(f[j]!=-1)
				f[j]=c[i];
			else	if(j<a[i]||f[j-a[i]]==-1)
				f[j]=-1;
			else	f[j]=f[j-a[i]]-1;
	}
	for(int i=1;i<=m;i++)
		if(f[i]!=-1)
			ans++;
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		work();
	}
	return 0;
}
     