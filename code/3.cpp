#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const long long MAXN=1e6+5;
long long s[MAXN];
long long a[MAXN];
int n,m;

inline int lowbit(int x){return x&(-x);}

long long sum(int x) {
	long long ans=0;
	for(int i=x;i>=1;i-=lowbit(i)) ans+=s[i];
	// while(cur){
	// 	ans+=s[cur];
	// 	cur-=lowbit(cur);
	// }
	return ans;
}

void add(int x,int d){
	for(int i=x;i<=n;i+=lowbit(i)) 
		{
			s[i]+=d;
		}
	// while(cur<=n)
	// {
	// 	s[cur]+=d;
	// 	cur+=lowbit(cur);
	// }
}

void work() {
	int k,l,r;
	for(int i=1;i<=n;i++)
		add(i,a[i]);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&k,&l,&r);
		if(k==1)
			printf("%lld\n",sum(r)-sum(l-1));
		else {
			add(l,r-a[l]);
			a[l]=r;
		}
	}
}

void init() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	memset(s,0,sizeof(s));
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	work();
	return 0;
}