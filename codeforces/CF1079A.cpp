#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
int cnt[MAXN];
int a[MAXN];
int n,k;

void init(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
}

void work(){
	int maxd=0;
	for(int i=1;i<=100;i++)
		maxd=max(maxd,cnt[i]);
	int cai=maxd/k;
	if(cai*k!=maxd)	cai++;
	int cur=0;
	for(int i=1;i<=100;i++)
		if(cnt[i])
			cur++;
	cout<<cur*cai*k-n<<endl;
}

int main(){
	init();
	work();
	return 0;
}
     