#include<bits/stdc++.h>
using namespace std;

const int MAXM=10005;
int prim[MAXM];
int n;

void init(){
	for(int i=2;i<MAXM;i++)	prim[i]=1;
	for(int i=2;i<MAXM;i++)
		if(prim[i])
			for(int j=i*2;j<MAXM;j+=i)
				prim[j]=0;
}

void work(){
	int ans=0;
	for(int i=2;i<(n/2);i++)
		if(prim[i]&&prim[n-i])
			ans++;
	printf("%d\n",ans);
}

int main(){
	init();
	while(scanf("%d",&n)&&n){
		work();
	}
	return 0;
}
     