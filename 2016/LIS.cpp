#include<bits/stdc++.h>
using namespace std;

const int MAXN=1005;
int f[MAXN];
int n;

void init(){
	memset(f,0x3f,sizeof(f));
	cin>>n;
}

void work(){
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		*lower_bound(f+1,f+n+1,x)=x;
	}
	for(int i=1;i<=n;i++)
		if(f[i]>10000){
			printf("%d\n",i-1);
			return;
		}
	printf("%d\n",n);
}

int main(){
	init();
	work();
	return 0;
}
     