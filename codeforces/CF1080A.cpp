#include<bits/stdc++.h>
using namespace std;

int n,k;
int a,b,c;

void init(){
	cin>>n>>k;
	a=2*n;	b=5*n;	c=8*n;
}

void work(){
	if(a%k==0)	a/=k;	else	a=a/k+1;
	if(b%k==0)	b/=k;	else	b=b/k+1;
	if(c%k==0)	c/=k;	else	c=c/k+1;
	printf("%d\n",a+b+c);
}

int main(){
	init();
	work();
	return 0;
}
     