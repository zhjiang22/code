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

const int MAXN=105;
int a[MAXN];
int n,m;

void init(){
	int x;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x;
		a[x]++;
	}
}

bool check(const int& x){
	int cnt=0;
	for(int i=1;i<=100;i++)
		cnt+=a[i]/x;
	return cnt>=n;
}

void work(){
	int l=0,r=105;
	while(l<r){
		int mid=(l+r+1)/2;
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
     