#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN=100005;
LL a[MAXN];
LL Sum;
LL n,m;

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]),Sum+=a[i];
	sort(a+1,a+n+1);
}

void work(){
	if(n==1){
		printf("0\n");
		return;
	}
	LL now=0;
	for(int i=1;i<=n;i++)
		if(a[i]>now)
			now++;
	Sum-=(n+a[n]-now);
	printf("%lld\n",Sum);
}

int main(){
	init();
	work();
	return 0;
}
     