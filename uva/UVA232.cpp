#include<bits/stdc++.h>
using namespace std;

const int MAXN=15;
struct Point{
	int x,y;
};
std::vector<Point> across,down;
char a[MAXN][MAXN];
int idx[MAXN][MAXN];
int first;
int Case;
int n,m;

void init(){
	across.clear();	down.clear();
	memset(idx,0,sizeof(idx));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
}

bool valid(const int& x,const int& y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}

void work(){
	if(first)  printf("\n");
	else  first=1;  
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			bool ok=0;
			if(a[i][j]=='*')	continue;
			if(!valid(i,j-1)||a[i][j-1]=='*')	across.push_back((Point){i,j}),ok=1;
			if(!valid(i-1,j)||a[i-1][j]=='*')	down.push_back((Point){i,j}),ok=1;
			if(ok)	idx[i][j]=++cnt;
		}
	printf("puzzle #%d:\n",++Case);
	printf("Across\n");
	int l1=across.size();	int l2=down.size();
	for(int i=0;i<l1;i++){
		int x=across[i].x;	int y=across[i].y;
		printf("%3d.",idx[x][y]);
		while(a[x][y]!='*'&&y<=m)	putchar(a[x][y++]);
		putchar('\n');
	}
	printf("Down\n");
	for(int i=0;i<l2;i++){
		int x=down[i].x;	int y=down[i].y;
		printf("%3d.",idx[x][y]);
		while(a[x][y]!='*'&&x<=n)	putchar(a[x++][y]);
		putchar('\n');
	}
}

int main(){
	while(scanf("%d%d",&n,&m)==2&&n&&m){
		init();
		work();
	}
	return 0;
}
     