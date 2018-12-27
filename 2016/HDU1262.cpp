#include<bits/stdc++.h>
using namespace std;

const int MAXM=10005;
int Prim[MAXM];
int n;

void init(){
	for(int i=2;i<MAXM;i++)	Prim[i]=1;
	for(int i=2;i<MAXM;i++)
		if(Prim[i])
			for(int j=i*2;j<MAXM;j+=i)
				Prim[j]=0;
}

void work(){
	for(int i=(n/2);i>=2;i--)
		if(Prim[i]&&Prim[n-i]&&i!=n-1){
			printf("%d %d\n",i,n-i);
			break;
		}
}

int main(){
	init();
	while(scanf("%d",&n)==1&&n)
		work();
	return 0;
}
     