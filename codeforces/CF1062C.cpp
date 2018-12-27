#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int MAXN=1e6+5;
vector<vector<int> > List(MAXN);
int f[MAXN];
int a[MAXN];
int n;

void init(){
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=2;i<=1e6;i++)
		for(int j=i;j<=1e6;j+=i)
			List[j].push_back(i);
}

void work(){
	for(int i=1;i<=n;i++){
		int& x=a[i];	int l=List[x].size();
		for(int j=l-1;j>=0;j--){
			int& d=List[x][j];
			f[d]=(f[d]+f[d-1])%MOD;
		}
		f[1]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)	ans=(ans+f[i])%MOD;
	printf("%d\n",ans);
}

int main(){
	init();
	work();
	return 0;
}
     