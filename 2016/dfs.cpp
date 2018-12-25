#include<iostream>
#include<algorithm>
using namespace std;

int k,tot=0;

void dfs(int a,int x,int n) {
	if(x>k) return;
	if(x==k && n>=a) {tot++; return;};
	for(int i=max(1,a);i<=n/(k-x+1);i++) dfs(i,x+1,n-i);
}

int main() {
	int n;
	cin>>n>>k;
	dfs(0,1,n);
	cout<<tot;
}