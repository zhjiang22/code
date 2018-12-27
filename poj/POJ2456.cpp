#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v){
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1){
	if(v==0)
		putchar(48);
	else{
    	if(v<0){
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0){
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

const int MAXN=1e5+5;
int a[MAXN];
int n,c;

void init(){
	cin>>n>>c;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
}

bool check(const int& x){
	int cur=1;	int last=1;
	int cnt=1;
	while(cur<=n){
		while(a[cur]-a[last]<x&&cur<=n)	cur++;
		if(cur==n+1)	break;
		cnt++;	last=cur;
	}
	return cnt>=c;
}

void work(){
	int l=0,r=1e9+1;
	while(l<r){
		int mid=(l+r)/2+1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",l);
}

int main(){
	init();
	work();
	return 0;
}
     