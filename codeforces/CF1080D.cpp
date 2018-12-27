#include<bits/stdc++.h>
using namespace std;

long long t;
long long n,k;

void init(){
	cin>>n>>k;
}

void work(){
	if(n<k)
		printf("NO\n");
	else{
		printf("YES %lld\n",(long long)log2(n));
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
     