#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

char rd;    int pn;
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

const int MAXN = 5005;
const int INF = 999999999;
int dir[MAXN];
int f[MAXN];
int n;

void init(){
    std::cin>>n;
    char ch;
    for(int i = 1; i <= n; i++){
    	std::cin>>ch;
    	dir[i] = ch == 'F' ? 1 : 0;
    }
}

int calc(const int& k){
	memset(f, 0, sizeof(f));
	int sum = 0;	int ans = 0;
	for(int i = 1; i+k <= n+1; i++){
		if((dir[i] + sum) % 2 == 0){
			f[i] = 1;
			ans++;
		}
		sum += f[i];
		if(i-k+1 >= 1)
			sum -= f[i-k+1];
	}
	for(int i = n-k+2; i <= n; i++){
		if((dir[i] + sum) % 2 == 0 )
			return INF;
		if(i-k+1 >= 1)	sum -= f[i-k+1];
	}
	return ans;
}

void work(){
	int ans = INF;	int cur=0;
	for(int i = 1; i <= n; i++){
		int k = calc(i);
		if(k < ans){
			ans = k;
			cur = i;
		}
	}
	if(ans == INF)
		printf("-1\n");
	else
		printf("%d %d\n",cur,ans);
}

int main(int argc, char const *argv[]){
    init();
    work();
    return 0;
}
     