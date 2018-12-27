#include<bits/stdc++.h>
using namespace std;

const int MAXN=12;
const int n=10,m=9;
struct chess{
	int idx;
	int x,y;
}a[MAXN];
int g[MAXN][MAXN];
int k,x,y;

int Horse[8][2]={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int Horse_leg[8][2]={{1,0},{-1,0},{1,0},{-1,0},{0,1},{0,1},{0,-1},{0,-1}};

void init(){
	char ch;
	for(int i=1;i<=k;i++){
		cin>>ch>>a[i].x>>a[i].y;
		if(ch=='G')	a[i].idx=1;//General
		if(ch=='R')	a[i].idx=2;//Chariot
		if(ch=='H')	a[i].idx=3;//Horse
		if(ch=='C') a[i].idx=4;//Cannon
	}
}

bool check_General(int x,int y){
	return x>=1&&x<=3&&y>=4&&y<=6;
}

bool goit(int idx,int x,int y){
	
}

bool check(int x,int y){
	if(!check_General(x,y))
		return 0;
	for(int i=1;i<=k;i++)
		if(goit(a[i].idx,x,y))
			return 0;
	return 1;
}

void work(){
	if(check(x+1,y)||check(x,y+1)||check(x-1,y)||check(x,y-1))
		printf("NO\n");
	else
		printf("YES\n");
}

int main()
{
	while(scanf("%d%d%d",&k,&x,&y)==3&&k&&x&&y){
		init();
		work();
	}
	return 0;
}
     