#include<bits/stdc++.h>
using namespace std;

int n,s;

void init(){
	cin>>n>>s;
}

void work(){
	int k=s/n;
	if(k*n==s)	cout<<k<<endl;
	else	cout<<k+1<<endl;
}

int main(){
	init();
	work();
	return 0;
}
     