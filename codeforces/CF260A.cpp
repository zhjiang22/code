#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int c[MAXN];
int a,b,n;

void init(){
	cin>>a>>b>>n;
}

void work(){
	c[0]=a;
	for(int i=1;i<=n;i++){
		int found=0;
		for(int j=0;j<10;j++){
			if((a*10+j)%b==0){
				c[i]=j;	a=(a*10+j)%b;
				found=1;
				break;
			}
		}
		if(!found){
			printf("-1\n");
			return;
		}
	}
	for(int i=0;i<=n;i++)	printf("%d",c[i]);
	printf("\n");
}

int main(){
	init();
	work();
	return 0;
}
     