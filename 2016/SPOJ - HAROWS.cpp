#include<bits/stdc++.h>
using namespace std;

const int MAXN=10;
int a[MAXN];
int Case;
int n;
int t;

void init(){
	int x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x)	a[i]=max(a[i],j);
		}
}

void work(){
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]>i){
			for(int j=i+1;j<=n;j++)
				if(a[j]<=i){
					break;
				}
				else{

				}
		}
	printf("Case #%d: %d\n",++Case,ans);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     