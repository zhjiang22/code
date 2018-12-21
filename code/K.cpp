#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXA=1000000009;
ll a[100009];
ll rmx[100009],rmn[100009];
ll lmx[100009][2],lmn[100009][2];
ll rx[100009],rn[100009];
ll lx[100009],ln[100009];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		memset(rmx,0,sizeof(rmx));
		memset(rmn,0,sizeof(rmn));
		memset(lmx,0,sizeof(lmx));
		memset(lmn,0,sizeof(lmn));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=n;i;i--){
			rmx[i]=max(a[i],a[i]-rmn[i+1]);
			rmn[i]=min(a[i],a[i]-rmx[i+1]);
	//		printf("%d %d %d\n",i,rmx[i],rmn[i]);
		}	
		lmx[1][1]=a[1];
		lmx[1][0]=-MAXA;
		lmn[1][1]=a[1];
		lmn[1][0]=MAXA;
		for(int i=2;i<=n;i++){
			lmx[i][i&1]=max(a[i],a[i]+lmx[i-1][i&1]);
			lmx[i][(i&1)^1]=-a[i]+lmx[i-1][(i&1)^1];
			lmn[i][i&1]=min(a[i],a[i]+lmn[i-1][i&1]);
			lmn[i][(i&1)^1]=-a[i]+lmn[i-1][(i&1)^1];
	//		printf("%d %d %d %d %d\n",i,lmx[i][0],lmx[i][1],lmn[i][0],lmn[i][1]);
		}
		lx[0]=-MAXA;
		ln[0]=MAXA;
		for(int i=1;i<=n;i++){
			lx[i]=max(lx[i-1],max(lmx[i][0],lmx[i][1]));
			ln[i]=min(ln[i-1],min(lmn[i][0],lmn[i][1]));
		}
		rx[n+1]=-MAXA;
		rn[n+1]=MAXA;
		for(int i=n;i;i--){
			rx[i]=max(rx[i+1],rmx[i]);
			rn[i]=min(rn[i+1],rmn[i]);
		}
		ll ans=0;
		for(int i=1;i<n;i++){
			ans=max(ans,max(lx[i]-rn[i+1],rx[i+1]-ln[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}