#include<bits/stdc++.h>
using namespace std;

const int MAXN=35;
double h[MAXN*MAXN];
int n,m,v;
int Cnt;

void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>h[(i-1)*m+j];
	sort(h+1,h+n*m+1);
	cin>>v;
}

void work(){
	double cur=v/100.0;	int can=1;
	cur+=h[1];
	for(int i=2;i<=n*m;i++){
		cur+=h[i];	
		if(cur/i<=h[i]){//刚好到达不算漫过
			cur-=h[i];
			break;
		}
		can=i;
	}
	printf("Region %d\n",++Cnt);
	printf("Water level is %.2lf meters.\n",(double)cur/can);
	printf("%.2lf percent of the region is under water.\n",(double)can/(n*m)*100);
	printf("\n");
}

int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		work();
	}
	return 0;
}
     