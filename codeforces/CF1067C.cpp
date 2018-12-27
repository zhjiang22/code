#include<bits/stdc++.h>
using namespace std;

int t;
int d;

void init(){
	cin>>d;
}

void work(){
	if(d>0&&d<4){
		printf("N\n");
		return;
	}
	double sub=sqrt(d*d-4*d);
	double plus=d;
	double a=(plus+sub)/2.0;
	double b=(plus-	sub)/2.0;
	printf("Y %.9f %.9f\n",a,b);
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     