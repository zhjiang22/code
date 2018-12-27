#include<bits/stdc++.h>
using namespace std;

const int MAXN=10;
const int n=8;
int g[MAXN][MAXN];
int tot[2];
int cur;
int t;

void init(){
	memset(g,0,sizeof(g));
	memset(tot,0,sizeof(tot));
	char ch;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>ch;
			if(ch=='-')	g[i][j]=-1;
			if(ch=='W')	g[i][j]=0,tot[0]++;
			if(ch=='B')	g[i][j]=1,tot[1]++;
		}
	cin>>ch;	if(ch=='W')	 cur=0;	 else	cur=1;
}

void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(g[i][j]==-1)	putchar('-');
			else	if(g[i][j])	putchar('B');
			else	putchar('W');
		printf("\n");
	}
	if(t!=0)
		printf("\n");
}

bool valid(const int& x,const int& y){
	return x<=n&&x>=1&&y<=n&&y>=1;
}

int dz[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

bool check(int x,int y){
	if(g[x][y]!=-1)	return 0;
	for(int i=0;i<8;i++){
		bool ok=1;
		for(int k=1;k<=n;k++){
			int nx=x+dz[i][0]*k;	int ny=y+dz[i][1]*k;
			if(!valid(nx,ny))	{ok=0; 	break;}
			if(g[nx][ny]==-1)	{ok=0;	break;}
			if(g[nx][ny]==cur&&k==1)	{ok=0;	break;}
			if(g[nx][ny]==cur)	{ok=1;	break;}
		}
		if(ok)	return 1;
	}
	return 0;
}

void query(){
	int first=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(check(i,j)){
				if(first)
					printf("(%d,%d)",i,j),first=0;
				else
					printf(" (%d,%d)",i,j);

			}
				
	if(first)	printf("No legal move.");
	printf("\n");	
}

void doit(int x,int y)
{
	for(int i=0;i<8;i++){
		int ok=1;	int maxk=0;
		for(int k=1;k<=n;k++){
			int nx=x+dz[i][0]*k;	int ny=y+dz[i][1]*k;
			if(!valid(nx,ny))	{ok=0; break;}
			if(g[nx][ny]==-1)	{ok=0; break;}
			if(g[nx][ny]==cur&&k==1)	{ok=0;	break;}
			if(g[nx][ny]==cur)	{ok=1;	maxk=k-1;	break;}
		}
		if(!ok)	continue;
		for(int k=1;k<=maxk;k++){
			int nx=x+dz[i][0]*k;	int ny=y+dz[i][1]*k;
			tot[!cur]--;	tot[cur]++;    g[nx][ny]=cur;
		}
	}
}

void work(){
	char ch;
	while(cin>>ch)
	{
		if(ch=='Q'){
			print();
			return;
		}
		if(ch=='L'){
			query();
		}
		if(ch=='M'){
			int x,y;	scanf("%01d %01d",&x,&y);
			if(check(x,y))	g[x][y]=cur;
			else	cur=!cur,g[x][y]=cur;
			doit(x,y);	tot[cur]++;	 cur=!cur;	
			printf("Black -%3d White -%3d\n",tot[1],tot[0]);
		}
	}
}

int main(){
	scanf("%d",&t);
	while(t--)
	{
		init();
		work();
	}
	return 0;
}