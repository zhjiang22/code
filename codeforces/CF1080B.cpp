#include<bits/stdc++.h>
using namespace std;

#define LL long long
int q;
int l,r;

void work(){
	cin>>q;
	while(q--){
		scanf("%d%d",&l,&r);
		LL k=r-l+1;
		if(k%2){
			if(l%2){
				LL t=(k-1)/2;
				printf("-%lld\n",r-t);
			}
			else{
				LL t=(k-1)/2;
				printf("%lld\n",r-t);
			}
		}
		else{
			if(l%2)
				printf("%lld\n",k/2);
			else
				printf("%lld\n",k/2);
		}
	}
}

int main(){
	work();
	return 0;
}
     