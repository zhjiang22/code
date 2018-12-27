#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
string a,b;
int n,m;

void init(){
	n=a.length();	m=b.length();
}

bool check(int p,int q){
	while(p<n&&q<m){
		if(a[p]+b[q]>'0'+'0'+3)	return 0;
		p++;	q++;
	}
	return 1;
}

int ans;

void work(){
	int p=0,q=0;
	while(p<n){
		if(check(p,q))
			break;
		else	p++;
	}
	ans=max(p-q+m,n);
	p=0,q=0;
	while(q<m){
		if(check(p,q))
			break;
		else	q++;
	}
	ans=min(ans,max(q-p+n,m));
	printf("%d\n",ans);
}

int main(){
	while(cin>>a>>b){
		init();
		work();
	}
	return 0;
}
     