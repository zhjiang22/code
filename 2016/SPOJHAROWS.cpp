#include<bits/stdc++.h>
using namespace std;

const int MAXN=10;
int Last[MAXN];
int Cnt;
int n;
int t;

void init(){
	int q;
	memset(Last,0,sizeof(Last));
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%1d",&q);
			if(q)	Last[i]=max(Last[i],j);
		}
}

void work(){
	int ans=0;
	for(int i=1;i<n;i++)
		if(Last[i]>i){
			for(int j=i+1;j<=n;j++)
				if(Last[j]<=i){
					ans+=(j-i);
					for(int k=j;k>i;k--)
						swap(Last[k],Last[k-1]);
					break;
				}
		}
	printf("Case #%d: %d\n",++Cnt,ans);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     