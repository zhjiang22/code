#include<bits/stdc++.h>
using namespace std;

long long t;
long long n,m;
long long X1,Y1,X2,Y2;
long long X3,Y3,X4,Y4;

void init(){
	cin>>n>>m;
	cin>>Y1>>X1>>Y2>>X2;
	cin>>Y3>>X3>>Y4>>X4;
}

void Count(long long X1,long long Y1,long long X2,long long Y2,long long& black,long long& white){
	if(X1>X2||Y1>Y2){
		black=white=0;
		return;
	}
	long long dx=X2-X1+1;	long long dy=Y2-Y1+1;
	if(dx%2&&dy%2){
		if((X1+Y1)%2){
			black=dx*dy/2+1;
			white=dx*dy-black;
		}
		else{
			black=dx*dy/2;
			white=dx*dy-black;
		}
	}
	else
		white=black=dx*dy/2;
}

void work(){
	long long x5,y5,x6,y6;
	x5=max(X1,X3);	x6=min(X2,X4);
	y5=max(Y1,Y3);	y6=min(Y2,Y4);
	long long sblack,swhite;
	Count(1,1,n,m,sblack,swhite);
	// cout<<sblack<<" "<<swhite<<endl;
	long long black,white;
	long long black1,white1;
	long long black2,white2;
	Count(x5,y5,x6,y6,black,white);
	Count(X1,Y1,X2,Y2,black1,white1);
	Count(X3,Y3,X4,Y4,black2,white2);
	// cout<<black<<" "<<white<<endl;
	// cout<<black1<<" "<<white1<<endl;
	// cout<<black2<<" "<<white2<<endl;
	black1-=black;	
	swhite+=black1;	sblack-=black1;
	swhite-=white2;	sblack+=white2;
	/*sblack-=black1;	sblack+=black2;
	swhite-=white2;	swhite+=black1;*/
	// cout<<endl;
	printf("%lld %lld\n",swhite,sblack);
	// cout<<endl;
}

int main(){
	cin>>t;
	while(t--){
		init();
		work();
	}
	return 0;
}
     