#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000009;
int n,a[MAXN],b[MAXN];

int chk(int x){
	for(int i=1;i<=n;i++)b[i]=(a[i]>=x);
		int mid=(n+1)/2,i=mid-1,j=mid+1;
	while(b[i]^b[i+1]&&i>0)i--;
	while(b[j]^b[j-1]&&j<=n)j--;
	if(mid-i<j-mid)return b[i+1];
	else return b[j-1];
}
int di(){
	int l=1,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(chk(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	n=2*n-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf ("%d\n",di());
	return 0;
}