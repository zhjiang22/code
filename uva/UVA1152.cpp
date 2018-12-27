#include<bits/stdc++.h>
using namespace std;

const int MAXN=4005;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int p[MAXN*MAXN];
int n,t;

void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
}

int find(const int& x){
	int l=1,r=n*n;
	int ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(p[mid]>=x)
			r=mid;
		else
			l=mid+1;
	}
	while(p[l]==x&&l<=n*n)	ans++,l++;
	return ans;
}

void work(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			p[(i-1)*n+j]=-(a[i]+b[j]);
	sort(p+1,p+n*n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=find(c[i]+d[j]);
	printf("%d\n",ans);
	if(t)	printf("\n");
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     