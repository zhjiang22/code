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
const int INF=0x7f7f7f7f;
int a[MAXN];
int n,s;
int t;

void init(){
	cin>>n>>s;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
}

void work(){
	int l=1,r=1,sum=a[1];
	int ans=INF;
	while(l<=r&&r<=n){
		while(sum<s&&r<=n)	sum+=a[++r];
		if(sum<s)	break;
		ans=min(ans,r-l+1);
		sum-=a[l++];	
	}
	if(ans==INF)
		printf("0\n");
	else
		printf("%d\n",ans);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     