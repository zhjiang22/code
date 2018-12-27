#include<bits/stdc++.h>
using namespace std;

int t;
int n,x,y;

void init(){
	scanf("%d%d%d",&n,&x,&y);
}

void work(){
	int a=(n+1)/2;	int b=(n-1)/2;
	if(x>=a&&y>=b){
		printf("YES\n");
		return;
	}
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
     