#include<bits/stdc++.h>
using namespace std;

int t;
int a,b;

void init(){
	a=b=0;
}

void work(){
	int x;	int ok=1;
	for(int i=1;i<=10;i++){
		cin>>x;
		if(a>x&&b>x)
			ok=0;
		else	if(a<x&&b>x)
			a=x;
		else	if(b<x&&a>x)
			b=x;
		else	if(a>b)
			a=x;
		else
			b=x;
	}
	if(ok)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     