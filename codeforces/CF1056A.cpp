#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
int a[MAXN];
int n,r;

void init(){
	cin>>n;
}

void work(){
	int x;
	for(int i=1;i<=n;i++){
		cin>>r;
		for(int j=1;j<=r;j++){
			cin>>x;
			a[x]++;
		}
	}
	for(int i=1;i<=100;i++)
		if(a[i]==n)
			cout<<i<<" ";
	cout<<endl;
}

int main(){
	init();
	work();
	return 0;
}
     