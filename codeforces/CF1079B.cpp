#include<bits/stdc++.h>
using namespace std;

const int MAXN=30;
string a;
int l;
int n,m;

void init(){
	cin>>a;
	l=a.length();
}

void work(){
	if(l<=20){
		cout<<1<<" "<<l<<endl;
		cout<<a<<endl;
		return;
	}
	n=l/20;
	if(n*20==l){
		cout<<n<<" "<<20<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=20;j++)
				putchar(a[(i-1)*20+j-1]);
			printf("\n");
		}
		return;
	}
	++n;	m=l/n;
	if(m*n==l){
		cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				putchar(a[(i-1)*m+j-1]);
			printf("\n");
		}
		return;
	}
	m++;
	cout<<n<<" "<<m<<endl;
	int k=m*n-l;
	int cur=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i<=k&&j==m)
				putchar('*');
			else
				putchar(a[cur++]);
		}
		printf("\n");
	}
}

int main(){
	init();
	work();
	return 0;
}
     