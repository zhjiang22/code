#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
int f[MAXN][MAXN];
int q[MAXN];
int p,n;
int Cnt;
int t;

void init(){
	cin>>p>>n;
	for(int i=1;i<=n;i++)	cin>>q[i];
}

void work(){
	memset(f,0x3f,sizeof(f));
	q[0]=0;	q[n+1]=p+1;
	for(int i=0;i<=n;i++)	f[i][i+1]=0;
	for(int l=2;l<=n+1;l++)
		for(int i=0;i+l<=n+1;i++){
			int j=i+l;
			for(int k=i+1;k<j;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			f[i][j]+=(q[j]-q[i]-2);
		}
	printf("Case #%d: %d\n",++Cnt,f[0][n+1]);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     