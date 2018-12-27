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

const int MAXN=10005;
const double eps=1e-5;
double a[MAXN];
int n,k;

void init(){
	for(int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
}

bool check(const double& p){
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(int)(a[i]/p);
	return cnt>=k;
}

void work(){
	double l=0,r=100100;
	while(r-l>eps){
		double mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%.2f\n",floor(r*100)/100);
}

int main(){
	while(scanf("%d%d",&n,&k)==2&&n&&k){
		init();
		work();
	}
	return 0;
}
