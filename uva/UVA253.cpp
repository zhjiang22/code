#include<bits/stdc++.h>
using namespace std;

const int MAXN=10;
char a[MAXN],b[MAXN];
char c[MAXN];
char f;
int top,botton;

void init(){
	a[0]=f;
	for(int i=1;i<6;i++)	cin>>a[i];	a[6]='\0';
	for(int i=0;i<6;i++)	cin>>b[i];	b[6]='\0';
}

bool used[MAXN];

bool dfs(int cur){
	if(cur==5){
		c[6]='\0';
		puts(c);
		if(strcmp(c,b)==0)
			return 1;
	}
	for(int i=0;i<6;i++)
		if(!used[i]){
			c[cur]=a[i];	used[i]=1;
			if(dfs(cur+1))
				return 1;
			used[i]=0;
		}
	return 0;
}

bool check(int top,int bot){
	memset(used,0,sizeof(used));
	c[0]=a[top];	c[5]=a[bot];
	used[top]=1;	used[bot]=1;
	if(dfs(1))	return 1;
	return 0;
}

void work(){
	if(check(0,5)||check(2,3)||check(1,4)){
		printf("TRUE\n");	
		return;
	}
	printf("FALSE\n");
}

int main(){
	while(cin>>f)
	{
		init();
		work();
	}
	return 0;
}
     