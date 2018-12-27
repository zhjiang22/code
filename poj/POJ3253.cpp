#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int n;

void init(){
	int x;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		q.push(x);
	}
}

void work(){
	long long ans=0;
	while(q.size()!=1)
	{
		int u=q.top();	q.pop();
		int v=q.top();	q.pop();
		q.push(u+v);	ans+=u+v;
	}
	printf("%lld\n",ans);
}

int main(){
	init();
	work();
	return 0;
}
     