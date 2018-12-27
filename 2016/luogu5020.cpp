#include<bits/stdc++.h>
using namespace std;

const int MAXV=25005;
const int MAXN=105;
int f[MAXV];
int a[MAXN];
int maxv;
int n;
int t;

void init(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(f,0,sizeof(f));
}

void work(){
	int ans=n;
	sort(a+1,a+n+1);	maxv=a[n];
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(f[a[i]]){
			ans--;
			continue;
		}
		for(int j=a[i];j<=maxv;j++)
			f[j]|=f[j-a[i]];
	}
	printf("%d\n",ans);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     