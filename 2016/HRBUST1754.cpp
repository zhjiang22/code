#include<bits/stdc++.h>
using namespace std;

const int MAXN=1005;
long long a[MAXN],b[MAXN];
int n;

void init(){
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)	scanf("%lld",&b[i]);
}

void work(){
	sort(a+1,a+n+1);	sort(b+1,b+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i]*b[n-i+1];
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d",&n)==1){
		init();
		work();
	}
	return 0;
}
     