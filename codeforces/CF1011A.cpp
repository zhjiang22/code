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

const int MAXN=30;
const int INF=0x7f7f7f7f;
int a[MAXN];
int n,k;
int ans=INF;

void init(){
	char ch;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>ch;
		a[ch-'a']++;
	}
}

void work(){
	int cur=0,cnt=0;
	int last=-5;
	int ans=0;
	while(cur<26){
		while(!a[cur]&&cur<26)	cur++;
		if(a[cur]&&cur-last>=2){
			ans+=cur+1;	cnt++;	last=cur;
			if(cnt==k){
				printf("%d\n",ans);
				return;
			}
		}
		cur++;
	}
	printf("-1\n");
}

int main(){
	init();
	work();
	return 0;
}
     