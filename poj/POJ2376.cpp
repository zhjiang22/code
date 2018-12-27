#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=25005;
struct Cow{
	int l,r;
	bool operator<(const Cow& c)const{
		if(l!=c.l)
			return l<c.l;
		else	return r>c.r;
	}
}a[MAXN];
int n,m;

void init(){
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
}

void work(){
	sort(a+1,a+n+1);
	int r=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int maxr=1;
		if(a[i].l>r+1){
			printf("-1\n");
			return;
		}
		while(i<=n&&a[i].l<=r+1)
			maxr=max(maxr,a[i++].r);
		r=maxr;	ans++;	i--;
		if(r>=m)	break;
	}
	if(r<m){
		printf("-1\n");
		return;
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)==2){
		init();
		work();
	}
	return 0;
}