#include<bits/stdc++.h>
using namespace std;

const int MAXN=1<<8;
const int MAXM=1e5;
char Map[100][MAXM];
char b[MAXM];
int cnt;
int n;

void init(){
	memset(Map,0,sizeof(Map));
	int n=strlen(b);	int maxlen=log2(n)+1;
	int cnt=0;
	for(int i=1;i<=maxlen;i++)
		for(int j=0;j<(1<<i)-1;j++)
			if(cnt<n)
				Map[i][j]=b[cnt++];
			else	return;
}

void work(){
	int c1,c2,c3;
	char c;
	while(scanf("%1d%1d%1d",&c1,&c2,&c3)==3){
		int len=c1*4+c2*2+c3;
		if(len==0)	break;
		while(true){
			int cur=0;
			for(int i=1;i<=len;i++){
				do 
					scanf("%c",&c);
				while(!isdigit(c));
				cur=cur*2+(c-'0');
			}
			if(cur>=((1<<len)-1))	break;
			else	if(Map[len][cur])	
				putchar(Map[len][cur]);
		}
	}
	printf("\n");
}

int main(){
	while(gets(b)!=NULL){
		if(!b[0])	continue;
		init();
		work();
	}
	return 0;
}