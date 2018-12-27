#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

char rd;	int pn;
template <typename Type>
inline void read(Type& v){
	pn = 1;
	while((rd = getchar()) <'0' || rd > '9')
		if(rd == '-')
			pn = -1;
	v = rd-'0';
	while((rd = getchar()) >= '0'&&rd <= '9')
		v = v*10+rd-'0';
	v *= pn;
}
template <typename Type>
inline void out(Type v,bool c = 1){
	if(v == 0)
		putchar(48);
	else{
    	if(v < 0){
    		putchar('-');
    		v = -v;
    	}
    	int len = 0,dg[20];  
    	while(v > 0){
    		dg[++len] = v%10;
    		v /= 10;
    	}  
    	for(int i = len; i >= 1; i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

const int MAXN = 1e6+5;
std::set<int> s;
std::map<int,int> count;
int a[MAXN];
int n,m;

void init(){
	read(n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	m = s.size();
}

void work(){
	int l = 1,r = 1;
	int ans = n;	int num = 0;
	while(true){
		while(num < m&&r <= n){
			if(!count[ a[r] ])
				num++;
			count[ a[r++] ]++;
		}
		if(num < m)	break;
		ans = std::min(ans , r - l);
		if(count[ a[l] ]==1)
			num--;
		count[ a[l++] ]--;
	}
	printf("%d\n", ans);
}

int main(){
	init();
	work();
	return 0;
}
     