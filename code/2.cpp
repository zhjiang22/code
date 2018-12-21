#include <bits/stdc++.h>
using namespace std;

int MAXN=500009;

int main() {
	int n,a,b,x,i,l=0,r=0,X;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&X);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&a,&b);
		a=(a+x+2)/2;
		b=(b-1+x)/2;
		r+=x;
		r=min(r,b);
		l=max(l,a);
		if(l>r)break;
	}
	if(i<=n)printf("GG\n");
	else printf("%d\n",l);
	return 0;
}