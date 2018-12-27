#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN=1e5+7;
const int INF=1<<30;
const int mod=1e9+7;

LL bt[80];
LL n;
int t;

void init(){
	cin>>n;
	n++;
}

void work(){
	LL pos=0;	LL cnt=0;
	LL tmp=n;
	while(tmp>1){
		pos=lower_bound(bt,bt+63,tmp)-bt;
		tmp-=bt[--pos];
		++cnt;
	}
	printf("%lld\n",n-bt[cnt]);
}

int main(){
	bt[0]=1;
	for(int i=1;i<=62;i++)	bt[i]=bt[i-1]<<1;
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     