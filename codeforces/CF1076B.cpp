#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
long long x;
int cnt;
int k;
int prim[MAXN];

bool is_prim(const long long& x)
{
	int k=sqrt(x);
	for(int i=2;i<=k;i++)
		if(!(x%i))
			return false;
	return true;
}

void init(){
	cin>>x;
	k=sqrt(x+1e-5);
	for(int i=2;i<=k;i++)
		if(is_prim(i))
			prim[++cnt]=i;
}

void work(){
	long long ans=0;
	while(x){
		if(is_prim(x)){
			ans++;
			break;
		}
		for(int i=1;i<=cnt;i++)
			if(x%prim[i]==0&&prim[i]!=2){
				ans++;
				x-=prim[i];
				break;
			}
			else	if(x%prim[i]==0&&prim[i]==2){
				ans+=(x/prim[i]);
				x=0;
				break;
			}
	}
	cout<<ans<<endl;
}

int main(){
	init();
	work();
	return 0;
}
     