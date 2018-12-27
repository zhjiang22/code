#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int n,r;

void init(){
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void work(){
	sort(a+1,a+n+1);
	int p=1,cur=1;
	int ans=0;
	while(cur<=n){
		while(cur<=n&&a[p]>=a[cur]-r)	cur++;
		if(cur==n+1)	{ans++;	break;}
		cur--;	ans++;	p=cur;
		while(cur<=n&&a[cur]<=a[p]+r)	cur++;
		if(cur==n+1)	break;
		cur--;	p=cur+1;
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&r,&n)&&n!=-1&&r!=-1){
		init();
		work();
	}
	return 0;
}
     