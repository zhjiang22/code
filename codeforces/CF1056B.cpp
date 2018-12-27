#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXM=1005;
int a[MAXM][MAXM];
int n,m;

void init(){
	cin>>n>>m;
}

void work(){
	if(n<m){
		LL ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if((i*i+j*j)%m==0)
					ans++;
		printf("%lld\n",ans);
		return;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if((i*i+j*j)%m==0)
				a[i][j]=1;
	LL ans=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j])
				ans+=((long long)(n-i)/m+1)*((n-j)/m+1);
	printf("%lld\n",ans);
}

int main(){
	init();
	work();
	return 0;
}
     