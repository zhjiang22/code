#include<bits/stdc++.h>
using namespace std;

const int MAXN=1005;
vector<string> v[MAXN];
int maxlen[MAXN];
char a[MAXN];
int line;
int n;

void init(){
	n=strlen(a);
}

void read(){
	int cur=0;
	int cnt=0;	line++;
	while(cur<n){
		while(a[cur]==' '&&cur<n)	cur++;
		if(cur==n)	break;
		int kk=0;
		string b;
		while(a[cur]!=' '&&cur<n){
			kk++;	b+=a[cur++];
		}
		cnt++;	v[line].push_back(b);
		maxlen[cnt]=max(maxlen[cnt],kk);
	}
}

void work(){
	for(int i=1;i<=line;i++){
		int l=v[i].size();
		for(int k=0;k<l;k++){
			cout<<v[i][k];
			if(k==l-1)	break;
			int t=maxlen[k+1]-v[i][k].length();
			while(t--)	putchar(' ');
			putchar(' ');
		}
		printf("\n");
	}
}

int main(){
	while(gets(a)!=NULL){
		if(strlen(a)==0)	continue;
		init();
		read();
	}
	work();
	return 0;
}
     