#include<bits/stdc++.h>
using namespace std;

const long long MAXN=28;
const long long INF=1e17;
const long long n=26;
long long a[MAXN];
long long t;

void init(){
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

void work(){
	long long ans1=0,ans2=INF;
	for(int i=1;i<=n;i++)
		if(a[i]>=2)
			ans1++,ans2=min(ans2,a[i]/2);
	bool ok1=0;
	for(int i=1;i<=n;i++)
		if(a[i])
			ok1=1;
	if(!ok1){
		printf("0 0\n");
		return;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1)
			cnt++;
	if(cnt==0){
		printf("%lld %lld\n",ans1*2,ans2);
		return;
	}
	ans1=(ans1*2)+1;
	ans2=min(ans2,cnt);
	printf("%lld %lld\n",ans1,ans2);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     