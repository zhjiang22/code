#include<bits/stdc++.h>
using namespace std;

int t;
int a,b;

bool check(const int &x){
	int p=abs(x);
	if(p==0)	return 0;
	if(p<=10)	return 1;
	return (p%10==0);
}

void init(){
	cin>>a>>b;
}

char get(int x){
	if(x>0)	return '+';
	else	return '-';
}

void work(){
	if(check(a)||check(b)){
		if(check(a))    swap(a,b);
		int c=(a/10)*10;	if(c==0)	c+=10;
		int d=a-c;
		printf("%d x %d %c %d x %d\n",c,b,get(d),abs(d),b);
	}
	else{
		int c=(a/10)*10;	if(c==0)	c+=10;
		int d=a-c;
		int p=(b/10)*10;	if(p==0)	p+=10;
		int q=b-p;
		printf("%d x %d %c %d x %d %c %d x %d %c %d x %d\n",c,p,get(c),abs(c),q,get(d),abs(d),p,get(d),abs(d),q);
	}
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     