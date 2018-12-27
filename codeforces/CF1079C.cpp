#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
char dp[MAXN][10];
int arr[MAXN];
int n;

void init(){
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>arr[i];
	memset(dp,-1,sizeof dp);
	memset(dp[0],0, sizeof dp[0]);
}

void work(){
	for(int i=1;i<n;i++)
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)
				if(dp[i-1][j]>=0&&((arr[i-1]<arr[i]&&j<k)||(arr[i-1]>arr[i]&&j>k)||(arr[i-1]==arr[i]&&j!=k))) 
					dp[i][k]=j;
	for(int i=0;i<5;++i)
		if(dp[n-1][i]>=0){
			int last=i;
			vector<int> vp;
			for(int j=n-1;j>=0;--j){
				vp.push_back(last);
				last=dp[j][last];
			}
			reverse(vp.begin(),vp.end());
			for(int x: vp) cout<<x+1<<" ";
			return;
		}
	cout<<-1<<endl;
}

int main(){
	init();
	work();
	return 0;
}