#include<bits/stdc++.h>
using namespace std;

const int MAXV=1e5;
int f[MAXV];
int n,maxv;

void init(){
	cin>>n>>maxv;
}

void work(){
	int w,v;
	for(int i=1;i<=n;i++){
		cin>>v>>w;
		for(int j=maxv;j>=v;j--)
			f[j]=max(f[j],f[j-v]+w);
	}
	printf("%d\n",f[maxv]);
}

int main(){
	init();
	work();
	return 0;
}
     