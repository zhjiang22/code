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

const int MAXN=1005;
const double eps=1e-6;
int a[MAXN],b[MAXN];
int n,m;

void init(){
	read(n);	read(m);
	for(int i=1;i<=n;i++)	read(a[i]);
	for(int i=1;i<=n;i++)	read(b[i]);
}

bool check(double x){
	double s=x+m;
	s-=(s/a[1]);	if(s<=m)	return 0;
	for(int i=2;i<=n;i++){
		s-=(s/a[i]);	if(s<=m)	return 0;
		s-=(s/b[i]);	if(s<=m)	return 0;
	}
	s-=(s/b[1]);	if(s<=m)	return 0;
	return 1;
}

void work(){
	double l=0,r=1e9+10;
	if(!check(1e9)){
		printf("-1\n");
		return;
	}
	while(r-l>eps){
		double mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	if(l>1e9)
		printf("-1\n");
	else
		printf("%.8f\n",l);
}

int main(){
	init();
	work();
	return 0;
}
     